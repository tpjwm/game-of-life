#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "visualizer/board.h"

namespace gameoflife {

    namespace visualizer {

/**
 * Allows a user to manipulate particles that interact following the laws of ideal gas.
 */
        class GameOfLifeApp : public ci::app::App {
        public:

            GameOfLifeApp();

            void draw() override;

            void DrawStartButton() const;

            void DrawResetButton() const;

            void DrawSpeedButtons() const;

            void update() override;

            void mouseDown(ci::app::MouseEvent event) override;

            const double kWindowSize = 875;
            const double kMargin = 100;
            const size_t kNumCells = 40;

        private:

            BoardUI board_;

            /**
             * if true, player is allowed to draw and string is displayed
             * if false, simulation runs and player is not allowed to shade
             */
            bool draw_phase_;

            /**
             * The following constants are used for handling the speed buttons
             */
            const float kSpeedBoxesWindowSize = 25;

            //SPEED UP
            const glm::vec2 kTopLeftCornerSpeedUpBox = glm::vec2(kMargin * 4.3, kWindowSize - kMargin * 0.7);
            const glm::vec2 kBottomRightCornerSpeedUpBox = glm::vec2(kTopLeftCornerSpeedUpBox +
                                                                     glm::vec2(kSpeedBoxesWindowSize * 2,
                                                                               kSpeedBoxesWindowSize));
            const glm::vec2 kStringUpPos = glm::vec2((kTopLeftCornerSpeedUpBox.x + kBottomRightCornerSpeedUpBox.x) / 2,
                                                     (kTopLeftCornerSpeedUpBox.y + kBottomRightCornerSpeedUpBox.y) / 2 -
                                                     7.5);

            //TITLE
            const glm::vec2 kStringSpeedPos = glm::vec2(kTopLeftCornerSpeedUpBox.x + kSpeedBoxesWindowSize / 1.1,
                                                        kTopLeftCornerSpeedUpBox.y - kSpeedBoxesWindowSize * 1.1);

            //SPEED DOWN
            const glm::vec2 kTopLeftCornerSpeedDownBox = glm::vec2(
                    kTopLeftCornerSpeedUpBox.x, kTopLeftCornerSpeedUpBox.y + kSpeedBoxesWindowSize * 1.5);
            const glm::vec2 kBottomRightCornerSpeedDownBox = glm::vec2(kTopLeftCornerSpeedDownBox +
                                                                       glm::vec2(kSpeedBoxesWindowSize * 2,
                                                                                 kSpeedBoxesWindowSize));
            const glm::vec2 kStringDownPos = glm::vec2(
                    (kTopLeftCornerSpeedDownBox.x + kBottomRightCornerSpeedDownBox.x) / 2,
                    (kTopLeftCornerSpeedDownBox.y + kBottomRightCornerSpeedDownBox.y) / 2 - 7.5);

            /**
             * The following constants are used for handling the reset button
             */
            const float kResetBoxWindowSize = 50;
            const glm::vec2 kTopLeftCornerReset = glm::vec2(kMargin * 2, kWindowSize - kMargin * 0.85);
            const glm::vec2 kBottomRightCornerReset = glm::vec2(kTopLeftCornerReset +
                                                                glm::vec2(kResetBoxWindowSize * 2,
                                                                          kResetBoxWindowSize));
            const glm::vec2 kStringResetPos = glm::vec2(kTopLeftCornerReset.x + kResetBoxWindowSize,
                                                        kTopLeftCornerReset.y + kResetBoxWindowSize / 3.5);

            /**
             * The following constants are used for handling the start button
             */
            const float kStartBoxWindowSize = 50;
            const glm::vec2 kTopLeftCornerStart = glm::vec2(kMargin * 6, kWindowSize - kMargin * 0.85);
            const glm::vec2 kBottomRightCornerStart = glm::vec2(kTopLeftCornerStart +
                                                                glm::vec2(kStartBoxWindowSize * 2,
                                                                          kStartBoxWindowSize));
            const glm::vec2 kStringStartPos = glm::vec2(kTopLeftCornerStart.x + kStartBoxWindowSize,
                                                        kTopLeftCornerStart.y + kStartBoxWindowSize / 3.5);
        };

    }  //namespace visualizer

}  //namespace gameoflife
