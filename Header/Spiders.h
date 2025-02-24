#pragma once

#include <iostream>

#include "Monsters.h"

class Spiders : public Monsters
{
public:
    Spiders(MonType type, const std::string& name);
    ~Spiders(){};

    enum Energy
    {
        MIN_EN = 10,                    //Minimum Energy required for any move to take place
        BASE_EN = 20,
        BA_REQ_EN = 10,                 //Minimum Energy required for Basic attack
        REVIT_EN = 20,                  //Energy to be revitalized when in defensive state
        CHA_USED_EN = 45,               //Energy used when using charged attack
        CHA_REQ_EN = 60,                //Energy required to use charged attack
        MAX_EN = 100                    //Maximum energy 
    };

    enum DmgStat
    {
        BA_DMG = 20,
        CHA_DMG = 70
    };

    int GetMinEnergyRequired() override;
    int GetDissipatedEnergyBA() override;
    int GetRequiredCHAEnergy() override;
    int GetEnergyUsedCHA() override;
    int GetMaxEnergy() override;
    int GetRevitEnergy() override;
};