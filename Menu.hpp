/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 10, 2018
 ** Description: Menu class header file
 ****************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <iostream> 
#include <string>

class Menu 
{
private: 
    int intResponse; 
    int menuSize;
    std::string stringResponse; 
    std::string *prompts; 
public:
    Menu(std::string*, int); 
    void printMenu(); 
    int getIntegerResponse(int, int); 
    std::string getStringResponse(); 
    bool validateIntResponse(); 
};

#endif
