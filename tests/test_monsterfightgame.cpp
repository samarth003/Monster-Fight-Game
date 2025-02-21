#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include<sstream>
#include<iostream>
#include <vector>

#include "MonsterFightGame.h"
#include "Dragons.h"

TEST(RosterCreation, RosterCreation_RosterSiz_Test)
{
    std::vector<Monsters*> Roster;
    CreateRoster(Roster);

    EXPECT_EQ(Roster.size(), 3); //Roster size check once roster is updated

    for(auto monster : Roster)
        delete monster;
}

TEST(MonsterSelection, MonsterSelection_SelectMonsterNoBot_Test)
{
    std::vector<Monsters*> Roster;
    Monsters* Mon1 = nullptr; 
    Monsters* Mon2 = nullptr;
    bool PlayBot = false;

    Roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "Silo"));
    Roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "Kaos")); 
    Roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "IronClaw")); 

    //user input "N"- No bot, 1-Select Silo, 3-IronClaw 
    std::stringstream input("N\n1\n3\n");
    std::streambuf* orig_cin = std::cin.rdbuf(input.rdbuf()); 

    MonSelection(Roster, Mon1, Mon2, PlayBot);

    EXPECT_EQ(Mon1->GetMonName(), "Silo");
    EXPECT_EQ(Mon2->GetMonName(), "IronClaw");
    EXPECT_EQ(PlayBot, false);

    std::cin.rdbuf(orig_cin);

    for(auto monster : Roster)
        delete monster;
}

TEST(MonsterSelection, MonsterSelection_SelectMonsterBot_Test)
{
    std::vector<Monsters*> Roster;
    Monsters* Mon1 = nullptr; 
    Monsters* Mon2 = nullptr;
    bool PlayBot = false;

    Roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "Silo"));
    Roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "Kaos")); 
    Roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "IronClaw")); 

    //user input "Y"- bot, 1-Select Silo
    std::stringstream input("Y\n1\n");
    std::streambuf* orig_cin = std::cin.rdbuf(input.rdbuf()); 

    MonSelection(Roster, Mon1, Mon2, PlayBot);

    EXPECT_EQ(Mon1->GetMonName(), "Silo");
    EXPECT_EQ(PlayBot, true);

    std::cin.rdbuf(orig_cin);

    for(auto monster : Roster)
        delete monster;
}

TEST(MonsterSelection, MonsterSelection_ExhaustRetries_Test)
{
    std::vector<Monsters*> Roster;
    Monsters* Mon1 = nullptr; 
    Monsters* Mon2 = nullptr;
    bool PlayBot = false;

    Roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "Silo"));
    Roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "Kaos")); 
    Roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "IronClaw")); 

    //user input "N"- No bot, 1-3 are valid inputs, rest invalid  
    std::stringstream input("N\n1\n4\n3\n5\n2\n6\n");
    std::streambuf* orig_cin = std::cin.rdbuf(input.rdbuf()); 

    std::stringstream OutputBuf;
    std::streambuf* orig_cout = std::cout.rdbuf(OutputBuf.rdbuf());

    MonSelection(Roster, Mon1, Mon2, PlayBot);

    std::cin.rdbuf(orig_cin); 
    std::cout.rdbuf(orig_cout);

    std::string RetString = OutputBuf.str();

    
    EXPECT_THAT(RetString, testing::HasSubstr("404"));  

    for(auto monster : Roster)
        delete monster;
}

TEST(MonsterSelection, MonsterSelection_ExhaustRetriesBot_Test)
{
    std::vector<Monsters*> Roster;
    Monsters* Mon1 = nullptr; 
    Monsters* Mon2 = nullptr;
    bool PlayBot = false;

    Roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "Silo"));
    Roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "Kaos")); 
    Roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "IronClaw")); 

    //user input "Y"- bot, 1-3 are valid inputs, rest invalid  
    std::stringstream input("Y\n5\n4\n7\n");
    std::streambuf* orig_cin = std::cin.rdbuf(input.rdbuf()); 

    std::stringstream OutputBuf;
    std::streambuf* orig_cout = std::cout.rdbuf(OutputBuf.rdbuf());

    MonSelection(Roster, Mon1, Mon2, PlayBot);

    std::cin.rdbuf(orig_cin); 
    std::cout.rdbuf(orig_cout);

    std::string RetString = OutputBuf.str();

    
    EXPECT_THAT(RetString, testing::HasSubstr("404"));  

    for(auto monster : Roster)
        delete monster;
}

TEST(MonsterSelection, MonsterSelection_MaxRetries_Test)
{
    std::vector<Monsters*> Roster;
    Monsters* Mon1 = nullptr; 
    Monsters* Mon2 = nullptr;
    bool PlayBot = false;

    Roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "Silo"));
    Roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "Kaos")); 
    Roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "IronClaw")); 

    //user input "N"- No bot, 1-3 are valid inputs, rest invalid  
    std::stringstream input("N\n1\n4\n3\n5\n2\n1\n");
    std::streambuf* orig_cin = std::cin.rdbuf(input.rdbuf()); 

    std::stringstream OutputBuf;
    std::streambuf* orig_cout = std::cout.rdbuf(OutputBuf.rdbuf());

    MonSelection(Roster, Mon1, Mon2, PlayBot);

    std::cin.rdbuf(orig_cin); 
    std::cout.rdbuf(orig_cout);

    std::string RetString = OutputBuf.str();

    
    EXPECT_THAT(RetString, testing::Not(testing::HasSubstr("404")));  

    for(auto monster : Roster)
        delete monster;
}

TEST(MonsterSelection, MonsterSelection_MaxRetriesBot_Test)
{
    std::vector<Monsters*> Roster;
    Monsters* Mon1 = nullptr; 
    Monsters* Mon2 = nullptr;
    bool PlayBot = false;

    Roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "Silo"));
    Roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "Kaos")); 
    Roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "IronClaw")); 

    //user input "Y"- bot, 1-3 are valid inputs, rest invalid  
    std::stringstream input("Y\n4\n5\n3\n");
    std::streambuf* orig_cin = std::cin.rdbuf(input.rdbuf()); 

    std::stringstream OutputBuf;
    std::streambuf* orig_cout = std::cout.rdbuf(OutputBuf.rdbuf());

    MonSelection(Roster, Mon1, Mon2, PlayBot);

    std::cin.rdbuf(orig_cin); 
    std::cout.rdbuf(orig_cout);

    std::string RetString = OutputBuf.str();

    
    EXPECT_THAT(RetString, testing::Not(testing::HasSubstr("404")));  

    for(auto monster : Roster)
        delete monster;
}

