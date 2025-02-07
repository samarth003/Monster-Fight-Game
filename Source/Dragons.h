#pragma once

#include <iostream>

#include "Monsters.h"
#include "LogR.h"

class Dragons : public Monsters, LogR
{
public:
    Dragons(MonType type, const std::string& name);

    enum Energy
    {
        MIN_EN = 15,                    //Minimum Energy required for any move to take place
        BA_REQ_EN = 15,                 //Minimum Energy required for Basic attack 
        REVIT_EN = 25,                  //Energy to be revitalized when in defensive state
        CHA_USED_EN = 60,               //Energy used when using charged attack
        CHA_REQ_EN = 75,                //Energy required to use charged attack
        MAX_EN = 100                    //Maximum energy 
    };

    int GetBaseHP();
    int GetEnergyLeft();

    /**MOVESETS FOR DRAGON
     * Basic Attack
     * - DMG dealt 30
     * - ENERGY USED 15 (minimum energy needed for BA)
     */
    int MonBasicAttack() override;

     /* Charged Attack
     * - DMG dealt 100
     * - ENERGY needed 75 (Min energy needed for CHA)
     * - ENERGY USED 60
     */
    int MonChargedAttack() override;

     /* Defensive Shield
     * - DMG dealt 0
     * - ENERGY Revitalized 25 
     */
    int MonDefensiveShield() override;

    /**Damage taken
     * - Get DMG stats BA or CHA to calculate
     * - left over health 
     * - Returns m_MonHP 
     */
    int MonDamageTaken(int DmgReceived) override;
    
private:
    const int m_BADmg {};
    const int m_CHADmg {};
    int m_EnergyLeft {};
};