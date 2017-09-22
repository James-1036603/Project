#include "Engine.h"

void Engine::draw()
{
    _window.clear(sf::Color::White);

    _window.draw(_backgroundSprite);
    _window.draw(_player.getSprite());

    _player.drawBullets(_window);

    //Draw the enemy
    _theEnemies.drawEnemies(&_window);

    _window.display();
}

void Engine::drawBullets()
{
}
