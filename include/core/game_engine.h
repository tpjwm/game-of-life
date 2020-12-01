//
// Created by dimit on 11/16/2020.
//
#pragma once

#ifndef GAME_OF_LIFE_PROJECT_GAME_ENGINE_H
#define GAME_OF_LIFE_PROJECT_GAME_ENGINE_H

#include "visualizer/board.h"

namespace gameoflife {
    class GameEngine {
    public:
        GameEngine();
        std::vector<std::vector<Cell>> UpdateCells(const std::vector<std::vector<Cell>> &cells);
    private:

        int GetLivingNeighbors(const std::vector<std::vector<Cell>> &cells, size_t row, size_t col);
    };

} //namespace gameoflife

#endif //GAME_OF_LIFE_PROJECT_GAME_ENGINE_H
