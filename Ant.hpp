/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 10, 2018 
 ** Description: Header file for the Ant class 
 ****************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include "Board.hpp"

    //Enumerated type to track ant direction on the board
    enum Direction {NORTH, EAST, SOUTH, WEST}; 

class Ant 
{
private: 
    Direction orientation; 
    Space color;
    int locationRow; 
    int locationCol; 
    int rows; 
    int columns;
    Board *board; 
public:
    Ant(int, int, int, int, Direction); 
    int getRow(); 
    void setRow(int);
    int getCol(); 
    void setCol(int);
    Direction getOrientation(); 
    void setOrientation(int); 
    void moveAnt(); 
    void printBoard(); 
    ~Ant(); 
};
#endif
