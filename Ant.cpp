/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 10, 2018
 ** Description: Function implementation for the Ant class 
 ****************************************************************************/

Ant(int rowNumber, int colNumber, int antRow, int antCol, Direction dir)
{
    orientation = dir; 
    locationRow = antRow; 
    locationCol = antCol; 

    //Create board
    board = new char*[rowNumber]; 
    for(int r = 0; r < rowNumber; r++)
    {
        board[r] = new char[colNumber]; 
        for(int c = 0; c < colNumber; c++)
        {
            
        }
    }

    //Initialize board spaces
}
