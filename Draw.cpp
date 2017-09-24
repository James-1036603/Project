#include "Engine.h"

void Engine::draw()
{
    _window.clear(sf::Color::White);

    _window.draw(_backgroundSprite);
    //Draw the player
    _thePlayer.drawPlayerToWindow(&_window);
    _thePlayer.drawPlayerBullets(&_window);

    //Draw the enemy
    _theEnemies.drawEnemies(&_window);
    _theEnemies.drawEnemyBullets(&_window);
    _window.display();
}
