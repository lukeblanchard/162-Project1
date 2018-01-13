/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 10, 2018
 ** Description: Menu class implementation
 ****************************************************************************/
#include "Menu.hpp"
#include <sstream>
#include <string> 
#include <map> 
#include <iterator> 

Menu::Menu(std::string *menuPrompts, int size)
{
    prompts = menuPrompts;
    menuSize = size; 
}

Menu::Menu(std::string prompt)
{
    prompts = nullptr;
    singlePrompt = prompt;
}

Menu::Menu(std::map<std::string, int*> menuPandR)
{
    promptsAndResponses = menuPandR;
}

void Menu::getAllResponses()
{
    for(std::map<std::string, int*>::iterator itr = promptsAndResponses.begin(); itr != promptsAndResponses.end(); ++itr)    
    {
        std::cout << itr->first; 
        *(itr->second) = getIntegerResponse(); 
    }
}

void Menu::getAllResponses(int low, int high)
{
    for(std::map<std::string, int*>::iterator itr = promptsAndResponses.begin(); itr != promptsAndResponses.end(); ++itr)    
    {
        std::cout << itr->first; 
        *(itr->second) = getIntegerResponse(low, high); 
    }
}

void Menu::printMenu()
{
    if(prompts == nullptr)
    {
        std::cout << singlePrompt << std::endl;
    }
    else
    {
        for(int i = 0; i < menuSize; i++)
            std::cout << prompts[i] << std::endl; 
    }
}

bool Menu::checkInt(std::string s)
{
    bool invalid = false; 

    for(std::string::iterator it = s.begin(); it != s.end(); ++it)
    {
        if((int) *it > 57 || (int) *it < 48)
        {
            if(it == s.begin() && (int) *it == 45)
            {
                continue; 
            }
            else
            {
                invalid = true; 
                break;
            }
        }
    }
    return invalid;
}

int Menu::getIntegerResponse(int low, int high)
{
    int response; 
    std::string strResponse;
    bool invalid;

    std::getline(std::cin, strResponse);
    invalid = checkInt(strResponse); 

    if(!invalid)
    {
        std::istringstream istr(strResponse);
        istr >> response;   
        invalid = response < low || response > high;
    }

    while(invalid) 
    {
        std::cout << "Please enter a valid number from " << low << "-" << high << ": "; 
        std::getline(std::cin, strResponse);
        invalid = checkInt(strResponse); 
        if(!invalid)
        {
            std::istringstream istr(strResponse);
            istr >> response;   
            invalid = response < low || response > high;
        }
    }
    return response;
}

int Menu::getIntegerResponse()
{
    int response; 
    std::string strResponse;
    bool invalid;

    std::getline(std::cin, strResponse);
    invalid = checkInt(strResponse); 

    while(invalid) 
    {
        std::cout << "Please enter a valid number: ";  
        std::getline(std::cin, strResponse);
        invalid = checkInt(strResponse); 
    }

    std::istringstream istr(strResponse);
    istr >> response;
    return response;
}

void Menu::setPrompts(std::map<std::string, int*> newPAndR)
{
    promptsAndResponses = newPAndR;
}

void Menu::setSinglePrompt(std::string newPrompt)
{
    prompts = nullptr;
    singlePrompt = newPrompt;
}
