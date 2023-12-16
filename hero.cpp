#include "hero.h"

Hero::Hero(uint16_t id, std::string name, uint16_t hp, uint16_t damage)
{
    m_id = id;
    m_name = name;
    m_hp = hp;
    m_damage = damage;
}

uint16_t Hero::getId() {return m_id;}
std::string Hero::getName() {return m_name;}
uint16_t Hero::getHp() {return m_hp;}
uint16_t Hero::getDamage() {return m_damage;}