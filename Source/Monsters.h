#pragma once

#include<iostream>
#include "LogR.h"

class Monsters : public LogR 
{
public:
    enum MonType
    {
        Giant_Spider=0,
        Three_Headed_Dragon,
        Fire_Winged_Ogre,
        Sticky_Slime,
        One_Horned_Kraken
    };

    Monsters(MonType type, const std::string& name, int basicAtkDmg, int chargedAtkDmg, int initialEnergy);

    /**
     * Assigns Base HP for all monsters 
     */
    static int MonBaseHealth(MonType type)
    {
        switch(type)
        {
            case Giant_Spider:              return 300;
            case Three_Headed_Dragon:       return 500;
            case Fire_Winged_Ogre:          return 250;
            case Sticky_Slime:              return 250;
            case One_Horned_Kraken:         return 400;
            default:                        return 100;
        }
    }

    /**Basic Attack
     * - Check for Minimum Energy requirement for the move
     * - Once move is performed, substract energy used for the move
     * - If energy requirement not met, print error log and return -1
     * - Otherwise, return attack damage dealt
     *  */   
    int MonBasicAttack();

    /**Charged Attack
     * - Check for Minimum Energy requirement for the move
     * - Once move is performed, substract energy used for the move
     * - If energy requirement not met, print error log and return -1
     * - Otherwise, return attack damage dealt
     *  */    
    int MonChargedAttack();

    /**Shield and Regen
     * - Check if Max energy is already achieved
     * - If not, revitalize the monster with the difference and return 0
     * - Otherwise, print error log and return -1
     *  */
    int MonDefensiveShield();

    /**Damage Taken
     * - Update monster HP with damage received 
     * - If Damage received > HP left, then make HP 0 
     */
    void MonDamageTaken(int DmgReceived);

    /**Check for Defeat
     * - If Mon HP is <= 0, return true
     * - Otherwise, false
     */
    bool IsDefeated();

    int GetBaseHP();
    int GetMonHPLeft();  
    std::string& GetMonName();

    virtual int GetMinEnergyRequired() = 0;
    virtual int GetDissipatedEnergyBA() = 0;
    virtual int GetRequiredCHAEnergy() = 0;
    virtual int GetEnergyUsedCHA() = 0;
    virtual int GetMaxEnergy() = 0;
    virtual int GetRevitEnergy() = 0;

protected:
    MonType m_MonsterType {};               //Monster Type
    std::string m_MonsterName {};           //Name of Monster
    int m_MonBaseHP  {};                    //Base HP 
    int m_MonHP {};                         //HP left after receiving Damage

    int m_BADmg {};                         //Basic Attack Damage
    int m_CHADmg {};                        //Charged Attack Damage
    int m_EnergyLeft {};                    //Energy Left for the move 
};