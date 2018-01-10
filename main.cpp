/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 10, 2018
 ** Description: Main function for Project 1 Langton's Ant 
 ****************************************************************************/
#include "Ant.hpp"

int main()
{
    Ant langton(5, 5, 2, 3, NORTH); 
    for(int i = 0; i < 50; i++)
    {
        langton.printBoard(); 
        langton.move();
    }
    return 0;
}
