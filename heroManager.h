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
    Hero CreateHero(std::string name, uint16_t hp, uint16_t damage);
    bool DeleteHero(uint16_t id);

    std::optional<Hero> getHeroById(uint16_t id);
    std::optional<Hero> getHeroByName(std::string name);
    void showHeroInfo(Hero* hero);
};