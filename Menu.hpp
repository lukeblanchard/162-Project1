/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 10, 2018
 ** Description: Menu class header file
 ****************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <iostream> 
#include <string>
#include <map>

class Menu 
{
private: 
    int intResponse; 
    int menuSize;
    std::map<std::string, int*> promptsAndResponses;

    std::string *prompts; 
    std::string singlePrompt;
public:
    Menu(std::string*, int); 
    Menu(std::string); 
    Menu(std::map<std::string, int*>);     
    void getAllResponses(); 
    void getAllResponses(int, int); 


    void printMenu(); 
    int getIntegerResponse(int, int); 
    int getIntegerResponse(); 
    bool checkInt(std::string);
    void setStringResponse(); 
    std::string getStringResponse(); 
    void setPrompts(std::map<std::string, int*>); 
    void setSinglePrompt(std::string); 
    void printSinglePrompt(); 
};

#endif
