#include "teamManager.h"
#include <iostream>

Team& TeamManager::getTeamByName(std::string name)
{
    for(long unsigned int i = 0; i < teamList.size(); i++)
    {
        if(teamList[i].getName() == name) {return teamList[i];}
    }
    throw std::runtime_error("Team with name " + name + " not found");
}

Team& TeamManager::generateNewteam(std::string name)
{
    for(auto it = teamList.begin(); it != teamList.end(); it++)
    {
        if(it->getName() == name) {throw std::runtime_error("Team with name " + name + " already exist");}
    }
    teamList.push_back(Team(name));
    return teamList[teamList.size() - 1];
}

bool TeamManager::deleteTeam(std::string name)
{
    for(auto it = teamList.begin(); it < teamList.end(); it++)
    {
        if(it->getName() == name)
        {
            teamList.erase(it);
            return true;
        }
    }
    return false;
}

void TeamManager::getTeamInfo(Team team)
{
    std::cout << "===TEAM===" << std::endl;
    std::cout << "Name: " << team.getName() << std::endl;
    for(int i = 0; i < TEAM_SIZE; i++)
    {
        std::cout << i+1 << ". ";
        std::optional<std::pair<Player, Hero>> current = team.getPlayerByIndex(i);
        if(current.has_value())
        {
            std::cout << current.value().first.getName() << " plays on hero " << current.value().second.getName() << std::endl;
        }
        else 
        {
            std::cout << "Empty" << std::endl;
        }
    }
    std::cout << "==========" << std::endl;
}