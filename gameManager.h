#ifndef GAME_MANAGER
#define GAME_MANAGER

#include "session.h"
#include <list>

class GameManager
{
private:
    std::list<Session> sessionList;
public:
    void PerformGameSession(Team team1, Team team2, PlayerManager& pmanager);
    Session& getSessionList();
};

#endif