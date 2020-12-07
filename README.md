# Conway's Game Of Life
![Image of UI](https://i.imgur.com/gmYfxC2.png)
![Gif of a glider](https://i.imgur.com/t1OJW8K.gif)

This program runs Conway's Game Of Life using Cinder, a C++ graphics library.

## Description

The Game of Life, also known simply as Life, is a cellular automation
devised by the British mathematician John Horton Conway in 1970.

It is a zero-player game, meaning its evolution is determined by its
initial state, requiring no further input.

It takes place in a 2D grid of cells each of which is in one of two possible
states: alive or dead.

Every cell interacts with its eight *neighbors*, which are cells horizontally,
vertically, and diagonally adjacent.

At each step in time each step follows the following rules:

* Any live cell with fewer than two live neighbours dies, as if by underpopulation.
* Any live cell with two or three live neighbours lives on to the next generation.
* Any live cell with more than three live neighbours dies, as if by overpopulation.
* Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

## Set Up
  - For Windows: [Microsoft Visual Studio 2015][visual-studio] or compatible compiler to work
with [Cinder][cinder].
    
    
[cinder]: https://libcinder.org/
[visual-studio]: https://docs.microsoft.com/en-us/visualstudio/releasenotes/vs2015-update3-vs

## Controls
 - Reset Button - Resets the simulation and board
 - Start Button - Starts the simulation, disables user shading
