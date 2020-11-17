#include <visualizer/game_of_life_app.h>

namespace gameoflife {

    namespace visualizer {

        GameOfLifeApp::GameOfLifeApp() : board_(glm::vec2(kMargin, kMargin), kWindowSize - 2 * kMargin),
                                         gameEngine_(board_.GetCells()) {
            ci::app::setWindowSize((int) kWindowSize, (int) kWindowSize);
            draw_phase_ = true;
        }

        void GameOfLifeApp::draw() {
            ci::Color8u background_color(0, 0, 0); //black
            ci::gl::clear(background_color);

            board_.Draw();

            //Draw string if simulation hasn't started
            if (draw_phase_) {
                ci::gl::drawStringCentered("Click to shade cells, press Start to begin",
                                           glm::vec2(kWindowSize / 2, kMargin / 2), ci::Color(255, 255, 255), //white
                                           ci::Font("Arial", 36.0f));
            }

            update();
        }

        void GameOfLifeApp::mouseDown(ci::app::MouseEvent event) {
            if (draw_phase_) {
                board_.ShadeCell(event.getPos());
            }
        }

        void GameOfLifeApp::update() {
            ///if !draw_phase_, call gameEngine to start manipulating cells
        }

    }  //namespace visualizer

}  //namespace gameoflife
