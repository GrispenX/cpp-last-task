#ifndef TEAM_MANAGER
#define TEAM_MANAGER

#include "team.h"

class TeamManager
{
private:
    std::vector<Team> teamList;
public:
    Team* generateNewteam(std::string name);
    bool deleteTeam(std::string name);

    Team* getTeamByName(std::string name);
    void getTeamInfo(Team team);
};

#endif