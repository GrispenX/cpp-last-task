#ifndef GAME_MANAGER
#define GAME_MANAGER

#include "session.h"
#include <vector>

class GameManager
{
private:
    std::vector<Session> sessionList;
    PlayerManager m_pmanager;
    HeroManager m_hmanager;
    TeamManager m_tmanager;
public:
    GameManager(PlayerManager pmanager);
    GameManager(HeroManager hmanager);
    GameManager(PlayerManager pmanager, HeroManager hmanager);

    PlayerManager& getPManager();
    HeroManager& getHManager();
    // TeamManager& getTManager();

    void PerformGameSession();
    Session getSessionByIndex(uint64_t index);
};

#endif