#ifndef PLAYER_MANAGER
#define PLAYER_MANAGER

#include "player.h"
#include <vector>
#include <optional>

class PlayerManager
{
private:
    std::vector<Player> playerList;
    uint16_t next_id = 0;
    uint16_t genId();
public:
    Player& CreatePlayer(std::string name);
    bool DeletePlayer(uint16_t id);

    Player& getPlayerById(uint16_t id);
    Player& getPlayerByName(std::string name);
    Player& getPlayerByIndex(uint64_t index);
    uint64_t getListSize();
    void showPlayerInfo(Player player);
};

#endif