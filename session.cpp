#include "session.h"
#include <iostream>

Session::Session(Team teamOne, Team teamTwo) : m_teamOne(teamOne), m_teamTwo(teamTwo)
{
    time_t t = time(0);
    m_startTime = ctime(&t);
}

Team Session::getTeamOne() {return m_teamOne;}
Team Session::getTeamTwo() {return m_teamTwo;}
void Session::claculateWinner()
{
    uint32_t teamOneHP = 0, teamOneDamage = 0, teamTwoHP = 0, teamTwoDamage = 0;
    for(int i = 0; i < TEAM_SIZE; i++)
    {
        try
        {
            Hero hero = m_teamOne.getPlayerByIndex(i).second;
            teamOneHP += hero.getHp();
            teamOneDamage += hero.getDamage();
        }
        catch(const std::exception& e)
        { 
            std::cerr << "Player slot " << i + 1 << " in team " << m_teamOne.getName() << " is empty!";
        }
        try
        {
            Hero hero = m_teamTwo.getPlayerByIndex(i).second;
            teamTwoHP += hero.getHp();
            teamTwoDamage += hero.getDamage();
        }
        catch(const std::exception& e)
        { 
            std::cerr << "Player slot " << i + 1 << " in team " << m_teamTwo.getName() << " is empty!";
        }
    }

    if(teamOneHP > teamTwoDamage) {teamOneHP -= teamTwoDamage;}
    else {teamOneHP = 0;}
    if(teamTwoHP > teamOneDamage) {teamTwoHP -= teamOneDamage;}
    else {teamTwoHP = 0;}

    if(teamOneHP > teamTwoHP)
    {
        m_winner = &m_teamOne;
        m_loser = &m_teamTwo;
    }
    else if(teamTwoHP > teamOneHP)
    {
        m_winner = &m_teamTwo;
        m_loser = &m_teamOne;
    }
    else
    {
        m_winner = nullptr;
        m_loser = nullptr;
    }
}

Team* Session::getWinner() {return m_winner;}
Team* Session::getLoser() {return m_loser;}