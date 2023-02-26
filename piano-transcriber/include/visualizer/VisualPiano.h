#pragma once

#include <core/Song.h>
#include <vector>
#include "cinder/Area.h"

using namespace std;
using cinder::RectT;
using std::vector;

class VisualPiano {
private:
    /**
     * A map where the keys are the chord names
     * and the values are the chord's notes.
     */
    map<string,vector<string>> chords_map;

    /**
     * A counter used to iterate through
     * all the chords in a song.
     */
    size_t current_chord_counter = 0;

    /**
    * The chords in a song.
    */
    vector<string> chords_in_song;

    /**
     * The current chord being played.
     */
    string current_chord;

    /**
     * The number of white keys and black keys on the visual piano.
     */
    const size_t num_white_keys = 7;
    const size_t num_black_keys = 5;

    /**
     * All of the keys displayed on the piano
     * separated by sharp, flat, or neither.
     */
    vector<string> white_notes{"C","D","E","F","G","A","B"};
    vector<string> black_sharp_notes{"C#","D#","F#","G#","A#"};
    vector<string> black_flat_notes{"Db","Eb","Gb","Ab","Bb"};

    /**
     * * A helper method that sets up the visual piano's white keys
     * * @param white_keys
     * */
    void SetUpWhiteKeys(vector<RectT<float>> &white_keys) const;

    /**
     * A helper method that sets up the visual piano's black keys
     * @param back_keys
     */
    void SetUpBlackKeys(vector<RectT<float>> &back_keys) const;

    /**
     * A helper method called in Display
     * hat changes the keys being played to red.
     * @param white_keys
     * @param black_keys
     */
    void PlayVisualPiano(vector<RectT<float>> &white_keys, vector<RectT<float>> &black_keys) const;

    static void RedrawUnusedBlackKeys(vector<RectT<float>> &black_keys, vector<size_t> &red_black_keys_index);

public:
    /**
     * Constructor for VisualPiano.
     * which reads in a song and retrieves its chord composition.
     */
    VisualPiano();

    /**
     * Visually displays the visual piano and the current chord.
     */
    void Display() const;

    /**
     * Updates the current chord.
     */
    void AdvanceOneFrame();

    /**
     * Getter for the current chord
     * @return A string of the name of the current chord
     */
    string GetCurrentChord();
};

