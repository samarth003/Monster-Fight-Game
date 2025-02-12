#include <iostream>

#include "Dragons.h"


void MonBattle(Monsters& Mon1, Monsters& Mon2)
{
    int MoveNo {0};
    int AttackDmg {0};
    int BattleTurn = 1;

    LogR Logger; 

    while(!Mon1.IsDefeated() && !Mon2.IsDefeated())
    {
        Monsters& Attacker = (BattleTurn % 2 == 1)? Mon1 : Mon2;
        Monsters& Defender = (BattleTurn % 2 == 1)? Mon2 : Mon1;
        
        Logger.printMsg(Attacker.GetMonName(), Logger.HEALTH ,Attacker.GetMonHPLeft());
        Logger.printMsg(Defender.GetMonName(), Logger.HEALTH ,Defender.GetMonHPLeft());    

        Logger.printMsg("What moveset you want to use?\
                        (1) BA, (2) CHA or (3) Regen"); 
        std::cin >> MoveNo;

        if(MoveNo == 1)
            AttackDmg = Attacker.MonBasicAttack(); 
        else if(MoveNo == 2)
            AttackDmg = Attacker.MonChargedAttack();
        else if(MoveNo == 3)
            AttackDmg = Attacker.MonDefensiveShield();
        else
            Logger.printMsg("No moveset selected");

        if(AttackDmg <= 0)
            AttackDmg = 0; 
        Defender.MonDamageTaken(AttackDmg); 

        BattleTurn++;
    }
    std::cout << "Fight Over! Winner: "
              << (Mon1.IsDefeated() ? Mon2.GetMonName() : Mon1.GetMonName()) << std::endl;
}

int main()
{
    int MonHealth {};
    int DmgStat {0};

    Dragons Dragon(Monsters::Three_Headed_Dragon, "Gecko"); 
    Dragons DragonKing(Monsters::Three_Headed_Dragon, "Smaug");

    MonBattle(Dragon, DragonKing);

    return 0;
}