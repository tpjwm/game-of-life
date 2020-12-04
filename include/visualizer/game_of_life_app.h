#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "core/game_engine.h"

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

            void update() override;

            void mouseDown(ci::app::MouseEvent event) override;

            const double kWindowSize = 875;
            const double kMargin = 100;

        private:
            BoardUI board_;
            GameEngine gameEngine_;
            /**
             * if true, player is allowed to draw and string is displayed
             * if false, simulation runs and player is not allowed to shade
             */
            bool draw_phase_;
        };

    }  //namespace visualizer

}  //namespace gameoflife
