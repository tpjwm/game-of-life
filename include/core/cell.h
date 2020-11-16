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
        bool IsAlive() const;
        void SetLife(bool living);
        const glm::vec2& GetTopLeftCorner();
    private:
        double size_;
        glm::vec2 top_left_corner_;
        bool alive_;
    };
} //namespace gameoflife
#endif //GAME_OF_LIFE_PROJECT_CELL_H
