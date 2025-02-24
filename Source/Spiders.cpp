#include<iostream>
#include<string>

#include "Spiders.h"

Spiders::Spiders(MonType type, const std::string& name)
        : Monsters(type, name, BA_DMG, CHA_DMG, BASE_EN) 
        {

        }

int Spiders::GetMinEnergyRequired() {return MIN_EN; }
int Spiders::GetDissipatedEnergyBA() {return BA_REQ_EN; }
int Spiders::GetRequiredCHAEnergy() {return CHA_REQ_EN; }
int Spiders::GetEnergyUsedCHA() {return CHA_USED_EN; }
int Spiders::GetMaxEnergy() {return MAX_EN; }
int Spiders::GetRevitEnergy() {return REVIT_EN; }