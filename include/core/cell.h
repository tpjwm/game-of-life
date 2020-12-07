//
// Created by dimit on 11/16/2020.
//
#pragma once
#ifndef GAME_OF_LIFE_PROJECT_CELL_H
#define GAME_OF_LIFE_PROJECT_CELL_H

#include "cinder/gl/gl.h"

namespace gameoflife {
    class Cell {
    public:
        /**
         * Constructor for Cell
         * Takes in size and top left corner, makes square cell
         *
         * @param size - length of one side of cell
         * @param top_left_corner - top left corner of cell
         */
        Cell(double size, const glm::vec2 &top_left_corner);

        /**
         * Draws the cell and if "alive" shades it
         */
        void Draw() const;

        /**
         * Getter for size
         */
        double GetSize() const;

        /**
         * Returns true if cell is considered "alive" (shaded)
         * False if cell is not "alive"
         */
        bool IsAlive() const;

        /**
         * Setter for alive_
         * @param living - the true/false status of a cell
         */
        void SetLife(bool living);

        /**
         * Getter for top_left_corner_
         */
        const glm::vec2 &GetTopLeftCorner();

    private:
        double size_;
        glm::vec2 top_left_corner_;
        bool alive_; //If true, shades cell, otherwise remains unshaded
        float line_width_ = 2;
    };

} //namespace gameoflife

#endif //GAME_OF_LIFE_PROJECT_CELL_H
