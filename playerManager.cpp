#include "playerManager.h"
#include <iostream> 

uint16_t PlayerManager::genId() {return next_id++;}

Player& PlayerManager::CreatePlayer(std::string name)
{
    playerList.push_back(Player(genId(), name));
    return playerList.back();
}

bool PlayerManager::DeletePlayer(uint16_t id)
{
    for(long unsigned int i = 0; i < playerList.size(); i++)
    {
        if(playerList[i].getId() == id)
        {
            playerList.erase(playerList.begin() + i);
            return true;
        }
    }
    return false;
}

Player& PlayerManager::getPlayerById(uint16_t id)
{
    for(long unsigned int i = 0; i < playerList.size(); i++)
    {
        if(playerList[i].getId() == id)
        {
            return playerList[i];
        }
    }
    throw std::runtime_error("Player with id " + std::to_string(id) + " not found");
}
Player& PlayerManager::getPlayerByName(std::string name)
{
    for(long unsigned int i = 0; i < playerList.size(); i++)
    {
        if(playerList[i].getName() == name)
        {
            return playerList[i];
        }
    }
    throw std::runtime_error("Player with name " + name + " not found");
}
void PlayerManager::showPlayerInfo(Player player)
{
    std::cout << "==PLAYER==";
    std::cout << "\nName: " << player.getName();
    std::cout << "\nId: " << player.getId();
    std::cout << "\nRank: " << player.getRank();
    std::cout << "\n==========\n";
}