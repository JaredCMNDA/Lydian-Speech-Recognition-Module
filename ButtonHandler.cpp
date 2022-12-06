//
// Created by jared on 2022-11-29.
//
#include "link.h"

using namespace std;

void StartButton() {

    sf::SoundBufferRecorder recorder;
    sf::SoundBuffer buffer;
    sf::Sound sound;

        recorder.start();
        cout << "Recording" << endl;
        sf::sleep(sf::seconds(5));
        recorder.stop();
        cout << "Stopped Recording" << endl;
        buffer = recorder.getBuffer();

        cout << buffer.getSampleRate() << endl;
        cout << buffer.getSampleCount() << endl;
        buffer.saveToFile("../nodeJS/uploads/recording.wav");


}