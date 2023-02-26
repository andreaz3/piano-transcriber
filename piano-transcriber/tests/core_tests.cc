#include <catch2/catch.hpp>
#include <core/AllChords.h>
#include <fstream>
#include <core/Song.h>

TEST_CASE("Loading Chords") {
    AllChords allChords;
    std::ifstream chords_txt("/Users/andreazhou/Downloads/Cinder/my-projects/final-project-andreaz3/assets/chords-to-notes");
    std::istream& stream = chords_txt;

    stream >> allChords;
    SECTION("Regular Major Chord") {

        vector<string> chord_note = allChords.chords_map.at("C");

        REQUIRE(chord_note[0] == "C");
        REQUIRE(chord_note[1] == "E");
        REQUIRE(chord_note[2] == "G");
    }
    SECTION("Regular Minor Chord") {

        vector<string> chord_note = allChords.chords_map.at("Cm");

        REQUIRE(chord_note[0] == "C");
        REQUIRE(chord_note[1] == "Eb");
        REQUIRE(chord_note[2] == "G");
    }
    SECTION("# Major Chord") {

        vector<string> chord_note = allChords.chords_map.at("D#");

        REQUIRE(chord_note[0] == "Eb");
        REQUIRE(chord_note[1] == "G");
        REQUIRE(chord_note[2] == "Bb");
    }
    SECTION("b minor Chord") {

        vector<string> chord_note = allChords.chords_map.at("Bbm");

        REQUIRE(chord_note[0] == "Bb");
        REQUIRE(chord_note[1] == "Db");
        REQUIRE(chord_note[2] == "F");
    }
}

TEST_CASE("Operator Overload Songs") {
    SECTION("Song 1") {
        Song tequila_song;
        std::ifstream song_txt ("/Users/andreazhou/Downloads/Cinder/my-projects/final-project-andreaz3/assets/Dan + Shay - Tequila");
        std::istream& stream = song_txt;
        stream >> tequila_song;

        //The 4 repeated chords
        REQUIRE(tequila_song.chords_in_song[0] == "E");
        REQUIRE(tequila_song.chords_in_song[1] == "B");
        REQUIRE(tequila_song.chords_in_song[2] == "F#");
        REQUIRE(tequila_song.chords_in_song[3] == "G#m");
        //Making sure the chords are repeating correctly
        REQUIRE(tequila_song.chords_in_song[4] == "E");
    }
    SECTION("Song 2") {
        Song red_song;
        std::ifstream song_txt ("/Users/andreazhou/Downloads/Cinder/my-projects/final-project-andreaz3/assets/Taylor Swift - Red");
        std::istream& stream = song_txt;
        stream >> red_song;

        //The 3 repeated chords
        REQUIRE(red_song.chords_in_song[0] == "A");
        REQUIRE(red_song.chords_in_song[1] == "C#m");
        REQUIRE(red_song.chords_in_song[2] == "B");
        //Making sure the chords are repeating correctly
        REQUIRE(red_song.chords_in_song[3] == "A");
    }
}
