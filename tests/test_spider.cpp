#include<gtest/gtest.h>
#include "Spiders.h"

class SpiderTest : public ::testing::Test
{
protected:
    Spiders Spidey;

    SpiderTest()
    :Spidey(Monsters::Three_Headed_Dragon, "TickleClaw")
    {

    }
};

TEST_F(SpiderTest, SpiderTest_MonName_Test)
{
    EXPECT_EQ(Spidey.GetMonName(), std::string("TickleClaw"));
}

TEST_F(SpiderTest, SpiderTest_BasicAtkDamage_Test)
{
    EXPECT_GT(Spidey.MonBasicAttack(), 0);
}

TEST_F(SpiderTest, SpiderTest_FailedChargedAttack_Test)
{
    EXPECT_LT(Spidey.MonChargedAttack(), 0);
}

TEST_F(SpiderTest, SpiderTest_DamageTaken_Test)
{
    int dmg {50};
    int hp = Spidey.GetMonHPLeft();
    Spidey.MonDamageTaken(dmg);
    EXPECT_EQ(Spidey.GetMonHPLeft(), (hp-dmg));
}

TEST_F(SpiderTest, SpiderTest_ShieldRegen_Test)
{
    EXPECT_EQ(Spidey.MonDefensiveShield(), 0);
}