#include "core/Song.h"
#include <fstream>
#include <vector>
#include <core/AllChords.h>

Song::Song(){
    AllChords allChords;
    std::ifstream chords_txt("/Users/andreazhou/Downloads/Cinder/my-projects/final-project-andreaz3/assets/chords-to-notes");
    std::istream& stream = chords_txt;
    stream >> allChords;
    this->chords_map = allChords.chords_map;
}

istream &operator>>(istream &input, Song &song) {

    string line;
    size_t line_counter = 0;

    while(getline(input,line)) {
        if (line.empty() || line.at(0) == '[') {
            continue;
        } else {
            if (line_counter % 2 == 0) {
                //only reads in every other line

                string chord;
                size_t character_tracker = 0;
                size_t max_note_letter = 3;

                for (char character : line) {
                    //find the uppercase character
                    if (isupper(character)) {
                        chord.push_back(character);
                        size_t temp_char_tracker = 0;
                        //reads the next couple character
                        for (size_t i = 0; i < max_note_letter; i++) {
                            //If last chord is one note, it won't have 3 more characters in the line.
                            if (character_tracker + temp_char_tracker != line.size() -1 &&
                            line.at(character_tracker + i + 1) != ' ') {
                                chord.push_back(line.at(character_tracker + 1 + i));
                                temp_char_tracker++;
                            } else {
                                break;
                            }
                        }
                        song.chords_in_song.push_back(chord);
                        chord = "";
                    }
                    character_tracker++;
                }
            }
            line_counter++;
        }
    }

    return input;
}