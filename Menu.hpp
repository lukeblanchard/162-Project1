/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 10, 2018
 ** Description: Menu class header file
 ****************************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <iostream> 
#include <string>
#include <vector>

typedef std::pair<std::string, int*> menuPair; 
typedef std::vector<menuPair> menuIO; 

class Menu 
{
private: 
    int intResponse; 
    int menuSize;
    std::vector<menuPair> promptsAndResponses;

    std::string *prompts; 
    std::string singlePrompt;
public:
    Menu(std::string*, int); 
    Menu(std::string); 
    Menu(menuIO);     
    void getAllResponses(); 
    void getAllResponses(int, int, int offset=0); 


    void printMenu(); 
    int getIntegerResponse(int, int, int); 
    int getIntegerResponse(); 
    bool checkInt(std::string);
    void setStringResponse(); 
    std::string getStringResponse(); 
    void setPrompts(std::vector<menuPair>); 
    void setSinglePrompt(std::string); 
    void printSinglePrompt(); 
};

#endif
