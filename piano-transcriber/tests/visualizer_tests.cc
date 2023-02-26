#include <catch2/catch.hpp>
#include <fstream>
#include <visualizer/VisualPiano.h>

using ci::RectT;

TEST_CASE("Testing Visual Piano") {

    VisualPiano visualPiano;

    SECTION("AdvanceOneFrame & GetCurrentChord") {
        visualPiano.AdvanceOneFrame();
        REQUIRE(visualPiano.GetCurrentChord() == "E");
        visualPiano.AdvanceOneFrame();
        REQUIRE(visualPiano.GetCurrentChord() == "B");
    }

    //Everything else in VisualPiano and CinderApp either draws an image
    //or plays a sound which isn't tested through catch2

}
