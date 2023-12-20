#ifndef HERO_MANAGER
#define HERO_MANAGER

#include "hero.h"
#include <vector>
#include <optional>

class HeroManager
{
private:
    std::vector<Hero> heroList;
    uint16_t next_id = 0;
    uint16_t genId();
public:
    Hero& CreateHero(std::string name, uint16_t hp, uint16_t damage);
    bool DeleteHero(uint16_t id);

    Hero& getHeroById(uint16_t id);
    Hero& getHeroByName(std::string name);
    Hero& getHeroByIndex(uint64_t index);
    uint64_t getListSize();
    void showHeroInfo(Hero hero);
};

#endif