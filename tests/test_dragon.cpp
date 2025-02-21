#include<gtest/gtest.h>
#include "Dragons.h"

class DragonTest : public ::testing::Test
{
protected:
    Dragons Drogon;

    DragonTest()
    :Drogon(Monsters::Three_Headed_Dragon, "Toothless")
    {

    }
};

TEST_F(DragonTest, DragonTest_MonName_Test)
{
    EXPECT_EQ(Drogon.GetMonName(), std::string("Toothless"));
}

TEST_F(DragonTest, DragonTest_BasicAtkDamage_Test)
{
    EXPECT_GT(Drogon.MonBasicAttack(), 0);
}

TEST_F(DragonTest, DragonTest_FailedChargedAttack_Test)
{
    EXPECT_LT(Drogon.MonChargedAttack(), 0);
}

TEST_F(DragonTest, DragonTest_DamageTaken_Test)
{
    int dmg {50};
    int hp = Drogon.GetMonHPLeft();
    Drogon.MonDamageTaken(dmg);
    EXPECT_EQ(Drogon.GetMonHPLeft(), (hp-dmg));
}

TEST_F(DragonTest, DragonTest_ShieldRegen_Test)
{
    EXPECT_EQ(Drogon.MonDefensiveShield(), 0);
}