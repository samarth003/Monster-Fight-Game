#pragma once

#include<iostream>

class Monsters
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


    Monsters(MonType type, const std::string& name)
    :m_MonsterType {type}, m_MonsterName {name}, m_MonBaseHP {MonBaseHealth(type)}{}

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

    /**SIMPLE MOVESETS
     * 1 Basic attack 
     * basic attack will return damage to be dealt and disperse energy used for charged move 
     * 1 Charged attack
     * charged attack will return damage to be dealt once the energy is charged completely. 
     * 1 Defense shield 
     * This will not have damage dealt but will increase the charged energy for moveset
     */
    virtual int MonBasicAttack() = 0; 
    virtual int MonChargedAttack() = 0;
    virtual void MonDefensiveShield() = 0; 

protected:
    MonType m_MonsterType {};
    std::string m_MonsterName {};
    int m_MonBaseHP  {};
};