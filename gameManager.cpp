#include "gameManager.h"
#include <iostream>

void GameManager::PerformGameSession(Team team1, Team team2, PlayerManager& pmanager)
{
    Session session(team1, team2);
    Team* winner = session.claculateWinner();
    if(winner != nullptr)
    {
        Team* looser;
        if(team1.getName() == winner->getName())
        {
            looser = &team2;
        }
        else
        {
            looser = &team1;
        }
        for(int i = 0; i < TEAM_SIZE; i++)
        {
            try
            {
                uint16_t id = winner->getPlayerByIndex(i).first.getId();
                pmanager.getPlayerById(id).changeRank(25);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << std::endl;
            }
            try
            {
                uint16_t id = looser->getPlayerByIndex(i).first.getId();
                pmanager.getPlayerById(id).changeRank(-25);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << std::endl;
            }
            
        }
        std::cout << winner->getName() << " wins!" << std::endl;
    }
    else
    {
        std::cout << "Tie!" << std::endl;
    }
    sessionList.push_back(session);
}

Session GameManager::getSessionList(uint64_t index)
{
    return sessionList[index];
}