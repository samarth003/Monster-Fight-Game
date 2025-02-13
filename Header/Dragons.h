#pragma once

#include <iostream>

#include "Monsters.h"

class Dragons : public Monsters
{
public:
    Dragons(MonType type, const std::string& name);
    ~Dragons(){};

    enum Energy
    {
        MIN_EN = 15,                    //Minimum Energy required for any move to take place
        BASE_EN = 30,
        BA_REQ_EN = 15,                 //Minimum Energy required for Basic attack
        REVIT_EN = 25,                  //Energy to be revitalized when in defensive state
        CHA_USED_EN = 60,               //Energy used when using charged attack
        CHA_REQ_EN = 75,                //Energy required to use charged attack
        MAX_EN = 100                    //Maximum energy 
    };

    enum DmgStat
    {
        BA_DMG = 30,
        CHA_DMG = 100
    };

    int GetMinEnergyRequired() override;
    int GetDissipatedEnergyBA() override;
    int GetRequiredCHAEnergy() override;
    int GetEnergyUsedCHA() override;
    int GetMaxEnergy() override;
    int GetRevitEnergy() override;
};