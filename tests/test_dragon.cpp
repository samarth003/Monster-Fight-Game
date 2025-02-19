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

TEST_F(DragonTest, MonName)
{
    EXPECT_EQ(Drogon.GetMonName(), std::string("Toothless"));
}

TEST_F(DragonTest, BasicAtkDamage)
{
    EXPECT_GT(Drogon.MonBasicAttack(), 0);
}

TEST_F(DragonTest, FailedChargedAtk)
{
    EXPECT_LT(Drogon.MonChargedAttack(), 0);
}

TEST_F(DragonTest, DamageTaken)
{
    int dmg {50};
    int hp = Drogon.GetMonHPLeft();
    Drogon.MonDamageTaken(dmg);
    EXPECT_EQ(Drogon.GetMonHPLeft(), (hp-dmg));
}

TEST_F(DragonTest, ShieldRegen)
{
    EXPECT_EQ(Drogon.MonDefensiveShield(), 0);
}