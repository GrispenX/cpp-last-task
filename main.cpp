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
    game.getPManager().showPlayerInfo(game.getPManager().getPlayerById(game.getSessionByIndex(0).getWinner()->getPlayerByIndex(0).first.getId()));
    game.getPManager().showPlayerInfo(game.getPManager().getPlayerById(game.getSessionByIndex(0).getLoser()->getPlayerByIndex(0).first.getId()));
}