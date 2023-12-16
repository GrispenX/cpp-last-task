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
    Player CreatePlayer(std::string name);
    bool DeletePlayer(uint16_t id);

    std::optional<Player> getPlayerById(uint16_t id);
    std::optional<Player> getPlayerByName(std::string name);
    void showPlayerInfo(Player* player);
};