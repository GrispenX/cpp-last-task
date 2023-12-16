#include <string>

class Hero
{
private:
    uint16_t m_id;
    std::string m_name;
    uint16_t m_hp;
    uint16_t m_damage;
public:
    Hero() = delete;
    Hero(uint16_t id, std::string name, uint16_t hp, uint16_t damage);

    uint16_t getId();
    std::string getName();
    uint16_t getHp();
    uint16_t getDamage();
};