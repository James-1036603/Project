#include "Engine.h"

void Engine::input()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)) _window.close();//Quit the game

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) _player.moveRight();//Player moves right
    else _player.stopRight();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) _player.moveLeft();//Player moves left
    else _player.stopLeft();

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) _player.Shoot(); //Shoot //Keep as a different abstraction. Maybe make an enum that says it is a friendly bullet. Also easier to interact and shoot




}
