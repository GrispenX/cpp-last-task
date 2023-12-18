#include "team.h"

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

bool Team::removePlayer(uint16_t id)
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
std::optional<std::pair<Player, Hero>> Team::getPlayerByIndex(int index)
{
    return team[index];
}