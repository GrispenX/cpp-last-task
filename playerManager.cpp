#include "playerManager.h"
#include <iostream> 

uint16_t PlayerManager::genId() {return next_id++;}

Player* PlayerManager::CreatePlayer(std::string name)
{
    playerList.push_back(Player(genId(), name));
    return &playerList.back();
}

bool PlayerManager::DeletePlayer(uint16_t id)
{
    for(int i = 0; i < playerList.size(); i++)
    {
        if(playerList[i].getId() == id)
        {
            playerList.erase(playerList.begin() + i);
            return true;
        }
    }
    return false;
}

Player* PlayerManager::getPlayerById(uint16_t id)
{
    for(int i = 0; i < playerList.size(); i++)
    {
        if(playerList[i].getId() == id)
        {
            return &playerList[i];
        }
    }
    return 0;
}
Player* PlayerManager::getPlayerByName(std::string name)
{
    for(int i = 0; i < playerList.size(); i++)
    {
        if(playerList[i].getName() == name)
        {
            return &playerList[i];
        }
    }
    return 0;
}
void PlayerManager::showPlayerInfo(uint16_t id)
{
    Player* player = getPlayerById(id);
    if(player)
    {
        std::cout << "==========";
        std::cout << "\nName: " << player->getName();
        std::cout << "\nId: " << player->getId();
        std::cout << "\nRank: " << player->getRank();
        std::cout << "\n==========";
        return;
    }
    std::cout << "Player with id " << id << " not found!\n";
}