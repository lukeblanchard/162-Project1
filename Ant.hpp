/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 10, 2018 
 ** Description: Header file for the Ant class 
 ****************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

    //Enumerated type to track ant direction on the board
    enum Direction {NORTH, EAST, SOUTH, WEST}; 
    enum Space {WHITE, BLACK, ANT}; 

class Ant 
{
private: 
    Direction orientation; 
    int locationRow; 
    int locationCol; 
    int rows; 
    int columns;
    int **board; 
public:
    Ant(int, int, int, int, Direction); 
    int getRow(); 
    void setRow();
    int getCol(); 
    void setCol();
    Direction getOrientation(); 
    void setOrientation(); 
    void moveAnt(); 
    void printBoard(); 
    ~Ant(); 
};
#endif
