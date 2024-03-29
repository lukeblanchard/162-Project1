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

typedef std::pair<std::string, int*> menuIntPrompts; 
typedef std::pair<std::string, std::string*> menuStringPrompts; 
typedef std::pair<std::string, bool*> menuBoolPrompts; 
typedef std::vector<menuIntPrompts> menuIntIO; 
typedef std::vector<menuStringPrompts> menuStringIO; 
typedef std::vector<menuBoolPrompts> menuBoolIO; 

class Menu 
{
private: 
    menuIntIO intResponses;
    menuStringIO stringResponses;
    menuBoolIO boolResponses;
public:
    void load(menuIntIO); 
    void load(menuIntIO, int, int, int offset = 0); 
    void load(menuStringIO); 
    void load(menuBoolIO); 

    void getAllResponses(menuIntIO); 
    void getAllResponses(menuIntIO, int, int, int); 
    void getAllResponses(menuStringIO); 
    void getAllResponses(menuBoolIO); 

    
    int getIntegerResponse(int, int, int); 
    int getIntegerResponse(); 
    bool checkInt(std::string);

    bool getBoolResponse(); 
    bool checkBool(std::string*); 
};

#endif
