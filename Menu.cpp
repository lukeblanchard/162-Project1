/****************************************************************************
 ** Author: Lucas Blanchard
 ** Date: January 10, 2018
 ** Description: Menu class implementation
 ****************************************************************************/
#include "Menu.hpp"
#include <sstream>
#include <string> 
#include <vector> 
#include <iterator> 
#include <cctype> 

void Menu::getAllResponses(menuIntIO menuInt)
{
    for(menuIntIO::iterator itr = intResponses.begin(); itr != intResponses.end(); ++itr)    
    {
        std::cout << itr->first; 
        *(itr->second) = getIntegerResponse(); 
    }
}

void Menu::getAllResponses(menuIntIO menuInt, int low, int high, int offset)
{
    for(menuIntIO::iterator itr = intResponses.begin(); itr != intResponses.end(); ++itr)    
    {
        std::cout << itr->first; 
        *(itr->second) = getIntegerResponse(low, high, offset); 
    }
}

void Menu::getAllResponses(menuStringIO menuString)
{
    for(menuStringIO::iterator itr = stringResponses.begin(); itr != stringResponses.end(); ++itr)    
    {
        std::cout << itr->first; 
        getline(std::cin,*(itr->second));
    }
}

void Menu::getAllResponses(menuBoolIO menuBool)
{
    for(menuBoolIO::iterator itr = boolResponses.begin(); itr != boolResponses.end(); ++itr)    
    {
        std::cout << itr->first; 
        *(itr->second) = getBoolResponse(); 
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

int Menu::getIntegerResponse(int low, int high, int offset)
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
        std::cout << "Please enter a valid choice from " << low << "-" << high << ": "; 
        std::getline(std::cin, strResponse);
        invalid = checkInt(strResponse); 
        if(!invalid)
        {
            std::istringstream istr(strResponse);
            istr >> response;   
            invalid = response < low || response > high;
        }
    }
    return response + offset;
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

bool Menu::getBoolResponse()
{
    std::string strResponse;
    bool invalid;

    std::getline(std::cin, strResponse);
    invalid = checkBool(&strResponse); 

    while(invalid) 
    {
        std::cout << "Please enter 'y' or 'n': ";  
        std::getline(std::cin, strResponse);
        invalid = checkBool(&strResponse); 
    }
    if(strResponse == "NO" || strResponse == "N")
        return false; 
    else
        return true;
}

bool Menu::checkBool(std::string *resp) 
{
    for(std::string::iterator it = resp->begin(); it != resp->end(); ++it)
    {
        *it = toupper(*it); 
    }
    std::cout << *resp << std::endl; 

    if(*resp != "NO" && *resp != "N" && *resp != "YES" && *resp != "Y")
        return true; 
    else
        return false;
}

void Menu::load(menuIntIO newPAndR)
{
    intResponses = newPAndR;
    getAllResponses(intResponses);  
}

void Menu::load(menuIntIO newPAndR, int low, int high, int offset)
{
    intResponses = newPAndR;
    getAllResponses(intResponses, low, high, offset);  
}

void Menu::load(menuStringIO newPAndR)
{
    stringResponses = newPAndR;
    getAllResponses(stringResponses);
}

void Menu::load(menuBoolIO newPAndR)
{
    boolResponses = newPAndR;
    getAllResponses(boolResponses); 
}

