#include "visualizer/VisualPiano.h"
#include <map>

#pragma once

using namespace std;

class AllChords {
public:
    /**
     * A map where the keys are the chord names and
     * the values are the notes within the chord.
     */
    map<string,vector<string>> chords_map;

    /** operator overload of >>
     * Takes in an input and populates the chords_map in allChords.
     * @param input
     * @param allChords
     * @return input
     */
    friend istream &operator>>(istream &input, AllChords &allChords);
};
