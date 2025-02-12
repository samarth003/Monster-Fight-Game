#include<iostream>

#include "..\Header\Monsters.h"

Monsters:: Monsters(MonType type, const std::string& name, int basicAtkDmg, int chargedAtkDmg, int initialEnergy)
            :m_MonsterType {type}, m_MonsterName {name}, m_BADmg {basicAtkDmg}
            ,m_CHADmg {chargedAtkDmg}, m_EnergyLeft {initialEnergy}
            ,m_MonBaseHP {MonBaseHealth(type)}, m_MonHP {m_MonBaseHP}
            {

            }

int Monsters::GetBaseHP() {return m_MonBaseHP;}
int Monsters::GetMonHPLeft() {return m_MonHP; }        
std::string& Monsters::GetMonName() { return m_MonsterName; }


bool Monsters::IsDefeated()
{
    if(m_MonHP <=0)
        return true;
    return false;
}

int Monsters::MonBasicAttack()
{
    if(m_EnergyLeft >= GetMinEnergyRequired())
        m_EnergyLeft -= GetDissipatedEnergyBA();
    else
    {
        ErrorLog(ERR_NO_EN_BA);
        return -1; 
    }

    return m_BADmg;        
}

int Monsters::MonChargedAttack()
{
    if(m_EnergyLeft >= GetRequiredCHAEnergy())
        m_EnergyLeft -= GetEnergyUsedCHA();
    else
    {
        ErrorLog(ERR_NO_EN_CHA); 
        return -1;
    }

    return m_CHADmg;        
}

int Monsters::MonDefensiveShield()
{
    int Max_Energy = GetMaxEnergy();
    int EnergyRevitalized = GetRevitEnergy();

    if(m_EnergyLeft < Max_Energy)
    {
        if((Max_Energy - m_EnergyLeft) >= EnergyRevitalized)
            m_EnergyLeft += EnergyRevitalized;
        else if((Max_Energy - m_EnergyLeft) < EnergyRevitalized)
            m_EnergyLeft += (Max_Energy - m_EnergyLeft);
    }
    else
    {
        ErrorLog(ERR_MAX_EN);
        return -1;
    }
    return 0;
}

void Monsters::MonDamageTaken(int DmgReceived)
{   
    if((m_MonHP - DmgReceived) <= 0)
        m_MonHP = 0;
    else
        m_MonHP -= DmgReceived;
    printMsg(m_MonsterName, LogStat::DAMAGE, DmgReceived);
}