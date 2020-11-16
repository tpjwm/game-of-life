//
// Created by dimit on 11/16/2020.
//
#include "core/cell.h"
namespace gameoflife{

    Cell::Cell(double size, const glm::vec2& top_left_corner) {
        size_ = size;
        top_left_corner_ = top_left_corner;
        alive_ = false;
    }

    void Cell::Draw() const{
        ci::gl::color(255,255,255); //white

        glm::vec2 bottom_right_corner = top_left_corner_ + glm::vec2(size_, size_);

        ci::Rectf bounding_box(top_left_corner_, bottom_right_corner);

        ci::gl::drawStrokedRect(bounding_box, 1);
        if (alive_){
            ci::gl::color(0,0,0); //black
            ci::gl::drawSolidRect(bounding_box);
        }
    }

    double Cell::GetSize() const{
        return size_;
    }

    bool Cell::IsAlive() const {
        return alive_;
    }

    void Cell::SetLife(bool living) {
        alive_ = living;
    }

    const glm::vec2 &Cell::GetTopLeftCorner() {
        return top_left_corner_;
    }
} //namespace gameoflife
