//
// Created by dimit on 11/14/2020.
//
#include "visualizer/board.h"

namespace gameoflife{
    namespace visualizer{

        Board::Board(const glm::vec2& top_left_corner, double window_size) {
            top_left_corner_ = top_left_corner;
            window_size_ = window_size;
        }

        void Board::Draw() const {
            ci::gl::color(0.57f,0.57f,0.57f);
            glm::vec2 bottom_right_corner =
                    top_left_corner_ + glm::vec2(window_size_, window_size_);
            ci::Rectf bounding_box(top_left_corner_, bottom_right_corner);

            ci::gl::drawSolidRect(bounding_box);

        }
    }
}