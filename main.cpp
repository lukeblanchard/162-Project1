/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 10, 2018
 ** Description: Main function for Project 1 Langton's Ant 
 ****************************************************************************/

#include "Ant.hpp"
#include "Menu.hpp"
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int playOrQuit;
    int rows;
    int cols; 
    int steps; 
    int startRow; 
    int startCol;
    bool randomLoc;
    Menu antMenu; 
    srand (time(NULL)); 

    menuIntIO beginPrompts; 
    beginPrompts.push_back(std::make_pair("1. Start Langton's Ant simulation\n2. Quit\n", &playOrQuit)); 

    menuIntIO boardSetup; 
    boardSetup.push_back(std::make_pair("Number of rows for the board: ", &rows)); 
    boardSetup.push_back(std::make_pair("Number of columns for the board: ", &cols)); 
    boardSetup.push_back(std::make_pair("Number of steps for the simulation: ", &steps)); 

    menuBoolIO randomLocation; 
    randomLocation.push_back(std::make_pair("Do you want to start from a random location? (y/n) ", &randomLoc)); 

    menuIntIO rowStartLocation; 
    rowStartLocation.push_back(std::make_pair("Starting row of ant: ", &startRow)); 

    menuIntIO colStartLocation; 
    colStartLocation.push_back(std::make_pair("Starting column of ant: ", &startCol)); 
    
    menuIntIO endPrompt; 
    endPrompt.push_back(std::make_pair("1. Play again\n2. Quit\n", &playOrQuit)); 

    antMenu.load(beginPrompts, 1, 2); 
   
    while(playOrQuit == 1)
    {

        antMenu.load(boardSetup);
        antMenu.load(randomLocation); 

        if(randomLoc)
        {
            startRow = rand() % rows; 
            startCol = rand() % cols; 
        }
        else 
        {
            antMenu.load(rowStartLocation, 1, rows, -1); 
            antMenu.load(colStartLocation, 1, cols, -1); 
        }

        Ant langton(rows, cols, startRow, startCol, NORTH);

        langton.printBoard(); 

        for(int i = 0; i < steps; i++)
        {
            langton.move();
            langton.printBoard(); 
        }
        
        antMenu.load(endPrompt, 1, 2); 
    }
    return 0;
}
