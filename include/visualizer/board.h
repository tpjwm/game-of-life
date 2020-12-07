//
// Created by dimit on 11/14/2020.
//
#pragma once
#ifndef GAME_OF_LIFE_BOARD_H
#define GAME_OF_LIFE_BOARD_H

#include "core/game_engine.h"

namespace gameoflife {
    namespace visualizer {
        class BoardUI {
        public:
            /**
             * Constructor for BoardUI
             * Takes in top left corner and window size, creates square window
             *
             * @param top_left_corner - top left corner of board
             * @param window_size - length of one side of board
             */
            BoardUI(const glm::vec2 &top_left_corner, double window_size, size_t num_cells);

            /**
             * Displays grid of cells and board itself
             */
            void Draw() const;

            GameEngine& GetGameEngine();

        private:
            double window_size_;
            glm::vec2 top_left_corner_;
            GameEngine game_engine_;
        };

    } //namespace visualizer

} //namespace gameoflife

#endif //GAME_OF_LIFE_BOARD_H
