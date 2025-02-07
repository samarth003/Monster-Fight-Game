#include<iostream>
#include<string>

#include "Dragons.h"

Dragons::Dragons(MonType type, const std::string& name)
        : Monsters(type, name), m_BADmg {30}
        ,m_CHADmg {100}, m_EnergyLeft {30} {}

int Dragons::GetBaseHP() {return m_MonBaseHP;}        
int Dragons::GetEnergyLeft() { return m_EnergyLeft; }

int Dragons::MonBasicAttack()
{
    if(m_EnergyLeft >= MIN_EN)
        m_EnergyLeft -= BA_REQ_EN;
    else
    {
        ErrorLog(ERR_NO_EN_BA);
        return -1; 
    }

    return m_BADmg;    
}

int Dragons::MonChargedAttack()
{
    if(m_EnergyLeft >= CHA_REQ_EN)
        m_EnergyLeft -= CHA_USED_EN;
    else
    {
        ErrorLog(ERR_NO_EN_CHA); 
        return -1;
    }

    return m_CHADmg;    
}

int Dragons::MonDefensiveShield()
{
    if(m_EnergyLeft < MAX_EN)
    {
        if((MAX_EN - m_EnergyLeft) >= REVIT_EN)
            m_EnergyLeft += REVIT_EN;
        else if((MAX_EN - m_EnergyLeft) < REVIT_EN)
            m_EnergyLeft += (MAX_EN - m_EnergyLeft);
    }
    else
    {
        ErrorLog(ERR_MAX_EN);
        return -1;
    }
    return 0;
}

int Dragons::MonDamageTaken(int DmgReceived)
{   
    if((m_MonHP - DmgReceived) <= 0)
        m_MonHP = 0;
    else
        m_MonHP -= DmgReceived;
    return m_MonHP;
}