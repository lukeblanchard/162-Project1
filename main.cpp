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
    int resp;
    std::string prompts[] = {"1. Start Langton's Ant simulation", "2. Quit"}; 
    Ant langton(5, 5, 2, 3, NORTH); 
    Menu antMenu(prompts, 2); 
    antMenu.printMenu(); 
    resp = antMenu.getIntegerResponse(1, 2);  

    return 0;
}
