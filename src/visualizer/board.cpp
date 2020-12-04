//
// Created by dimit on 11/14/2020.
//
#include "visualizer/board.h"

namespace gameoflife {
    namespace visualizer {

        BoardUI::BoardUI(const glm::vec2 &top_left_corner, double window_size) {
            top_left_corner_ = top_left_corner;
            window_size_ = window_size;


            double size = window_size_ / (float) kNumCells;
            for (size_t row = 0; row < kNumCells; ++row) {
                std::vector<Cell> row_of_cells;
                for (size_t col = 0; col < kNumCells; ++col) {
                    row_of_cells.emplace_back(size,
                                              glm::vec2(top_left_corner.x + size * col,top_left_corner.y + row * size)); ///use local variables
                }
                cells_.push_back(row_of_cells);
            }
        }

        void BoardUI::Draw() const {
            ci::gl::color(0.57f, 0.57f, 0.57f); //grey
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

        void BoardUI::ShadeCell(const glm::vec2 &mouse_coords) {
            for (size_t i = 0; i < kNumCells; ++i) {
                for (size_t j = 0; j < kNumCells; ++j) {
                    glm::vec2 top_left = cells_[i][j].GetTopLeftCorner();
                    double size = cells_[i][j].GetSize();

                    if (mouse_coords.x >= top_left.x && mouse_coords.y >= top_left.y
                        && mouse_coords.x < top_left.x + size && mouse_coords.y < top_left.y + size) {
                        cells_[i][j].SetLife(true);
                    }
                }
            }
        }

        const std::vector<std::vector<Cell>> &BoardUI::GetCells() const {
            return cells_;
        }

        void BoardUI::SetCells(const std::vector<std::vector<Cell>> &cells) {
            cells_ = cells;
        }

    } //namespace visualizer

} //namespace gameoflife