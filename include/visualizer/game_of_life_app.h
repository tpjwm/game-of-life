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
            const float kSpeedBoxesWindowSize = 20;
            const glm::vec2 kTopLeftCornerSpeedUpBox = glm::vec2(kMargin * 4.3, kWindowSize - kMargin * 0.65);
            const glm::vec2 kBottomRightCornerSpeedUpBox = glm::vec2(kTopLeftCornerSpeedUpBox +
                    glm::vec2(kSpeedBoxesWindowSize, kSpeedBoxesWindowSize));
            const glm::vec2 kStringSpeedPos = glm::vec2(kTopLeftCornerSpeedUpBox.x + kSpeedBoxesWindowSize / 3,
                                                        kTopLeftCornerSpeedUpBox.y - kSpeedBoxesWindowSize * 1.3);
            const glm::vec2 kTopLeftCornerSpeedDownBox = glm::vec2(
                    kTopLeftCornerSpeedUpBox.x,kTopLeftCornerSpeedUpBox.y + kSpeedBoxesWindowSize*1.5);
            const glm::vec2 kBottomRightCornerSpeedDownBox = glm::vec2(kTopLeftCornerSpeedDownBox +
                    glm::vec2(kSpeedBoxesWindowSize, kSpeedBoxesWindowSize));

        };

    }  //namespace visualizer

}  //namespace gameoflife
