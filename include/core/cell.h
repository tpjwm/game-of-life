//
// Created by dimit on 11/16/2020.
//
#pragma once
#ifndef GAME_OF_LIFE_PROJECT_CELL_H
#define GAME_OF_LIFE_PROJECT_CELL_H

#include "cinder/gl/gl.h"

namespace gameoflife{
    class Cell{
    public:
        Cell(double size, const glm::vec2& top_left_corner);
        void Draw() const;
        double GetSize() const;
    private:
        double size_;
        glm::vec2 top_left_corner_;
    };
} //namespace gameoflife
#endif //GAME_OF_LIFE_PROJECT_CELL_H
