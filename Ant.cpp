/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 10, 2018
 ** Description: Function implementation for the Ant class 
 ****************************************************************************/
#include "Ant.hpp"
#include <iostream> 
#include <string>

Ant::Ant(int rowNumber, int colNumber, int antRow, int antCol, Direction dir)
{
    orientation = dir; 
    locationRow = antRow; 
    locationCol = antCol; 
    rows = rowNumber;
    columns = colNumber;

    //Create board
    board = new int*[rows]; 
    for(int r = 0; r < rows; r++)
    {
        board[r] = new int[columns]; 
        for(int c = 0; c < columns; c++)
        {
            if(r == antRow && c == antCol)
                board[r][c] = ANT;
            else
                board[r][c] = WHITE;
        }
    }
}

void Ant::printBoard()
{
    std::cout << std::string((columns + 2), '-') << std::endl;
    for(int r = 0; r < rows; r++)
    {
        std::cout << "|";
        for(int c = 0; c < columns; c++)
        {
            switch(board[r][c])
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
    std::cout << std::string((columns + 2), '-') << std::endl;
}

Ant::~Ant()
{
    for(int r = 0; r < rows; r++)
        delete [] board[r]; 
    delete [] board;
}
