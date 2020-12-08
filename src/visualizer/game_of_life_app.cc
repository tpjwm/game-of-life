#include <visualizer/game_of_life_app.h>

namespace gameoflife {

    namespace visualizer {

        GameOfLifeApp::GameOfLifeApp() : board_(glm::vec2(kMargin, kMargin), kWindowSize - 2 * kMargin, kNumCells) {
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

            DrawSpeedButtons();

            update();
        }

        void GameOfLifeApp::mouseDown(ci::app::MouseEvent event) {
            //shade cell logic
            if (draw_phase_) {
                board_.GetGameEngine().ShadeCell(event.getPos());
            }

            //reset button
            if (event.getPos().x > kTopLeftCornerReset.x && event.getPos().y > kTopLeftCornerReset.y &&
                event.getPos().x < kBottomRightCornerReset.x && event.getPos().y < kBottomRightCornerReset.y) {

                board_ = BoardUI(glm::vec2(kMargin, kMargin), kWindowSize - 2 * kMargin, kNumCells); //create new board
                draw_phase_ = true;
                board_.GetGameEngine().StopMusic(); //stop the ingame music
            }

            //start button
            if (event.getPos().x > kTopLeftCornerStart.x && event.getPos().y > kTopLeftCornerStart.y &&
                event.getPos().x < kBottomRightCornerStart.x && event.getPos().y < kBottomRightCornerStart.y) {
                draw_phase_ = false;
                board_.GetGameEngine().PlayMusic(); //play music
            }

            //speed up button
            if (event.getPos().x > kTopLeftCornerSpeedUpBox.x && event.getPos().y > kTopLeftCornerSpeedUpBox.y &&
            event.getPos().x < kBottomRightCornerSpeedUpBox.x && event.getPos().y < kBottomRightCornerSpeedUpBox.y){
                board_.GetGameEngine().SpeedUp();
            }
            if (event.getPos().x > kTopLeftCornerSpeedDownBox.x && event.getPos().y > kTopLeftCornerSpeedDownBox.y &&
            event.getPos().x < kBottomRightCornerSpeedDownBox.x && event.getPos().y < kBottomRightCornerSpeedDownBox.y){
                board_.GetGameEngine().SlowDown();
            }
        }

        void GameOfLifeApp::update() {
            if (!draw_phase_) {
                board_.GetGameEngine().UpdateCells();
            }
        }

        void GameOfLifeApp::DrawStartButton() const {
            ci::gl::color(0.7f, 0.7f, 0.7f); //grey

            //Start Box
            ci::Rectf bounding_box(kTopLeftCornerStart, kBottomRightCornerStart);
            ci::gl::drawSolidRect(bounding_box);

            //Start String
            ci::gl::drawStringCentered("Start", kStringStartPos,ci::Color(255, 255, 255),
                                       ci::Font("Arial", 24.0f));
        }

        void GameOfLifeApp::DrawResetButton() const {
            ci::gl::color(0.7f, 0.7f, 0.7f); //grey

            //Reset Box
            ci::Rectf bounding_box(kTopLeftCornerReset, kBottomRightCornerReset);
            ci::gl::drawSolidRect(bounding_box);

            //Reset String
            ci::gl::drawStringCentered("Reset", kStringResetPos,ci::Color(255, 255, 255),
                                       ci::Font("Arial", 24.0f));
        }

        void GameOfLifeApp::DrawSpeedButtons() const{
            ci::gl::color(0.7f, 0.7f, 0.7f); //grey

            //Speed up button

            ci::Rectf bounding_box1(kTopLeftCornerSpeedUpBox, kBottomRightCornerSpeedUpBox);
            ci::gl::drawSolidRect(bounding_box1);

            //String "Speed"
            ci::gl::drawStringCentered("Speed", glm::vec2(kStringSpeedPos),
                                       ci::Color(255, 255, 255), ci::Font("Arial", 24.0f));

            //Speed down button
            ci::Rectf bounding_box2(kTopLeftCornerSpeedDownBox, kBottomRightCornerSpeedDownBox);
            ci::gl::drawSolidRect(bounding_box2);
        }

    }  //namespace visualizer

}  //namespace gameoflife
