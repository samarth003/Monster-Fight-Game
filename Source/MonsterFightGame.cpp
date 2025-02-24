#include <iostream>
#include <vector>
#include<cstdlib>
#include <bits/stdc++.h>

#include "MonsterFightGame.h"
#include "Dragons.h"
#include "Spiders.h"

#define MAX_RETRIES 3
#define MOVESET 3

void ExitBattle(std::vector<Monsters*>& roster)
{
    for(Monsters* monster : roster)
        delete monster;
    std::exit(EXIT_SUCCESS);
}

void MonBattle(Monsters& Mon1, Monsters& Mon2, bool& PlayBot)
{
    int MoveNo {0};
    int AttackDmg {0};
    int BattleTurn = 1;

    LogR Logger; 
    Logger.printMsg("|=======================================|");
    Logger.printMsg("           BATTLE NIGHT                  ");
    Logger.printMsg("              " + Mon1.GetMonName()       );
    Logger.printMsg("                V/S                      ");
    Logger.printMsg("              " + Mon2.GetMonName()       );
    Logger.printMsg("|=======================================|");    

    while(!Mon1.IsDefeated() && !Mon2.IsDefeated())
    {
        Monsters& Attacker = (BattleTurn % 2 == 1)? Mon1 : Mon2;
        Monsters& Defender = (BattleTurn % 2 == 1)? Mon2 : Mon1;
        
        Logger.printMsg(Attacker.GetMonName(), Logger.HEALTH ,Attacker.GetMonHPLeft());
        Logger.printMsg(Defender.GetMonName(), Logger.HEALTH ,Defender.GetMonHPLeft());    

        if(PlayBot && (BattleTurn%2 == 0))
        {
            Logger.printMsg("Bot counters with ");
            MoveNo = rand() % MOVESET + 1;
            std::cout << MoveNo << std::endl; 
        }
        else
        {
            Logger.printMsg("What moveset you want to use?\
                            (1) BA, (2) CHA or (3) Regen"); 
            std::cin >> MoveNo;
        }

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

void MonSelection(std::vector<Monsters*>& roster, Monsters*& Mon1, Monsters*& Mon2, bool& PlayBot)
{
    //Select monsters
    int choice1 = 1;
    int choice2 = 1;
    int retry_selection = 3;
    std::string BattleBot {"N"};
    LogR logger;

    logger.printMsg("Battle against Computer [Y/N] ?");
    std::cin >> BattleBot;
    std::transform(BattleBot.begin(), BattleBot.end(), BattleBot.begin(), ::toupper);

    if(BattleBot == "Y")
        PlayBot = true;

    logger.printMsg("Select Monsters for Battle");
    
    for(size_t i=0; i<roster.size(); i++)
    {
        std::cout << "[Mon ID: " << i+1  << "] " << roster[i]->GetMonName() << std::endl;
    }

    do
    {
        logger.printMsg("Select your Monster as Champion. (Provide associated ID)");
        std::cin >> choice1;
        if(PlayBot)
        { 
            choice2 = rand() % roster.size() + 1; //range from 1 to MAX_MONSTERS
            logger.printMsg("Bot's Champion");
            std::cout << choice2 <<std::endl;
        }
        else
        {
            logger.printMsg("Select Opponent's Champion. (Provide associated ID)");
            std::cin >> choice2;
        }

        if((choice1>0 && choice1<=roster.size()) && choice2>0 && choice2<=roster.size())
            break;
        else
        {
            logger.printMsg("Provide a valid ID associated with Monster");
            retry_selection--;
        }
    } while (retry_selection>0);

    if(retry_selection <= 0)
    {
        logger.ErrorLog(logger.ERR_APP_EXIT);
#ifndef UNIT_TEST        
        ExitBattle(roster);
#endif        
    }

    Mon1 = roster[choice1-1];
    Mon2 = roster[choice2-1];
}

void CreateRoster(std::vector<Monsters*>& roster)
{
    LogR logger;
    //Create a vector database for all monsters here 
    if(roster.size() <= 0)
    {
        roster.push_back(new Spiders(Monsters::Giant_Spider, "Shelob"));
        roster.push_back(new Spiders(Monsters::Giant_Spider, "Ungoliant"));
        roster.push_back(new Spiders(Monsters::Giant_Spider, "Deathsting"));  

        roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "Gecko"));
        roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "Smaug"));
        roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "Glaurung"));

    }
    else
        logger.printMsg("Roster already created");
}

#ifndef UNIT_TEST
int main()
{
    int MonHealth {};
    int DmgStat {0};
    bool PlayAgainstBot {false};

    std::vector<Monsters*> roster; 
    Monsters* Monster1;
    Monsters* Monsters2;

    CreateRoster(roster);

    MonSelection(roster, Monster1, Monsters2, PlayAgainstBot);

    MonBattle(*Monster1, *Monsters2, PlayAgainstBot);

    //Exit battle
    ExitBattle(roster);

    return 0;
}
#endif