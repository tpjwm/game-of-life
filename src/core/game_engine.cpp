//
// Created by dimit on 11/16/2020.
//
#include "core/game_engine.h"

namespace gameoflife {

    GameEngine::GameEngine(size_t num_cells){
        num_cells_ = num_cells;
    }

    void GameEngine::UpdateCells() {
        std::vector<std::vector<Cell>> future_cells = cells_; //need this or else updates conflict

        for (size_t row = 1; row <cells_.size()-1; ++row) {
            for (size_t col = 1; col < cells_[row].size()-1; ++col) {

                int alive_neighbors = GetNumLivingNeighbors(row, col);

                ///Rules of life:
                //if cell alive but lonely
                if (cells_[row][col].IsAlive() && (alive_neighbors < 2)){
                    future_cells[row][col].SetLife(false);
                }
                //if cell alive but overpopulated
                else if (cells_[row][col].IsAlive() && (alive_neighbors > 3)){
                    future_cells[row][col].SetLife(false);
                }
                //if cell is dead but has 3 neighbors
                else if (!cells_[row][col].IsAlive() && (alive_neighbors == 3)){
                    future_cells[row][col].SetLife(true);
                }
            }
        }
        cells_ = future_cells;
    }

    size_t GameEngine::GetNumLivingNeighbors(size_t row, size_t col) {
        //Find number of neighbors alive
        size_t alive_neighbors = 0;

        //for each cell immediately around the cell being examined
        for(int i = -1; i <= 1; i++){
            for (int j = -1; j<= 1; j++){
                if (cells_[row + i][col + j].IsAlive()){
                    alive_neighbors++;
                }
            }
        }
        //subtract the cell's life value from alive_neighbors if it is alive
        if (cells_[row][col].IsAlive()){
            alive_neighbors--;
        }

        return alive_neighbors;
    }

    const std::vector<std::vector<Cell>> & GameEngine::GetCells() const {
        return cells_;
    }

    void GameEngine::SetCells(const std::vector<std::vector<Cell>> &cells) {
        cells_ = cells;
    }

    void GameEngine::ShadeCell(const glm::vec2 &mouse_coords) {
        for (size_t i = 0; i < num_cells_; ++i) {
            for (size_t j = 0; j < num_cells_; ++j) {
                glm::vec2 top_left = cells_[i][j].GetTopLeftCorner();
                double size = cells_[i][j].GetSize();

                if (mouse_coords.x >= top_left.x && mouse_coords.y >= top_left.y
                    && mouse_coords.x < top_left.x + size && mouse_coords.y < top_left.y + size) {
                    cells_[i][j].SetLife(true);
                }
            }
        }
    }

    size_t GameEngine::GetNumCells() const {
        return num_cells_;
    }

} //namespace gameoflife
