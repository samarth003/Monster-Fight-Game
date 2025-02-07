#include <iostream>

#include "Dragons.h"


int main()
{
    int MonHealth {};
    int DmgStat {0};
    const std::string MonName = "Gecko"; 
    Dragons Dragon(Monsters::Three_Headed_Dragon, MonName); 

    MonHealth = Dragon.GetBaseHP();
    std::cout << MonName << " has " << MonHealth << " HP Left" << std::endl;

    DmgStat = Dragon.MonBasicAttack();
    DmgStat = Dragon.MonChargedAttack();
    if(DmgStat > 0)
        MonHealth = Dragon.MonDamageTaken(DmgStat);
    std::cout << MonName << " has " << MonHealth << " HP Left" << std::endl;
    return 0;
}