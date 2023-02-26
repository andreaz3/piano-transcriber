#include "visualizer/CinderApp.h"

void prepareSettings(CinderApp::Settings* settings) {
  settings->setResizable(false);
}

// This line is a macro that expands into an "int main()" function.
CINDER_APP(CinderApp, ci::app::RendererGl, prepareSettings);
