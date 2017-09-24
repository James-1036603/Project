#include "Engine.h"

void Engine::input()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)) _window.close();//Quit the game

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) _thePlayer.movePlayer(MoveDirection::LEFT); //Player moves left
    else _thePlayer.movePlayer(MoveDirection::STOP_LEFT);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) _thePlayer.movePlayer(MoveDirection::RIGHT); //Player moves right
    else _thePlayer.movePlayer(MoveDirection::STOP_RIGHT);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) _thePlayer.playerShoot(); //Shoot //Keep as a different abstraction. Maybe make an enum that says it is a friendly bullet. Also easier to interact and shoot



}
