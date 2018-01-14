/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 10, 2018
 ** Description: Main function for Project 1 Langton's Ant 
 ****************************************************************************/
#include "Ant.hpp"
#include "Menu.hpp"
#include <string>
#include <vector>


int main()
{
    int playOrQuit;
    int rows;
    int cols; 
    int steps; 
    int startRow; 
    int startCol;

    menuIO beginPrompts; 
    beginPrompts.push_back(std::make_pair("1. Start Langton's Ant simulation\n2. Quit\n", &playOrQuit)); 

    menuIO boardSetup; 
    boardSetup.push_back(std::make_pair("Number of rows for the board: ", &rows)); 
    boardSetup.push_back(std::make_pair("Number of columns for the board: ", &cols)); 
    boardSetup.push_back(std::make_pair("Number of steps for the simulation: ", &steps)); 

    menuIO rowStartLocation; 
    rowStartLocation.push_back(std::make_pair("Starting row of ant: ", &startRow)); 

    menuIO colStartLocation; 
    colStartLocation.push_back(std::make_pair("Starting column of ant: ", &startCol)); 
    
    menuIO endPrompt; 
    endPrompt.push_back(std::make_pair("1. Play again\n2. Quit\n", &playOrQuit)); 

    Menu antMenu(beginPrompts);
    antMenu.getAllResponses(1, 2); 
   
    while(playOrQuit == 1)
    {

        antMenu.setPrompts(boardSetup);
        antMenu.getAllResponses(); 

        antMenu.setPrompts(rowStartLocation); 
        antMenu.getAllResponses(1, rows, -1); 
        
        antMenu.setPrompts(colStartLocation); 
        antMenu.getAllResponses(1, cols, -1); 

        Ant langton(rows, cols, startRow, startCol, NORTH);

        langton.printBoard(); 

        for(int i = 0; i < steps; i++)
        {
            langton.move();
            langton.printBoard(); 
        }
        
        antMenu.setPrompts(endPrompt); 
        antMenu.getAllResponses(1,2); 
    }
    return 0;
}
