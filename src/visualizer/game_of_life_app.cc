#include <visualizer/game_of_life_app.h>

namespace gameoflife {

    namespace visualizer {

        GameOfLifeApp::GameOfLifeApp(){
            ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
        }

        void GameOfLifeApp::draw() {
            ci::Color8u background_color(150, 150, 150); //grey
            ci::gl::clear(background_color);

            ci::gl::drawStringCentered("Click to add particle",
                                       glm::vec2(kWindowSize / 2, kMargin / 2), ci::Color(0, 0, 0),
                                       ci::Font("Arial", 36.0f));

            update();
        }

        void GameOfLifeApp::mouseDown(ci::app::MouseEvent  /*event*/) {

        }

        void GameOfLifeApp::update() {

        }

    }  // namespace visualizer

}  // namespace gameoflife
