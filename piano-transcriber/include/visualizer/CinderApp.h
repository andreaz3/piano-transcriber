#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "visualizer/VisualPiano.h"
#include <vector>
#include "cinder/audio/Voice.h"
#include "cinder/audio/Source.h"

using namespace std;
using ci::app::KeyEvent;
using cinder::audio::SourceFileRef;
using cinder::audio::VoiceRef;

/**
 * An app for visualizing the chords in a song being played.
 */
class CinderApp : public ci::app::App  {

public:
    /**
     * Constructor for CinderApp
     */
    CinderApp();

    /**
     * Draws the visuals
     */
    void draw() override;

    /**
     * Updates every frame
     */
    void update() override;

    /**
     * Inserts all the wav files into a map
     */
    void setup() override;

    /**
     * Method used to distinguish between different keys and their functions
     **/
    void keyDown(KeyEvent event) override;

private:

    /**
     * Size of the pop-up window
     */
    const size_t kWindowSizeX = 500;
    const size_t kWindowSizeY = 500;

    VisualPiano pianoSong;
    float previous_frame_rate = 0.5f;
    VoiceRef audio;

    /**
     * A map where the key is the name of the chord
     * and the value is the source of the chord sound.
     */
    map<string, SourceFileRef> wav_map;
};

