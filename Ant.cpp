/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 10, 2018
 ** Description: Function implementation for the Ant class 
 ****************************************************************************/
#include "Ant.hpp"
#include <iostream> 
#include <string>

Ant::Ant(int rowNumber, int colNumber, int antR, int antC, Direction dir)
{
    orientation = dir; 
    color = WHITE;
    antRow = antR;
    antCol = antC;
    rows = rowNumber;
    columns = colNumber;

    board = new Board(rowNumber, colNumber);
    board->setSpace(antRow, antCol, ANT); 
}

int Ant::getRow()
{
    return antRow; 
}

void Ant::setRow(int row)
{
    antRow = row; 
}

int Ant::getCol()
{
    return antCol;
}

void Ant::setCol(int col)
{
    antCol = col; 
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

void Ant::move()
{
    bool validMove = false; 
    int newOrientation; 
    int newRow; 
    int newCol;

    while(!validMove)
    {
        if(color == WHITE)
        {
            newOrientation = (orientation + 1) % 4; 
            setOrientation(newOrientation);     
        }
        else 
        {
            newOrientation = (orientation + 3) % 4; //3 right turns equals one left turn
            setOrientation(newOrientation);     
        }
        switch(orientation)
        {
            case NORTH : newRow = antRow - 1; 
                         newCol = antCol; 
                         break;
            case EAST : newRow = antRow; 
                        newCol = antCol + 1; 
                        break;
            case SOUTH : newRow = antRow + 1; 
                         newCol = antCol; 
                         break;
            case WEST : newRow = antRow; 
                        newCol = antCol - 1; 
                        break;
        }
        if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < columns)
            validMove = true; 
    }
    //Set color of old space
    if(color == WHITE) 
        board->setSpace(antRow, antCol, BLACK); 
    else
        board->setSpace(antRow, antCol, WHITE); 
    //Get color of new space
    switch(board->getSpace(newRow, newCol))
    {
        case 0 : color = WHITE;
                 break;
        case 1 : color = BLACK;
                 break; 
    }
    //Update ant location
    antRow = newRow; 
    antCol = newCol;
    board->setSpace(antRow, antCol, ANT); 
}

void Ant::printBoard()
{
    board->printBoard();
}

Ant::~Ant()
{
    delete board;
}
