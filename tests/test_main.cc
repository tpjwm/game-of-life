#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <visualizer/game_of_life_app.h>

namespace gameoflife{
    ///Board at 40 by 40 cells
    TEST_CASE("GameEngine Functionality at corner"){
        visualizer::BoardUI board(glm::vec2(0,0), 875, 40);

        std::vector<std::vector<Cell>> cells = std::vector<std::vector<Cell>>(board.GetGameEngine().GetCells());
        cells[2][2].SetLife(true); //cell in the center, being tested


        SECTION("Live Cell with 0 neighbors"){
            board.GetGameEngine().SetCells(cells);
            board.GetGameEngine().UpdateCells();
            visualizer::BoardUI test_board(glm::vec2(0,0), 875, 40);

            //test_board should have clear board which should be the next step as 0 neighbors kills the cell
            std::vector<std::vector<Cell>> test_cells = std::vector<std::vector<Cell>>(test_board.GetGameEngine().GetCells());
            std::vector<std::vector<Cell>> updated_cells = std::vector<std::vector<Cell>>(board.GetGameEngine().GetCells());

            //make sure each cell is the same
            for (size_t i = 0; i < test_cells.size(); ++i) {
                for (size_t j = 0; j < test_cells[i].size(); ++j) {
                    REQUIRE(test_cells[i][j].IsAlive() == updated_cells[i][j].IsAlive());
                }
            }
        }
        SECTION("Live Cell with 1 neighbors"){

            cells[1][1].SetLife(true); //upper left neighbor
            board.GetGameEngine().SetCells(cells);

            board.GetGameEngine().UpdateCells();
            visualizer::BoardUI test_board(glm::vec2(0,0), 875,40);

            //test_board should have clear board which should be the next step as 1 neighbors kills the cell
            std::vector<std::vector<Cell>> test_cells = std::vector<std::vector<Cell>>(test_board.GetGameEngine().GetCells());
            std::vector<std::vector<Cell>> updated_cells = std::vector<std::vector<Cell>>(board.GetGameEngine().GetCells());

            //make sure each cell is the same
            for (size_t i = 0; i < test_cells.size(); ++i) {
                for (size_t j = 0; j < test_cells[i].size(); ++j) {
                    REQUIRE(test_cells[i][j].IsAlive() == updated_cells[i][j].IsAlive());
                }
            }
        }
        SECTION("Live Cell with 2 neighbors"){
            cells[1][1].SetLife(true); //upper left neighbor
            cells[2][1].SetLife(true); //above neighbor
            board.GetGameEngine().SetCells(cells);
            board.GetGameEngine().UpdateCells();

            visualizer::BoardUI test_board(glm::vec2(0,0), 875, 40);

            //board shouldn't have changed the 3 cells shaded as it has 2 neighbors,
            //test_cells must be the same as board cells before update except for 1 extra shaded cell
            std::vector<std::vector<Cell>> test_cells = std::vector<std::vector<Cell>>(test_board.GetGameEngine().GetCells());
            test_cells[1][1].SetLife(true);
            test_cells[2][1].SetLife(true);
            test_cells[2][2].SetLife(true);
            test_cells[1][2].SetLife(true); //now that this cell has 3 neighbors it populates
            test_board.GetGameEngine().SetCells(test_cells);
            test_cells = std::vector<std::vector<Cell>>(test_board.GetGameEngine().GetCells());

            std::vector<std::vector<Cell>> updated_cells = std::vector<std::vector<Cell>>(board.GetGameEngine().GetCells());

            //make sure each cell is the same
            for (size_t i = 0; i < test_cells.size(); ++i) {
                for (size_t j = 0; j < test_cells[i].size(); ++j) {
                    REQUIRE(test_cells[i][j].IsAlive() == updated_cells[i][j].IsAlive());
                }
            }
        }
        SECTION("Live Cell with 3 neighbors"){
            cells[1][1].SetLife(true); //upper left neighbor
            cells[2][1].SetLife(true); //above neighbor
            cells[3][1].SetLife(true); //upper right neighbor
            board.GetGameEngine().SetCells(cells);
            board.GetGameEngine().UpdateCells();

            visualizer::BoardUI test_board(glm::vec2(0,0), 875,40);

            //board shouldn't have changed the 4 cells shaded as it has 3 neighbors,
            //2 extra shaded cells appear where the adjacent neighbors equal 3
            std::vector<std::vector<Cell>> test_cells = std::vector<std::vector<Cell>>(test_board.GetGameEngine().GetCells());
            test_cells[1][1].SetLife(true);
            test_cells[2][1].SetLife(true);
            test_cells[2][2].SetLife(true);
            test_cells[3][1].SetLife(true);
            test_cells[1][2].SetLife(true);//cell that was brought to life
            test_cells[3][2].SetLife(true);//cell that was brought to life

            test_board.GetGameEngine().SetCells(test_cells);
            test_cells = std::vector<std::vector<Cell>>(test_board.GetGameEngine().GetCells());

            std::vector<std::vector<Cell>> updated_cells = std::vector<std::vector<Cell>>(board.GetGameEngine().GetCells());

            //make sure each cell is the same
            for (size_t i = 0; i < test_cells.size(); ++i) {
                for (size_t j = 0; j < test_cells[i].size(); ++j) {
                    REQUIRE(test_cells[i][j].IsAlive() == updated_cells[i][j].IsAlive());
                }
            }
        }
        SECTION("Live Cell with 4 neighbors"){

            cells[1][1].SetLife(true); //upper left neighbor
            cells[2][1].SetLife(true); //above neighbor
            cells[3][1].SetLife(true); //upper right neighbor
            cells[1][2].SetLife(true); //left neighbor

            board.GetGameEngine().SetCells(cells);
            board.GetGameEngine().UpdateCells();

            visualizer::BoardUI test_board(glm::vec2(0,0), 875, 40);

            //cell at 2,1 and cell at 2,2 are killed by overpopulation,
            //1 extra cell at 3,2 is given life, everything else stays the same
            std::vector<std::vector<Cell>> test_cells = std::vector<std::vector<Cell>>(test_board.GetGameEngine().GetCells());
            test_cells[1][1].SetLife(true);
            test_cells[3][1].SetLife(true);
            test_cells[1][2].SetLife(true);//stays alive
            test_cells[3][2].SetLife(true);//cell that was brought to life

            test_board.GetGameEngine().SetCells(test_cells);
            test_cells = std::vector<std::vector<Cell>>(test_board.GetGameEngine().GetCells());

            std::vector<std::vector<Cell>> updated_cells = std::vector<std::vector<Cell>>(board.GetGameEngine().GetCells());

            //make sure each cell is the same
            for (size_t i = 0; i < test_cells.size(); ++i) {
                for (size_t j = 0; j < test_cells[i].size(); ++j) {
                    REQUIRE(test_cells[i][j].IsAlive() == updated_cells[i][j].IsAlive());
                }
            }
        }
        SECTION("Live Cell with 5 neighbors"){
            cells[1][1].SetLife(true); //upper left neighbor
            cells[2][1].SetLife(true); //above neighbor
            cells[3][1].SetLife(true); //upper right neighbor
            cells[1][2].SetLife(true); //left neighbor
            cells[3][2].SetLife(true); //right neighbor

            board.GetGameEngine().SetCells(cells);
            board.GetGameEngine().UpdateCells();

            visualizer::BoardUI test_board(glm::vec2(0,0), 875, 40);

            //cell at 2,1 and cell at 2,2 are killed by overpopulation,
            //1 extra cell at 2,3 is given life, everything else stays the same
            std::vector<std::vector<Cell>> test_cells = std::vector<std::vector<Cell>>(test_board.GetGameEngine().GetCells());
            test_cells[1][1].SetLife(true);
            test_cells[3][1].SetLife(true);
            test_cells[1][2].SetLife(true);//stays alive
            test_cells[3][2].SetLife(true);//stays alive
            test_cells[2][3].SetLife(true); //cell that was brought to life

            test_board.GetGameEngine().SetCells(test_cells);
            test_cells = std::vector<std::vector<Cell>>(test_board.GetGameEngine().GetCells());

            std::vector<std::vector<Cell>> updated_cells = std::vector<std::vector<Cell>>(board.GetGameEngine().GetCells());

            //make sure each cell is the same
            for (size_t i = 0; i < test_cells.size(); ++i) {
                for (size_t j = 0; j < test_cells[i].size(); ++j) {
                    REQUIRE(test_cells[i][j].IsAlive() == updated_cells[i][j].IsAlive());
                }
            }
        }
        SECTION("Live Cell with 6 neighbors"){
            cells[1][1].SetLife(true); //upper left neighbor
            cells[2][1].SetLife(true); //above neighbor
            cells[3][1].SetLife(true); //upper right neighbor
            cells[1][2].SetLife(true); //left neighbor
            cells[3][2].SetLife(true); //right neighbor
            cells[1][3].SetLife(true); //bottom left neighbor

            board.GetGameEngine().SetCells(cells);
            board.GetGameEngine().UpdateCells();

            visualizer::BoardUI test_board(glm::vec2(0,0), 875, 40);

            //cell at 1,2; cell at 2,1; cell at 2,2 are killed
            //other cells stay the same
            std::vector<std::vector<Cell>> test_cells = std::vector<std::vector<Cell>>(test_board.GetGameEngine().GetCells());
            test_cells[1][1].SetLife(true);//stays alive
            test_cells[3][1].SetLife(true);//stays alive
            test_cells[1][3].SetLife(true);//stays alive
            test_cells[3][2].SetLife(true);//stays alive

            test_board.GetGameEngine().SetCells(test_cells);
            test_cells = std::vector<std::vector<Cell>>(test_board.GetGameEngine().GetCells());

            std::vector<std::vector<Cell>> updated_cells = std::vector<std::vector<Cell>>(board.GetGameEngine().GetCells());

            //make sure each cell is the same
            for (size_t i = 0; i < test_cells.size(); ++i) {
                for (size_t j = 0; j < test_cells[i].size(); ++j) {
                    REQUIRE(test_cells[i][j].IsAlive() == updated_cells[i][j].IsAlive());
                }
            }
        }
        SECTION("Live Cell with 7 neighbors"){
            cells[1][1].SetLife(true); //upper left neighbor
            cells[2][1].SetLife(true); //above neighbor
            cells[3][1].SetLife(true); //upper right neighbor
            cells[1][2].SetLife(true); //left neighbor
            cells[3][2].SetLife(true); //right neighbor
            cells[1][3].SetLife(true); //bottom left neighbor
            cells[2][3].SetLife(true);//bottom neighbor

            board.GetGameEngine().SetCells(cells);
            board.GetGameEngine().UpdateCells();

            visualizer::BoardUI test_board(glm::vec2(0,0), 875, 40);

            //cell at 1,2; cell at 2,1; cell at 2,2; cell at 2,3; cell at 3,2 are killed
            //cell at 3,3 is created
            std::vector<std::vector<Cell>> test_cells = std::vector<std::vector<Cell>>(test_board.GetGameEngine().GetCells());
            test_cells[1][1].SetLife(true);//stays alive
            test_cells[3][1].SetLife(true);//stays alive
            test_cells[1][3].SetLife(true);//stays alive
            test_cells[3][3].SetLife(true);//cell that was brought to life

            test_board.GetGameEngine().SetCells(test_cells);
            test_cells = std::vector<std::vector<Cell>>(test_board.GetGameEngine().GetCells());

            std::vector<std::vector<Cell>> updated_cells = std::vector<std::vector<Cell>>(board.GetGameEngine().GetCells());

            //make sure each cell is the same
            for (size_t i = 0; i < test_cells.size(); ++i) {
                for (size_t j = 0; j < test_cells[i].size(); ++j) {
                    REQUIRE(test_cells[i][j].IsAlive() == updated_cells[i][j].IsAlive());
                }
            }
        }
        SECTION("Live Cell with 8 neighbors"){
            cells[1][1].SetLife(true); //upper left neighbor
            cells[2][1].SetLife(true); //above neighbor
            cells[3][1].SetLife(true); //upper right neighbor
            cells[1][2].SetLife(true); //left neighbor
            cells[3][2].SetLife(true); //right neighbor
            cells[1][3].SetLife(true); //bottom left neighbor
            cells[2][3].SetLife(true);//bottom neighbor
            cells[3][3].SetLife(true);//bottom right neighbor

            board.GetGameEngine().SetCells(cells);
            board.GetGameEngine().UpdateCells();

            visualizer::BoardUI test_board(glm::vec2(0,0), 875, 40);

            //cell at 1,2; cell at 2,1; cell at 2,2; cell at 2,3; cell at 3,2 are killed
            //cell at 2,4; cell at 4,2 are created
            std::vector<std::vector<Cell>> test_cells = std::vector<std::vector<Cell>>(test_board.GetGameEngine().GetCells());
            test_cells[1][1].SetLife(true);//stays alive
            test_cells[3][1].SetLife(true);//stays alive
            test_cells[1][3].SetLife(true);//stays alive
            test_cells[3][3].SetLife(true);//stays alive
            test_cells[2][4].SetLife(true);//created
            test_cells[4][2].SetLife(true);//created


            test_board.GetGameEngine().SetCells(test_cells);
            test_cells = std::vector<std::vector<Cell>>(test_board.GetGameEngine().GetCells());

            std::vector<std::vector<Cell>> updated_cells = std::vector<std::vector<Cell>>(board.GetGameEngine().GetCells());

            //make sure each cell is the same
            for (size_t i = 0; i < test_cells.size(); ++i) {
                for (size_t j = 0; j < test_cells[i].size(); ++j) {
                    REQUIRE(test_cells[i][j].IsAlive() == updated_cells[i][j].IsAlive());
                }
            }
        }
    }

} //namespace gameoflife

