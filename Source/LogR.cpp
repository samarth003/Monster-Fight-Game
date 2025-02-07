#include <iostream>
#include <string>
#include "LogR.h"

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
        case ERR_NONE:
            ErrorMessage = "No error detected ";
        default:
            ErrorMessage = "Unidentified occurence";
            break;
    }
    printError(error, ErrorMessage);
}

void LogR::printError(LogErr errorNo, const std::string& message)
{
    std::cout << "[E" << errorNo << "]: "  << message << std::endl;
}