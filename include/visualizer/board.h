//
// Created by dimit on 11/14/2020.
//
#pragma once
#ifndef GAME_OF_LIFE_BOARD_H
#define GAME_OF_LIFE_BOARD_H

#include "core/cell.h"

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
            BoardUI(const glm::vec2 &top_left_corner, double window_size);

            /**
             * Displays grid of cells and board itself
             */
            void Draw() const;

            /**
             * Shades the cell at the position given.
             * Makes it "alive"
             *
             * @param mouse_coords - coords of where mouse was pressed down
             */
            void ShadeCell(const glm::vec2 &mouse_coords);

            /**
             * Getter for 2d cells vector
             */
            const std::vector<std::vector<Cell>> &GetCells() const;
            void SetCells(const std::vector<std::vector<Cell>>& cells);

        private:
            double window_size_;
            glm::vec2 top_left_corner_;
            size_t kNumCells = 40; ///TODO: change to const, create copy ctor
            std::vector<std::vector<Cell>> cells_;
        };

    } //namespace visualizer

} //namespace gameoflife

#endif //GAME_OF_LIFE_BOARD_H
