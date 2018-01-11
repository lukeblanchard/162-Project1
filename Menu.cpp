/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 10, 2018
 ** Description: Menu class implementation
 ****************************************************************************/
 #include "Menu.hpp"

Menu::Menu(std::string *menuPrompts, int size)
{
    prompts = menuPrompts;
    menuSize = size; 
}

void Menu::printMenu()
{
    for(int i = 0; i < menuSize; i++)
        std::cout << prompts[i] << std::endl; 
}

int Menu::getIntegerResponse(int low, int high)
{
    int response; 
    std::cin >> response; 
    while(std::cin.fail() || response < low || response > high)
    {
        std::cin.clear(); 
        std::cin.ignore(); 
        std::cout << "Please enter a valid number from " << low << "-" << high << ": "; 
        std::cin >> response;
    }
    
    return response;
}
