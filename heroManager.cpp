#include "heroManager.h"

uint16_t HeroManager::genId() {return next_id++;}

Hero* HeroManager::CreateHero(std::string name, uint16_t hp, uint16_t damage)
{
    heroList.push_back(Hero(genId(), name, hp, damage));
    return &heroList.back();
}
bool HeroManager::DeleteHero(uint16_t id)
{
    for(int i = 0; i < heroList.size(); i++)
    {
        if(heroList[i].getId() == id)
        {
            heroList.erase(heroList.begin() + i);
            return true;
        }
    }
    return false;
}

Hero* HeroManager::getHeroById(uint16_t id)
{
    for(int i = 0; i < heroList.size(); i++)
    {
        if(heroList[i].getId() == id)
        {
            return &heroList[i];
        }
    }
    return 0;
}
Hero* HeroManager::getHeroByName(std::string name)
{
    for(int i = 0; i < heroList.size(); i++)
    {
        if(heroList[i].getName() == name)
        {
            return &heroList[i];
        }
    }
    return 0;
}