#include <iostream>

#include <core/AllChords.h>
#include <core/Song.h>

using namespace std;

int main(int argc, char* argv[]) {

    AllChords allChords;
    std::ifstream chords_txt ("/Users/andreazhou/Downloads/Cinder/my-projects/final-project-andreaz3/assets/chords-to-notes");
    std::istream& stream = chords_txt;

    stream >> allChords;

/*

    string chord_name;
    cout << "Type a chord: ";
    cin >> chord_name;
    while ( allChords.chords_map.find(chord_name) == allChords.chords_map.end() ) {
        cout << "Type a chord that exists: ";
        cin >> chord_name;
    }
    vector<string> chord_note = allChords.chords_map.at(chord_name);
    for (size_t i = 0; i < 3; i++) {
        cout << chord_note[i] <<endl;
    }
*/

    //Tequila song
    Song tequila_song;
    std::ifstream song_txt1 ("/Users/andreazhou/Downloads/Cinder/my-projects/final-project-andreaz3/assets/Dan + Shay - Tequila");
    std::istream& stream1 = song_txt1;
    stream1 >> tequila_song;

    for (auto & i : tequila_song.chords_in_song) {
        cout << i << endl;
    }

    //Coaster song
    Song coaster_song;
    std::ifstream song_txt2 ("/Users/andreazhou/Downloads/Cinder/my-projects/final-project-andreaz3/assets/Khalid - Coaster");
    std::istream& stream2 = song_txt2;
    stream2 >> coaster_song;

    //Red song
    Song red_song;
    std::ifstream song_txt3 ("/Users/andreazhou/Downloads/Cinder/my-projects/final-project-andreaz3/assets/Taylor Swift - Red");
    std::istream& stream3 = song_txt3;
    stream3 >> red_song;

  return 0;
}
