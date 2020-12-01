//
// Created by dimit on 11/16/2020.
//
#include "core/game_engine.h"

namespace gameoflife {

    GameEngine::GameEngine() = default;

    std::vector<std::vector<Cell>> GameEngine::UpdateCells(const std::vector<std::vector<Cell>> &cells) {
        std::vector<std::vector<Cell>> future_cells = std::vector<std::vector<Cell>>(cells);

        for (size_t row = 1; row <cells.size()-1; ++row) {
            for (size_t col = 1; col < cells[row].size()-1; ++col) {

                int alive_neighbors = GetLivingNeighbors(cells, row, col);
                ///Rules of life

                //if cell alive but lonely
                if (cells[row][col].IsAlive() && (alive_neighbors < 2)){
                    future_cells[row][col].SetLife(false);
                }
                //if cell alive but overpopulated
                else if (cells[row][col].IsAlive() && (alive_neighbors > 3)){
                    future_cells[row][col].SetLife(false);
                }
                //if cell is dead but has 3 neighbors
                else if (!cells[row][col].IsAlive() && (alive_neighbors == 3)){
                    future_cells[row][col].SetLife(true);
                }
            }
        }
        return future_cells;
    }

    int GameEngine::GetLivingNeighbors(const std::vector<std::vector<Cell>> &cells, size_t row, size_t col) {
        //Find number of neighbors alive
        int alive_neighbors = 0;

        for(int i = -1; i <= 1; i++){
            for (int j = -1; j<= 1; j++){
                if (cells[row + i][col + j].IsAlive()){
                    alive_neighbors++;
                }
            }
        }
        if (cells[row][col].IsAlive()){
            alive_neighbors--;
        }
        return alive_neighbors;
    }

} //namespace gameoflife
