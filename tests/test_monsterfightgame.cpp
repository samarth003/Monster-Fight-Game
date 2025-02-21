#include<gtest/gtest.h>
#include<gmock/gmock.h>

#include<sstream>
#include<iostream>
#include <vector>

#include "MonsterFightGame.h"
#include "Dragons.h"

class MonsterFightGame : public ::testing::Test
{
protected:
    std::vector<Monsters*> Roster;
    std::string UserInput = " "; 
    Monsters* Mon1 = nullptr; 
    Monsters* Mon2 = nullptr; 
    bool PlayBot = false;
    const int m_MaxRetries = 3;
    const int m_MaxRoster = 3; 

    MonsterFightGame()
    {

    }

    //Run before each test
    void SetUp() override
    {
        Roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "Silo"));
        Roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "Kaos")); 
        Roster.push_back(new Dragons(Monsters::Three_Headed_Dragon, "IronClaw"));         
    }

    //Run after each test
    void TearDown() override
    {
        for(auto monster : Roster)
            delete monster;
    }

    //Simulate monster selection return output to check for error
    std::string SimulateMonSelection(const std::string& UserIn)
    {
        std::stringstream input(UserIn);
        std::streambuf* orig_cin = std::cin.rdbuf(input.rdbuf()); 
    
        std::stringstream OutputBuf;
        std::streambuf* orig_cout = std::cout.rdbuf(OutputBuf.rdbuf());
    
        MonSelection(Roster, Mon1, Mon2, PlayBot);
    
        std::cin.rdbuf(orig_cin); 
        std::cout.rdbuf(orig_cout);
    
        return OutputBuf.str();
    }

};

//Roster Creation
TEST_F(MonsterFightGame, MonsterFightGame_RosterSize_Test)
{
    CreateRoster(Roster);
    EXPECT_EQ(Roster.size(), m_MaxRoster);
}

//No Bot - valid selection
TEST_F(MonsterFightGame, MonsterFightGame_SelectMonsterNoBot_Test)
{
    UserInput = "N\n1\n3\n";
    //user input "N"- No bot, 1-Select Silo, 3-IronClaw 
    SimulateMonSelection(UserInput);

    EXPECT_EQ(Mon1->GetMonName(), "Silo");
    EXPECT_EQ(Mon2->GetMonName(), "IronClaw");
    EXPECT_FALSE(PlayBot);
}

//Bot - valid selection
TEST_F(MonsterFightGame, MonsterFightGame_SelectMonstersBot_Test)
{

    UserInput = "Y\n1\n";
    //user input "Y"- bot, 1-Select Silo
    SimulateMonSelection(UserInput);

    EXPECT_EQ(Mon1->GetMonName(), "Silo");
    EXPECT_TRUE(PlayBot);
}

//No bot - exhaust all retries 
TEST_F(MonsterFightGame, MonsterFightGame_ExhaustRetries_Test)
{

    UserInput = "N\n1\n4\n3\n5\n2\n6\n";
    //user input "N"- No bot, 1-3 are valid inputs, rest invalid
    std::string RetString = SimulateMonSelection(UserInput);  
    
    EXPECT_THAT(RetString, testing::HasSubstr("404"));  
}

//Bot - Exhaust all retries
TEST_F(MonsterFightGame, MonsterFightGame_ExhaustRetriesBot_Test)
{
    UserInput = "Y\n5\n4\n7\n";
    //user input "Y"- bot, 1-3 are valid inputs, rest invalid 
    std::string RetString = SimulateMonSelection(UserInput); 
    
    EXPECT_THAT(RetString, testing::HasSubstr("404"));
}

//No bot - Max Retries limit 
TEST_F(MonsterFightGame, MonsterFightGame_MaxRetries_Test)
{
    UserInput = "N\n1\n4\n3\n5\n2\n1\n";
    //user input "N"- No bot, 1-3 are valid inputs, rest invalid
    std::string RetString = SimulateMonSelection(UserInput);  
    
    EXPECT_THAT(RetString, testing::Not(testing::HasSubstr("404"))); 
}

//Bot - Max retries limit 
TEST_F(MonsterFightGame, MonsterFightGame_MaxRetriesBot_Test)
{
    UserInput = "Y\n4\n5\n3\n";
    //user input "Y"- bot, 1-3 are valid inputs, rest invalid
    std::string RetString = SimulateMonSelection(UserInput);  
    
    EXPECT_THAT(RetString, testing::Not(testing::HasSubstr("404")));
}

