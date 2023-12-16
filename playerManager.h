#include "player.h"
#include <vector>

class PlayerManager
{
private:
    std::vector<Player> playerList;
    uint16_t next_id = 0;
    uint16_t genId();
public:
    Player* CreatePlayer(std::string name);
    bool DeletePlayer(uint16_t id);

    Player* getPlayerById(uint16_t id);
    Player* getPlayerByName(std::string name);
    void showPlayerInfo(Player* player);
};