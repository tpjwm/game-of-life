//
// Created by dimit on 11/14/2020.
//
#include "visualizer/board.h"

namespace gameoflife {
    namespace visualizer {

        BoardUI::BoardUI(const glm::vec2 &top_left_corner, double window_size, size_t num_cells)
                : game_engine_(num_cells) {
            top_left_corner_ = top_left_corner;
            window_size_ = window_size;
            std::vector<std::vector<Cell>> cells;
            double size = window_size_ / (float) num_cells;
            for (size_t row = 0; row < num_cells; ++row) {
                std::vector<Cell> row_of_cells;
                for (size_t col = 0; col < num_cells; ++col) {
                    row_of_cells.emplace_back(size,
                                              glm::vec2(top_left_corner.x + size * col,
                                                        top_left_corner.y + row * size));
                }
                cells.push_back(row_of_cells);
            }
            game_engine_.SetCells(cells);
        }

        void BoardUI::Draw() const {
            ci::gl::color(0.57f, 0.57f, 0.57f); //grey
            glm::vec2 bottom_right_corner =
                    top_left_corner_ + glm::vec2(window_size_, window_size_);
            ci::Rectf bounding_box(top_left_corner_, bottom_right_corner);

            ci::gl::drawSolidRect(bounding_box);

            std::vector<std::vector<Cell>> cells = game_engine_.GetCells();
            for (size_t i = 0; i < game_engine_.GetNumCells(); ++i) {
                for (size_t j = 0; j < game_engine_.GetNumCells(); ++j) {
                    cells[i][j].Draw();
                }
            }

        }

        GameEngine &BoardUI::GetGameEngine() {
            return game_engine_;
        }
    } //namespace visualizer

} //namespace gameoflife