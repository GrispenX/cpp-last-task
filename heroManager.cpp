#include "heroManager.h"
#include <iostream>

uint16_t HeroManager::genId() {return next_id++;}

Hero HeroManager::CreateHero(std::string name, uint16_t hp, uint16_t damage)
{
    heroList.push_back(Hero(genId(), name, hp, damage));
    return heroList.back();
}
bool HeroManager::DeleteHero(uint16_t id)
{
    for(long unsigned int i = 0; i < heroList.size(); i++)
    {
        if(heroList[i].getId() == id)
        {
            heroList.erase(heroList.begin() + i);
            return true;
        }
    }
    return false;
}

std::optional<Hero> HeroManager::getHeroById(uint16_t id)
{
    for(long unsigned int i = 0; i < heroList.size(); i++)
    {
        if(heroList[i].getId() == id)
        {
            return heroList[i];
        }
    }
    return std::nullopt;
}
std::optional<Hero> HeroManager::getHeroByName(std::string name)
{
    for(long unsigned int i = 0; i < heroList.size(); i++)
    {
        if(heroList[i].getName() == name)
        {
            return heroList[i];
        }
    }
    return std::nullopt;
}

void HeroManager::showHeroInfo(Hero* hero)
{
    std::cout << "==========";
    std::cout << "\nName: " << hero->getName();
    std::cout << "\nId: " << hero->getId();
    std::cout << "\nHP: " << hero->getHp();
    std::cout << "\nDamage: " << hero->getDamage();
    std::cout << "\n==========\n";
}