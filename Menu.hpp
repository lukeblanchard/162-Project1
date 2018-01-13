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
    std::string singlePrompt;
public:
    Menu(std::string*, int); 
    Menu(std::string); 
    void printMenu(); 
    void setIntegerResponse(int, int); 
    void setIntegerResponse(); 
    int getIntegerResponse(); 
    bool checkInt(std::string);
    void setStringResponse(); 
    std::string getStringResponse(); 
    void setPrompts(std::string*); 
    void setSinglePrompt(std::string); 
    void printSinglePrompt(); 
};

#endif
