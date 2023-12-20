#include "heroManager.h"
#include <iostream>

uint16_t HeroManager::genId() {return next_id++;}

Hero& HeroManager::CreateHero(std::string name, uint16_t hp, uint16_t damage)
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

Hero& HeroManager::getHeroById(uint16_t id)
{
    for(long unsigned int i = 0; i < heroList.size(); i++)
    {
        if(heroList[i].getId() == id)
        {
            return heroList[i];
        }
    }
    throw std::runtime_error("Hero with id " + std::to_string(id) + " not found");
}
Hero& HeroManager::getHeroByName(std::string name)
{
    for(long unsigned int i = 0; i < heroList.size(); i++)
    {
        if(heroList[i].getName() == name)
        {
            return heroList[i];
        }
    }
    throw std::runtime_error("Hero with name " + name + " not found");
}
Hero& HeroManager::getHeroByIndex(uint64_t index)
{
    if(index < heroList.size())
    {
        return heroList[index];
    }
    throw std::runtime_error("Hero by index " + std::to_string(index) + " not found");
}
uint64_t HeroManager::getListSize() {return heroList.size();}

void HeroManager::showHeroInfo(Hero hero)
{
    std::cout << "===HERO===" << std::endl;
    std::cout << "Name: " << hero.getName() << std::endl;
    std::cout << "Id: " << hero.getId() << std::endl;
    std::cout << "HP: " << hero.getHp() << std::endl;
    std::cout << "Damage: " << hero.getDamage() << std::endl;
    std::cout << "==========" << std::endl;
}