#include<gtest/gtest.h>
#include "Dragons.h"

TEST(DragonTest, MonName)
{
    Dragons Drogon(Monsters::Three_Headed_Dragon, "Toothless");
    EXPECT_EQ(Drogon.GetMonName(), std::string("Toothless"));
}

TEST(DragonTest, BasicAtkDamage)
{
    Dragons Drogon(Monsters::Three_Headed_Dragon, "Toothless");
    EXPECT_GT(Drogon.MonBasicAttack(), 0);
}