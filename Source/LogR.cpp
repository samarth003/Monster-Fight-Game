#include <iostream>
#include <string>
#include "..\Header\LogR.h"

void LogR::ErrorLog(LogErr error)
{
    std::string ErrorMessage = ""; 
    switch(error)
    {
        case ERR_NO_EN_BA:  
            ErrorMessage = "No energy for BA";
            break;
        case ERR_NO_EN_CHA:
            ErrorMessage = "No energy for CHA";
            break;
        case ERR_MAX_EN:
            ErrorMessage = "At Max Energy already ";
            break;
        case ERR_NONE:
            ErrorMessage = "No error detected ";
            break;
        default:
            ErrorMessage = "Unidentified occurence";
            break;
    }
    printError(error, ErrorMessage);
}

void LogR::printMsg(const std::string& message, LogStat stat, std::optional<int> statValue)
{
    if(statValue.has_value())
    {
        if(stat == DAMAGE)
            std::cout << message << " took " << *statValue << " damage" << std::endl;
        else
            std::cout << message << " has " << *statValue << " HP" << std::endl;
    }
    else
        std::cout << message << std::endl;
}

void LogR::printError(LogErr errorNo, const std::string& message)
{
    std::cout << "[E" << errorNo << "]: "  << message << std::endl;
}