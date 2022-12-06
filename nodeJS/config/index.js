const Cloud = require('@google-cloud/storage')
const path = require('path')

const serviceKey = path.join(__dirname, '../speech-to-text-key.json')

const { Storage } = Cloud

const storage = new Storage({
  keyFilename: serviceKey,
  projectId: 'speech-to-text-370213',
})

module.exports = storage
