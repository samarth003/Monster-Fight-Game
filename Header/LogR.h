#pragma once

#include<iostream>
#include<optional>

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

    enum LogStat
    {
        DAMAGE,
        HEALTH
    };

    void ErrorLog(LogErr error);
    void printMsg(const std::string& message, LogStat stat = DAMAGE, std::optional<int> statValue = std::nullopt);
private:
    static void printError(LogErr error, const std::string& message);
};