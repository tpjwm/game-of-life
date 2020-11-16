#include <visualizer/game_of_life_app.h>

namespace gameoflife {

    namespace visualizer {

        GameOfLifeApp::GameOfLifeApp() : board_(glm::vec2(kMargin,kMargin), kWindowSize - 2*kMargin){
            ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
        }

        void GameOfLifeApp::draw() {
            ci::Color8u background_color(0, 0, 0); //black
            ci::gl::clear(background_color);
            board_.Draw();
            update();
        }

        void GameOfLifeApp::mouseDown(ci::app::MouseEvent  /*event*/) {

        }

        void GameOfLifeApp::update() {

        }

    }  // namespace visualizer

}  // namespace gameoflife
