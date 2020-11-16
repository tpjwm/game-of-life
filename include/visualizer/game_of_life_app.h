#pragma once

#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "board.h"

namespace gameoflife {

    namespace visualizer {

/**
 * Allows a user to manipulate particles that interact following the laws of ideal gas.
 */
        class GameOfLifeApp : public ci::app::App {
        public:
            GameOfLifeApp();

            void draw() override;

            void update() override;

            void mouseDown(ci::app::MouseEvent event) override;

            const double kWindowSize = 875;
            const double kMargin = 100;

        private:
            Board board_;
        };

    }  // namespace visualizer

}  // namespace gameoflife
