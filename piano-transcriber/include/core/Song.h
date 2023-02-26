#pragma once
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class Song {
private:
public:

    /**
     * Constructor for Song.
     */
    Song();

    /**
     * A vector of all the chords in the song
     */
    vector<string> chords_in_song;

    /**
     * A map where the keys are chord names
     * and values are the three notes that make up a chord.
     */
    map<string,vector<string>> chords_map;

    /**
     * Another operator overload that extracts all the chords in a song.
     * @param input the path to a song with lyrics and chords
     * @param song, the Song we are assigning it to
     * @return input
     */
    friend istream &operator>>(istream &input, Song &song);

};

