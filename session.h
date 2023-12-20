#ifndef SESSION
#define SESSION

#include "teamManager.h"
#include <ctime>

class Session
{
private:
    char* m_startTime;
    Team m_teamOne;
    Team m_teamTwo;
    Team* m_winner;
    Team* m_loser;
public:
    Session() = delete;
    Session(Team teamOne, Team teamTwo);

    Team getTeamOne();
    Team getTeamTwo();
    Team* getWinner();
    Team* getLoser();
    void claculateWinner();
};

#endif