#include "Engine.h"

void Engine::update(float& dtAsSeconds)
{
    _thePlayer.updatePlayer(dtAsSeconds);
    _theEnemies.updateEnemies(dtAsSeconds);

    _thePlayer.checkEnemyBulletsToPlayer(_theEnemies.theEnemies());


}

void Engine::endGame()
{
    if(!_thePlayer.playerIsAlive())//if the player is dead, end the game
    {
        _window.close();
    }
}
