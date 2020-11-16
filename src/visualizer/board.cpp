//
// Created by dimit on 11/14/2020.
//
#include "visualizer/board.h"

namespace gameoflife{
    namespace visualizer{

        Board::Board(const glm::vec2& top_left_corner, double window_size) {
            top_left_corner_ = top_left_corner;
            window_size_ = window_size;

            std::vector<Cell> row_of_cells;
            double size = window_size_ / (float)kNumCells;
            for (size_t i = 0; i < kNumCells; ++i) {
                row_of_cells.clear();
                for (size_t j = 0; j < kNumCells; ++j) {
                    row_of_cells.emplace_back(size, glm::vec2(top_left_corner.x + size * j, top_left_corner.y + i * size));
                }
                cells_.push_back(row_of_cells);
            }
        }

        void Board::Draw() const {
            ci::gl::color(0.57f,0.57f,0.57f); //grey
            glm::vec2 bottom_right_corner =
                    top_left_corner_ + glm::vec2(window_size_, window_size_);
            ci::Rectf bounding_box(top_left_corner_, bottom_right_corner);

            ci::gl::drawSolidRect(bounding_box);

            for (size_t i = 0; i < kNumCells; ++i) {
                for (size_t j = 0; j < kNumCells; ++j) {
                    cells_[i][j].Draw();
                }
            }

        }
    }
}