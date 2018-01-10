/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 10, 2018
 ** Description: Implementation for Board class
 ****************************************************************************/
#include "Board.hpp"
#include <iostream>

Board::Board(int rowNumber, int colNumber)
{
    rows = rowNumber; 
    cols = colNumber;

    //Create grid
    grid = new int*[rows]; 
    for(int r = 0; r < rows; r++)
    {
        grid[r] = new int[cols]; 
        for(int c = 0; c < cols; c++)
            grid[r][c] = WHITE;
    }
}

int Board::getSpace(int r, int c)
{
    return grid[r][c]; 
}

void Board::setSpace(int r, int c, Space s)
{
    grid[r][c] = s; 
}


void Board::printBoard()
{
    std::cout << std::string((cols + 2), '-') << std::endl;
    for(int r = 0; r < rows; r++)
    {
        std::cout << "|";
        for(int c = 0; c < cols; c++)
        {
            switch(grid[r][c])
            {
                case WHITE  :   std::cout << " "; 
                                break;
                case BLACK  :   std::cout << "#"; 
                                break;
                case ANT    :   std::cout << "*"; 
            }
        }
        std::cout << "|" << std::endl;
    }
    std::cout << std::string((cols + 2), '-') << std::endl;
}

Board::~Board()
{
    for(int r = 0; r < rows; r++)
        delete [] grid[r]; 

    delete [] grid; 
}
