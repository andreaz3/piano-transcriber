#include <core/Song.h>
#include "visualizer/VisualPiano.h"
#include <string>
#include "cinder/gl/gl.h"

using namespace std;
using std::string;
using glm::vec2;
using ci::gl::color;
using ci::Color;
using ci::gl::drawSolidRect;
using ci::gl::drawStrokedRect;
using ci::gl::drawString;
using ci::Rectf;
using cinder::Font;
using cinder::RectT;

VisualPiano::VisualPiano() {

    Song song;
    //All you need to do to switch songs is change this path
    ifstream song_txt("/Users/andreazhou/Downloads/Cinder/my-projects/final-project-andreaz3/assets/Dan + Shay - Tequila");
    istream& stream1 = song_txt;
    stream1 >> song;

    this->chords_in_song = song.chords_in_song;
    this->chords_map = song.chords_map;

}

void VisualPiano::Display() const {

    vector<RectT<float>> white_keys;
    vector<RectT<float>> black_keys;

    //Displaying the piano
    SetUpWhiteKeys(white_keys);
    SetUpBlackKeys(black_keys);

    //Playing the piano
    PlayVisualPiano(white_keys, black_keys);

    //Labeling the Chord
    vec2 chord_label_placement(200, 100);
    drawString("Chord: " + current_chord, chord_label_placement,
               Color("black"),
               Font("Arial", 25));
}

void VisualPiano::AdvanceOneFrame() {
    if (current_chord_counter <= chords_in_song.size() - 1) {
        current_chord = chords_in_song.at(current_chord_counter);
        current_chord_counter++;
    }
}

void VisualPiano::SetUpWhiteKeys(vector<RectT<float>> &white_keys) const {

    //the bounds of the initial white key
    size_t lower_x_white = 100;
    size_t lower_y_white = 200;
    size_t upper_x_white = 150;
    size_t upper_y_white = 400;

    for (size_t i = 0; i < num_white_keys; i++) {
        //drawing each white key
        color(Color("white"));
        Rectf key = Rectf(vec2(lower_x_white, lower_y_white),
                          vec2(upper_x_white, upper_y_white));
        white_keys.push_back(key);
        drawSolidRect(key);

        //outlining the white key
        color(Color("black"));
        drawStrokedRect(key);

        //moving onto the next white key
        lower_x_white += 50;
        upper_x_white += 50;
    }

}

void VisualPiano::SetUpBlackKeys(vector<RectT<float>> &black_keys) const {

    //the bounds of the initial black key
    size_t lower_x_black = 135;
    size_t lower_y_black = 200;
    size_t upper_x_black = 160;
    size_t upper_y_black = 333;
    size_t index_skip_black_note = 1;

    for (size_t i = 0; i < num_black_keys; i++) {
        //drawing each black key
        color(Color("black"));
        Rectf key = Rectf(vec2(lower_x_black, lower_y_black),
                          vec2(upper_x_black, upper_y_black));
        black_keys.push_back(key);
        drawSolidRect(key);

        //moving onto the next black key, but skipping one
        if (i != index_skip_black_note) {
            lower_x_black += 50;
            upper_x_black += 50;
        } else {
            lower_x_black += 100;
            upper_x_black += 100;
        }
    }
}

void VisualPiano::PlayVisualPiano(vector<RectT<float>> &white_keys,
                                  vector<RectT<float>> &black_keys) const {

    vector<string> notes_in_current_chord = chords_map.at(current_chord);

    //A vector for the black keys being used
    vector<size_t> red_black_keys_index;

    char sharp = '#';
    char flat = 'b';

    for (string &note : notes_in_current_chord) {

        size_t index_of_note;
        color(Color("red"));

        if (note.find(sharp) != string::npos) {
            //Finding the key if the current note is a sharp note
            auto it = find(black_sharp_notes.begin(),
                           black_sharp_notes.end(), note);
            index_of_note = distance(black_sharp_notes.begin(), it);
            drawSolidRect(black_keys.at(index_of_note));
            red_black_keys_index.push_back(index_of_note);
        } else if (note.find(flat) != string::npos) {
            //Finding the key if the current note is a flat note
            auto it = find(black_flat_notes.begin(),
                           black_flat_notes.end(), note);
            index_of_note = distance(black_flat_notes.begin(), it);
            drawSolidRect(black_keys.at(index_of_note));
            red_black_keys_index.push_back(index_of_note);
        } else {
            //Finding the key if the current note is neither a sharp nor a flat note
            auto it = find(white_notes.begin(),
                           white_notes.end(), note);
            index_of_note = distance(white_notes.begin(), it);
            drawSolidRect(white_keys.at(index_of_note));
            RedrawUnusedBlackKeys(black_keys, red_black_keys_index);
        }
    }
}

void VisualPiano::RedrawUnusedBlackKeys(vector<RectT<float>> &black_keys,
                                        vector<size_t> &red_black_keys_index) {
    for (size_t i = 0; i < black_keys.size(); i++) {
        for (size_t index : red_black_keys_index) {
            if (i == index) {
                black_keys.erase(black_keys.begin() + index);
            }
        }
        color(Color("black"));
        drawSolidRect(black_keys.at(i));
    }
}


string VisualPiano::GetCurrentChord() {
    return current_chord;
}