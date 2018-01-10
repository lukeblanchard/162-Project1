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
    color = WHITE;
    locationRow = antRow; 
    locationCol = antCol; 
    rows = rowNumber;
    columns = colNumber;

    board = new Board(rowNumber, colNumber);
    board->setSpace(antRow, antCol, ANT); 
}

int Ant::getRow()
{
    return locationRow; 
}

void Ant::setRow(int row)
{
    locationRow = row; 
}

int Ant::getCol()
{
    return locationCol;
}

void Ant::setCol(int col)
{
    locationCol = col; 
}

Direction Ant::getOrientation()
{
    return orientation; 
}

void Ant::setOrientation(int dir)
{
    switch(dir)
    {
        case 0 : orientation = NORTH;
            break;
        case 1 : orientation = EAST;
            break;
        case 2 : orientation = SOUTH;
            break;
        case 3 : orientation = WEST;
            break;
    }
}

void Ant::moveAnt()
{
           
}

void Ant::printBoard()
{
    board->printBoard();
}

Ant::~Ant()
{
    delete board;
}
