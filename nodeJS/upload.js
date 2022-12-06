var axios = require('axios'); // Axios for HTTP requests
var FormData = require('form-data');
var fs = require('fs'); // File System
let audioURL = "string"; // Audio URL (Returns from "server" after uploading file to Google Cloud Storage)
let data; //init data (obj of FormData)
let fileName = "string"; // File name storage variable
const randomstring = require("randomstring");
const APIKey = "8c97b2ceb33a4189940693858d0d0c69" // AssemblyAI API Key

const CheckFiles = async () => {
    const check = setInterval( async () => {
        fs.readdir(__dirname + "/uploads/", (err, files) => {
            if (err) console.log(err);
            if(files.length > 0) {
                console.log("--------------------")
                console.log(". . . File found");
                console.log("Generating Random File ID");
                fileName = files[0].split(".")[0];
                fileName = fileName + "_" + randomstring.generate(5);
                fs.rename(__dirname + "/uploads/" + files[0], __dirname + "/uploads/" + fileName + ".wav", (err) => {
                    if (err) console.log(err);
                    console.log(`File Renamed to ${fileName}`);
                    data = new FormData();
                    data.append('file', fs.createReadStream(__dirname + `/uploads/${fileName}.wav`));
                    clearInterval(check);
                    PostFile();
                });
            } else if (files.length < 1){
                console.log(". . . No file found");
            }
        });
    }, 2500);
}
const PostFile = async () => {
    let config = {
        method: 'post',
        url: 'http://localhost:9001/uploads',
        headers: {
            ...data.getHeaders()
        },
        data : data
    };

    axios(config)
        .then(function (response) {
            console.log(JSON.stringify(response.data));
            console.log(`Success. Deleting file: ${fileName}.wav`);
            fs.unlinkSync(__dirname + `/uploads/${fileName}.wav`);
            audioURL = `https://storage.googleapis.com/lydian/${fileName}.wav`;
            getTranscript();
        })
        .catch(function (error) {
            console.log(error);
        });

}

// Setting up the AssemblyAI headers
const assembly = axios.create({
    baseURL: "https://api.assemblyai.com/v2",
    headers: {
        authorization: APIKey,
        "content-type": "application/json",
    },
})
const getTranscript = async () => {
    // Sends the audio file to AssemblyAI for transcription
    const response = await assembly.post("/transcript", {
        audio_url: audioURL,
    })
    // Interval for checking transcript completion
    let time = 0;
    const checkCompletionInterval = setInterval(async () => {
        const transcript = await assembly.get(`/transcript/${response.data.id}`)
        const transcriptStatus = transcript.data.status
        if (transcriptStatus !== "completed") {
            time++;
            console.log(`Transcript Status: ${transcriptStatus}` + " || " + time*2500/1000 + " seconds");
        } else if (transcriptStatus === "completed") {
            console.log("Transcription Status: completed!\n")
            let transcriptText = transcript.data.text
            console.log(transcriptText)
            console.log(time*2500/1000 + " seconds");
            console.log("--------------------")
            clearInterval(checkCompletionInterval)
            CheckFiles();
        }
    }, 2500)
}

CheckFiles();
