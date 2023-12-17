#ifndef TEAM
#define TEAM

#include "playerManager.h"
#include "heroManager.h"
#include <optional>

#define TEAM_SIZE 5

class Team
{
private:
    std::string m_name;
    std::optional<std::pair<Player, Hero>> team[TEAM_SIZE];
public:
    Team() = delete;
    Team(std::string name);

    bool addPlayer(Player player, Hero hero);
    bool removePlayer(uint16_t id);
    std::optional<std::pair<Player, Hero>> getPlayerByIndex(int index);
};

#endif