#include "Engine.h"

void Engine::draw()
{
    _window.clear(sf::Color::White);

    _window.draw(_backgroundSprite);
    _window.draw(_player.getSprite());

//    for(unsigned int i = 0; i != _player.getPlayerBullets().size(); i++)
//    {
//
//        _window.draw(_player.getPlayerBullets().at(i).getSprite());
//    }
    _player.drawBullets(_window);

    _window.display();
}

void Engine::drawBullets()
{
}
