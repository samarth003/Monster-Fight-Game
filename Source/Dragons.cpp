#include<iostream>
#include<string>

#include "Monsters.h"

class Dragons : public Monsters
{
public:
    Dragons(MonType type, const std::string& name)
    : Monsters(type, name) {}

    int GetBaseHP() { return m_MonBaseHP; }

    /**MOVESETS FOR DRAGON
     * Basic Attack
     * - DMG dealt 30
     * - ENERGY USED 15
     */
    int MonBasicAttack() override
    {
        return 0;
    }

     /* Charged Attack
     * - DMG dealt 100
     * - ENERGY needed 75
     * - ENERGY USED 60
     */
    int MonChargedAttack() override
    {
        return 0;
    }

     /* Defensive Shield
     * - DMG dealt 0
     * - ENERGY Revitalized 25 
     */
    void MonDefensiveShield() override
    {

    }
    
private:
    int m_HPLeft {};
};

int main()
{
    int MonHealth {};
    const std::string MonName = "Gecko"; 
    Dragons Dragon(Monsters::Three_Headed_Dragon, MonName); 

    MonHealth = Dragon.GetBaseHP();
    std::cout << MonName << " has " << MonHealth << " HP Left" << std::endl;
}