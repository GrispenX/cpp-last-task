#include "team.h"
#include <iostream>

Team::Team(std::string name) {m_name = name;}

std::string Team::getName() {return m_name;}

bool Team::addPlayer(Player player, Hero hero)
{
    for(int i = 0; i < TEAM_SIZE; i++)
    {
        if(team[i].has_value())
        {
            if(team[i].value().first.getId() == player.getId())
            {
                return false;
            }
        }
    }
    for(int i = 0; i < TEAM_SIZE; i++)
    {
        if(!team[i].has_value())
        {
            team[i] = std::make_pair(player, hero);
            return true;
        }
    }
    return false;
}

bool Team::removePlayerById(uint16_t id)
{
    for(int i = 0; i < TEAM_SIZE; i++)
    {
        if(team[i].has_value())
        {
            if(team[i].value().first.getId() == id)
            {
                team[i].reset();
                return true;
            }
        }
    }
    return false;
}
std::pair<Player, Hero> Team::getPlayerByIndex(int index)
{
    if(team[index].has_value())
    {
        return team[index].value();
    }
    throw std::runtime_error("There isn't player by index " + std::to_string(index));
}

bool Team::removePlayerByIndex(uint16_t index)
{
    if(index < TEAM_SIZE)
    {
        if(team[index].has_value())
        {
            team[index].reset();
            return true;
        }
    }
    return false;
}