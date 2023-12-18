#include "player.h"
#include <string>

#define START_RANK 250

Player::Player(uint16_t id, std::string name)
{
    m_id = id;
    m_name = name;
    m_rank = START_RANK;
}

uint16_t Player::getId() {return m_id;}
std::string Player::getName() {return m_name;}
uint16_t Player::getRank() {return m_rank;}

void Player::changeRank(int rank) {m_rank += rank;}