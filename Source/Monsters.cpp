#include<iostream>

class Monsters
{
public:
    enum MonType
    {
        Giant_Spider=0,
        Three_Headed_Dragon,
        Fire_Winged_Ogre,
        Sticky_Slime,
        One_Horned_Kraken
    };


    Monsters(MonType type, const std::string& name)
    {
        m_MonsterType = type;
        m_MonsterName = name;
    }

    std::string GetMonType() const
    {
        switch(m_MonsterType)
        {
            case Giant_Spider:
                return "Giant Spider";
            case Three_Headed_Dragon:
                return "3 Headed Dragon";
            case Fire_Winged_Ogre:
                return "Fire Winged Ogre";
            case Sticky_Slime:
                return "Sticky Slime";
            case One_Horned_Kraken:
                return "1 Horned Kraken";
            default:
                return "Unidentified Monster";
        }
    }

private:
    MonType m_MonsterType {};
    std::string m_MonsterName {};

};

int main()
{
    Monsters Slime(Monsters::Sticky_Slime, "Slimy Chicken");
    std::cout<< "Monster Type is: " << Slime.GetMonType() <<std::endl;
    return 0;
}