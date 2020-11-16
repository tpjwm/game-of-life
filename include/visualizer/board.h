//
// Created by dimit on 11/14/2020.
//
#pragma once
#ifndef GAME_OF_LIFE_BOARD_H
#define GAME_OF_LIFE_BOARD_H

#include "core/cell.h"

namespace gameoflife {
    namespace visualizer {
        class Board {
        public:
            Board(const glm::vec2& top_left_corner, double window_size);
            void Draw() const;
            void StartSimulation(const glm::vec2& mouse_coords);
        private:
            double window_size_;
            glm::vec2 top_left_corner_;
            const size_t kNumCells = 40;
            std::vector<std::vector<Cell>> cells_;
        };
    } //namespace visualizer
} //namespace gameoflife
#endif //GAME_OF_LIFE_BOARD_H
