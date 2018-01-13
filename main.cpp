/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 10, 2018
 ** Description: Main function for Project 1 Langton's Ant 
 ****************************************************************************/
#include "Ant.hpp"
#include "Menu.hpp"
#include <string>

int main()
{
    int rows;
    int cols; 
    int steps; 
    int startRow; 
    int startCol;
    std::string beginPrompts[] = {"1. Start Langton's Ant simulation", "2. Quit"}; 
    std::string middlePrompts[] = {"Number of rows for the board: ", "Number of columns for the board: ", 
                                   "Number of steps in simulation: ", "Starting row of ant: ", "Starting column of ant: "}; 
    std::string endPrompts[] = {"1. Play again", "2. Quit"}; 

    bool play = true; 
    Menu antMenu(beginPrompts, 2); 
    antMenu.setResponse(1, 2); 

    if (antMenu.getResponse() == 2)
        play = false;

    while(play)
    {
        for(int i = 0; i < )

    Ant langton(5, 5, 2, 3, NORTH); 
    Menu antMenu(prompts, 2); 
    antMenu.printMenu(); 
    antMenu.setIntegerResponse(1,2); 
    resp = antMenu.getIntegerResponse();  

    }

    return 0;
}
