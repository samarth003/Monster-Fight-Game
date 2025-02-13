#include<gtest/gtest.h>
// #include "Dragons.h"

// TEST(DragonTest, BA_Damage)
// {
//     Dragons Dragon(Monsters::Three_Headed_Dragon, "Toothless");
//     EXPECT_GT(Dragon.MonBasicAttack(), 0);
// }

TEST(HelloGTest, BasicAssertion)
{
    EXPECT_STRNE("Hello", "World");
    EXPECT_EQ(7*6, 42);
}