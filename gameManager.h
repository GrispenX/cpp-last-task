#ifndef GAME_MANAGER
#define GAME_MANAGER

#include "session.h"
#include <vector>

class GameManager
{
private:
    std::vector<Session> sessionList;
public:
    void PerformGameSession(Team team1, Team team2, PlayerManager& pmanager);
    Session getSessionList(uint64_t index);
};

#endif