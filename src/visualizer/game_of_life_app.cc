#include <visualizer/game_of_life_app.h>

namespace gameoflife {

    namespace visualizer {

        GameOfLifeApp::GameOfLifeApp() : board_(glm::vec2(kMargin, kMargin), kWindowSize - 2 * kMargin),
                                         gameEngine_() {
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

            DrawStartButton();

            DrawResetButton();

            update();
        }

        void GameOfLifeApp::mouseDown(ci::app::MouseEvent event) {
            //shade cell logic
            if (draw_phase_) {
                board_.ShadeCell(event.getPos());
            }

            //reset button
            if (event.getPos().x > kMargin * 2 && event.getPos().y > kWindowSize - kMargin * 0.85 &&
            event.getPos().x < kMargin * 2 + 100 && event.getPos().y < kWindowSize - kMargin * 0.85 + 50){

                board_ = BoardUI(glm::vec2(kMargin, kMargin), kWindowSize - 2 * kMargin);
                draw_phase_ = true;
            }

            //start button
            if (event.getPos().x > kMargin * 6 && event.getPos().y > kWindowSize - kMargin * 0.85 &&
                event.getPos().x < kMargin * 6 + 100 && event.getPos().y < kWindowSize - kMargin * 0.85 + 50) {
                draw_phase_ = false;
            }
        }

        void GameOfLifeApp::update() {
            if(!draw_phase_){
                board_.SetCells(gameEngine_.UpdateCells(board_.GetCells()));
            }
        }

        void GameOfLifeApp::DrawStartButton() const {
            ci::gl::color(0.7f, 0.7f, 0.7f); //grey

            float window_size = 50;

            glm::vec2 top_left_corner(kMargin * 6, kWindowSize - kMargin * 0.85); //0.85 and 6 is arbitrary
            glm::vec2 bottom_right_corner = top_left_corner + glm::vec2(window_size * 2, window_size);

            ci::Rectf bounding_box(top_left_corner, bottom_right_corner);
            ci::gl::drawSolidRect(bounding_box);

            ci::gl::drawStringCentered("Start", glm::vec2(top_left_corner.x + window_size,
                                                          top_left_corner.y + window_size / 3.5), //3.5 is arbitrary for centering
                                       ci::Color(255, 255, 255), ci::Font("Arial", 24.0f));
        }

        void GameOfLifeApp::DrawResetButton() const {
            ci::gl::color(0.7f, 0.7f, 0.7f); //grey

            float window_size = 50;

            glm::vec2 top_left_corner(kMargin * 2, kWindowSize - kMargin * 0.85); //0.85 and 2 is arbitrary
            glm::vec2 bottom_right_corner = top_left_corner + glm::vec2(window_size * 2, window_size);

            ci::Rectf bounding_box(top_left_corner, bottom_right_corner);
            ci::gl::drawSolidRect(bounding_box);

            ci::gl::drawStringCentered("Reset", glm::vec2(top_left_corner.x + window_size,
                                                          top_left_corner.y + window_size / 3.5), //3.5 is arbitrary for centering
                                       ci::Color(255, 255, 255), ci::Font("Arial", 24.0f));
        }

    }  //namespace visualizer

}  //namespace gameoflife
