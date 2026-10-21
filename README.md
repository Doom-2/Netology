# Game of Life

## A simple implementation of Conway's Game of Life in C++

This project simulates a cellular automaton on a square grid. Each cell is either alive or dead, and its state changes from one generation to the next according to the states of its neighboring cells.

The simulation uses two symbols: an asterisk (`*`) represents a living cell, and a hyphen (`-`) represents a dead cell. A living cell survives if it has two or three living neighbors; a dead cell becomes alive if it has exactly three. In all other cases, the cell is dead in the next generation.

The initial grid is loaded from [`Game of Life/initial_data.txt`](./Game%20of%20Life/initial_data.txt). The first line contains the grid dimensions, followed by the initial cell states. The program then applies the rules to each cell and displays the resulting generations.

The project includes a Visual Studio solution and is distributed under the GNU GPL v3.0 license. See [`Game of Life/LICENSE.txt`](./Game%20of%20Life/LICENSE.txt) for the license text.
