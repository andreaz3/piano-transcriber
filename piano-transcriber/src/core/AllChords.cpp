#include "core/AllChords.h"
#include <fstream>

istream &operator>>(istream &input, AllChords &allChords) {

    string line;
    while(getline(input,line)) {

        size_t colon_location;
        string chord_name;
        vector<string> chord_notes;

        //Finds the location of the colon
        if (line.at(1) == ':') {
            chord_name = line.at(0);
            colon_location = 1;
        } else if (line.at(2) == ':') {
            chord_name = line.substr(0,2);
            colon_location = 2;
        } else {
            chord_name = line.substr(0,3);
            colon_location = 3;
        }

        string note;
        for (char &character : line.substr(colon_location+1,line.size()-1)) {
            if (character != ',') {
                //pushed back the characters before the next comma
                note.push_back(character);
            } else {
                //pushes back the comprised current note
                chord_notes.push_back(note);
                note = "";
            }
        }
        allChords.chords_map.insert(pair<string,vector<string>>(chord_name,chord_notes));
        chord_notes.clear();
    }
    return input;
}
