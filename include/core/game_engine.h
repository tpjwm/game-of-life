//
// Created by dimit on 11/16/2020.
//
#pragma once

#ifndef GAME_OF_LIFE_PROJECT_GAME_ENGINE_H
#define GAME_OF_LIFE_PROJECT_GAME_ENGINE_H

#include "core/cell.h"
#include "cinder/audio/Voice.h"
#include "cinder/app/App.h"

namespace gameoflife {
    class GameEngine {
    public:
        /**
         * Default constructor for GameEngine
         * @param num_cells - the number of cells for the side of the square board
         *                    (i.e if num_cells = 40, constructs a 40 x 40 vector)
         */
        explicit GameEngine(size_t num_cells);

        /**
         * Takes in a reference to 2D vector of cells and "updates" them to the next
         * positions according to the rules of life and returns resulting 2D vector of cells
         * @param cells - the cells before being updated
         * @return - updated 2D cells vector
         */
        void UpdateCells();

        //Getter for 2D cells vector
        const std::vector<std::vector<Cell>> &GetCells() const;

        //Setter for 2D cells vector
        void SetCells(const std::vector<std::vector<Cell>> &cells);

        //Getter for number of cells
        size_t GetNumCells() const;

        /**
         * Shades the cell at the position given.
         * Flips the value of the cell (from alive to dead or dead to alive)
         *
         * @param mouse_coords - coords of where mouse was pressed down
         */
        void ShadeCell(const glm::vec2 &mouse_coords);
        void SpeedUp();
        void SlowDown();
        void PlayMusic();
        void StopMusic();
    private:
        /**
         * Calculates the amount of living neighbors around a cell at a particular
         * spot in a 2D grid.
         *
         * Does not account for border cells
         *
         * @param cells - the grid of cells
         * @param row - the row value of the cell
         * @param col - the column value of the cell
         * @return - the number of living neighbors around the cell
         */
        size_t GetNumLivingNeighbors(size_t row, size_t col);

        std::vector<std::vector<Cell>> cells_;
        size_t num_cells_;
        size_t slow_down_millis_ = 50; //how much to slow the simulation by for each time update cell is called

        std::vector<std::string> song_names_;

        std::string song_path_ = "1.wav";
        ci::audio::SourceFileRef source_file_ = ci::audio::load(ci::app::loadAsset(song_path_));
        ci::audio::VoiceRef mVoice;
    };

} //namespace gameoflife

#endif //GAME_OF_LIFE_PROJECT_GAME_ENGINE_H
