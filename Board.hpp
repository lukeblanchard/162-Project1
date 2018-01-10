/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 10, 2018
 ** Description: Board class header file
 ****************************************************************************/
#ifndef BOARD_HPP
#define BOARD_HPP

    enum Space {WHITE, BLACK, ANT}; 

class Board
{
private:
    int **grid; 
    int rows; 
    int cols; 
public: 
    Board(int, int); 
    int getSpace(int, int); 
    void setSpace(int, int, Space); 
    void printBoard();
    ~Board();
};

#endif
