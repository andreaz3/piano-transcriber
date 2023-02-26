#include "visualizer/CinderApp.h"
#include "cinder/audio/Voice.h"
#include "cinder/audio/Source.h"

using ci::app::setWindowSize;
using ci::Color;
using ci::gl::clear;
using ci::app::KeyEvent;
using ci::app::setFrameRate;
using cinder::audio::SourceFileRef;
using cinder::audio::load;
using cinder::app::loadAsset;
using cinder::audio::Voice;


CinderApp::CinderApp() {
    setWindowSize(kWindowSizeX, kWindowSizeY);
    ci::app::setFrameRate(.5f);
}

void CinderApp::draw() {
    Color background_color("lightskyblue");
    clear(background_color);

    pianoSong.Display();
}

void CinderApp::update() {
    pianoSong.AdvanceOneFrame();

    audio = Voice::create( wav_map[pianoSong.GetCurrentChord()] );
    if (audio->isPlaying()) {
        audio->stop();
    }
    audio->start();

}

void CinderApp::keyDown(KeyEvent event) {
    switch (event.getCode()) {
        case KeyEvent::KEY_SPACE:
            if (getFrameRate() != .0f) {
                setFrameRate(.0f);
            } else {
                setFrameRate(previous_frame_rate);
            }
            break;
        case KeyEvent::KEY_RIGHT:
            setFrameRate(getFrameRate() + .03f);
            previous_frame_rate = getFrameRate();
            break;
        case KeyEvent::KEY_LEFT:
            setFrameRate(getFrameRate() - .03f);
            previous_frame_rate = getFrameRate();
            break;
    }
}

void CinderApp::setup() {

    //Can add more wav files to play more songs
    //wav files downloaded from https://freesound.org/

    SourceFileRef A_major_wav = load( loadAsset( "Amajor.wav"));
    wav_map.insert(pair<string, SourceFileRef>("A", A_major_wav));

    SourceFileRef A_minor_wav = load( loadAsset( "Aminor.wav"));
    wav_map.insert(pair<string, SourceFileRef>("Am", A_minor_wav));

    SourceFileRef B_major_wav = load( loadAsset( "Bmajor.wav"));
    wav_map.insert(pair<string, cinder::audio::SourceFileRef>("B", B_major_wav));

    SourceFileRef C_major_wav = load( loadAsset( "Cmajor.wav"));
    wav_map.insert(pair<string, SourceFileRef>("C", C_major_wav));

    SourceFileRef C_sharp_minor_wav = load( loadAsset( "C#minor.wav"));
    wav_map.insert(pair<string, SourceFileRef>("C#m", C_sharp_minor_wav));

    SourceFileRef E_major_wav = load( loadAsset( "Emajor.wav"));
    wav_map.insert(pair<string, SourceFileRef>("E", E_major_wav));

    SourceFileRef E_minor_wav = load( loadAsset( "Eminor.wav"));
    wav_map.insert(pair<string, SourceFileRef>("Em", E_minor_wav));

    SourceFileRef F_sharp_major_wav = load( loadAsset( "F#major.wav"));
    wav_map.insert(pair<string, SourceFileRef>("F#", F_sharp_major_wav));

    SourceFileRef G_major_wav = load( loadAsset( "Gmajor.wav"));
    wav_map.insert(pair<string, SourceFileRef>("G", G_major_wav));

    SourceFileRef G_sharp_minor_wav = load( loadAsset( "G#minor.wav"));
    wav_map.insert(pair<string, SourceFileRef>("G#m", G_sharp_minor_wav));

}
