#include <string>

class Player
{
private:
    uint16_t m_id;
    std::string m_name;
    uint16_t m_rank;
public:
    Player() = delete;
    Player(uint16_t id, std::string name);

    uint16_t getId();
    std::string getName();
    uint16_t getRank();
};