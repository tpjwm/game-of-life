//
// Created by dimit on 11/16/2020.
//
#include "core/cell.h"
namespace gameoflife{

    Cell::Cell(double size, const glm::vec2& top_left_corner) {
        size_ = size;
        top_left_corner_ = top_left_corner;
    }

    void Cell::Draw() const{
        ci::gl::color(255,255,255); //black

        glm::vec2 bottom_right_corner = top_left_corner_ + glm::vec2(size_, size_);

        ci::Rectf bounding_box(top_left_corner_, bottom_right_corner);

        ci::gl::drawStrokedRect(bounding_box, 2);
    }

    double Cell::GetSize() const{
        return size_;
    }
} //namespace gameoflife
