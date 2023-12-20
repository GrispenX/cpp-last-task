#include "gameManager.h"
#include "PlayerHeroList.h"
#include <iostream>

int main()
{
    PlayerManager pmanager;
    HeroManager hmanager;
    for(int i = 0; i < 20; i++)
    {
        pmanager.CreatePlayer(pnamelist[i]);
        hmanager.CreateHero(hnamelist[i], hhplist[i], hdamagelist[i]);
    }
    GameManager game(pmanager, hmanager);
    game.PerformGameSession();
}