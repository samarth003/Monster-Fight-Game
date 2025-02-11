#pragma once

#include<iostream>

class LogR
{
public:
    enum LogErr
    {
        ERR_NONE=400,
        ERR_NO_EN_BA,
        ERR_NO_EN_CHA,
        ERR_MAX_EN
    };

    void ErrorLog(LogErr error);
    void printMsg(const std::string& message);
private:
    static void printError(LogErr error, const std::string& message);
};