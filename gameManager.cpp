#include "gameManager.h"
#include <iostream>

GameManager::GameManager(PlayerManager pmanager) {m_pmanager = pmanager;}
GameManager::GameManager(HeroManager hmanager) {m_hmanager = hmanager;}
GameManager::GameManager(PlayerManager pmanager, HeroManager hmanager)
{
    m_pmanager = pmanager;
    m_hmanager = hmanager;
}


PlayerManager& GameManager::getPManager() {return m_pmanager;}
HeroManager& GameManager::getHManager() {return m_hmanager;}

void GameManager::PerformGameSession()
{
    bool flag = 1;
    m_tmanager.generateNewteam("RED");
    m_tmanager.generateNewteam("BLUE");
    std::vector<uint16_t> pidlist;
    std::vector<uint16_t> hidlist;
    for(uint64_t i = 0; i < m_pmanager.getListSize(); i++)
    {
        pidlist.push_back(m_pmanager.getPlayerByIndex(i).getId());
    }
    for(uint64_t i = 0; i < m_hmanager.getListSize(); i++)
    {
        hidlist.push_back(m_hmanager.getHeroByIndex(i).getId());
    }
    srand(time(NULL));
    for(int i = 0; i < TEAM_SIZE * 2; i++)
    {
        if(!pidlist.empty() && !hidlist.empty())
        {
            int randomPlayer = rand() % pidlist.size();
            int randomHero = rand() % hidlist.size();
            if(flag)
            {
                m_tmanager.getTeamByName("RED").addPlayer(m_pmanager.getPlayerById(pidlist[randomPlayer]), m_hmanager.getHeroById(hidlist[randomHero]));
                flag = 0;
            }
            else
            {
                m_tmanager.getTeamByName("BLUE").addPlayer(m_pmanager.getPlayerById(pidlist[randomPlayer]), m_hmanager.getHeroById(hidlist[randomHero]));
                flag = 1;
            }
            pidlist.erase(pidlist.begin() + randomPlayer);
            hidlist.erase(hidlist.begin() + randomHero);
        }
    }
    sessionList.push_back(Session(m_tmanager.getTeamByName("RED"), m_tmanager.getTeamByName("BLUE")));
    m_tmanager.deleteTeam("RED");
    m_tmanager.deleteTeam("BLUE");
    sessionList.back().claculateWinner();
    m_tmanager.getTeamInfo(sessionList.back().getTeamOne());
    m_tmanager.getTeamInfo(sessionList.back().getTeamTwo());
    if(sessionList.back().getWinner() != nullptr && sessionList.back().getLoser() != nullptr)
    {
        for(int i = 0; i < TEAM_SIZE; i++)
        {
            m_pmanager.getPlayerById(sessionList.back().getWinner()->getPlayerByIndex(i).first.getId()).changeRank(25);
            m_pmanager.getPlayerById(sessionList.back().getLoser()->getPlayerByIndex(i).first.getId()).changeRank(-25);
        }
        std::cout << "Team " << sessionList.back().getWinner()->getName() << " win!" << std::endl;
    }
    else {std::cout << "Tie!";}
}

Session GameManager::getSessionByIndex(uint64_t index)
{
    if(sessionList.size() > index)
    {
        return sessionList[index];
    }
    throw std::runtime_error("There isn't session by index " + std::to_string(index));
}