/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 10, 2018
 ** Description: Main function for Project 1 Langton's Ant 
 ****************************************************************************/
#include "Ant.hpp"
#include "Menu.hpp"
#include <string>
#include <map>

int main()
{
    int playOrQuit;
    int rows;
    int cols; 
    int steps; 
    int startRow; 
    int startCol;
    
    std::map <std::string, int*> beginPrompts; 
    beginPrompts["1. Start Langton's Ant simulation\n2. Quit\n"] = &playOrQuit;

    std::map <std::string, int*> middlePrompts; 
    middlePrompts["Number of rows for the board: "] = &rows; 
    middlePrompts["Number of columns for the board: "] = &cols; 
    middlePrompts["Number of steps in simulation: "] = &steps; 
    middlePrompts["Starting row of ant: "] = &startRow; 
    middlePrompts["Starting column of ant: "] = &startCol; 

    std::map <std::string, int*> endPrompts; 
    endPrompts["1. Play again\n2. Quit\n"] = &playOrQuit;

    Menu antMenu(beginPrompts);
    antMenu.getAllResponses(1, 2); 
   
    while(playOrQuit == 1)
    {

        antMenu.setPrompts(middlePrompts);
        antMenu.getAllResponses(); 
        
        Ant langton(rows, cols, startRow, startCol, NORTH);

        langton.printBoard(); 

        for(int i = 0; i < steps; i++)
        {
            langton.move();
            langton.printBoard(); 
        }
        
        antMenu.setPrompts(endPrompts); 
        antMenu.getAllResponses(1,2); 
    }

    return 0;
}
