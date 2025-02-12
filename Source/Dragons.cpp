#include<iostream>
#include<string>

#include "..\Header\Dragons.h"

Dragons::Dragons(MonType type, const std::string& name)
        : Monsters(type, name, BA_DMG, CHA_DMG, BASE_EN) 
        {

        }

int Dragons::GetMinEnergyRequired() {return MIN_EN; }
int Dragons::GetDissipatedEnergyBA() {return BA_REQ_EN; }
int Dragons::GetRequiredCHAEnergy() {return CHA_REQ_EN; }
int Dragons::GetEnergyUsedCHA() {return CHA_USED_EN; }
int Dragons::GetMaxEnergy() {return MAX_EN; }
int Dragons::GetRevitEnergy() {return REVIT_EN; }