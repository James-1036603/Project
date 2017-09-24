#include "PlayerManager.h"

PlayerManager::PlayerManager(const sf::Vector2f& windowSize, const float& radius, BulletManager* bullet_manager):
    _curPlayer(windowSize, radius, bullet_manager)
{
    //ctor
}

PlayerManager::~PlayerManager()
{
    //dtor
}

void PlayerManager::movePlayer(MoveDirection dirToMove)//Move the player
{
    if(dirToMove == MoveDirection::RIGHT) _curPlayer.moveRight();
    else if(dirToMove == MoveDirection::STOP_RIGHT) _curPlayer.stopRight();

    if(dirToMove == MoveDirection::LEFT) _curPlayer.moveLeft();
    else if(dirToMove == MoveDirection::STOP_LEFT) _curPlayer.stopLeft();

    //const sf::Keyboard::Key& curPressedKey
}

void PlayerManager::updatePlayer(const float& elapsedTime)
{
    _curPlayer.update(elapsedTime);
}

void PlayerManager::playerShoot()
{
    _curPlayer.Shoot();
}

void PlayerManager::drawPlayerToWindow(sf::RenderWindow* currentWindow)//Draw player to window
{
    currentWindow->draw(_curPlayer.getSprite());
}

void PlayerManager::drawPlayerBullets(sf::RenderWindow* currentWindow)//Draw player bullets to window
{
    _curPlayer.drawBullets(currentWindow);
}

bool PlayerManager::playerIsAlive() const
{
    return _curPlayer.isAlive();
}

void PlayerManager::checkEnemyBulletsToPlayer(const std::vector<Enemy>& curEnemies)//This is not a good method. What if bullet was implemented other to a vector? plus you reveal that enemy has a vector of bullets
{
    for(auto i = 0u; i != curEnemies.size(); i++)
    {
        for(auto j = 0u; j != curEnemies.at(i).getEnemyBullets().size(); j++)
        {
            Bullet* curBullet = &curEnemies.at(i).getEnemyBullets().at(j);
            if(_curPlayer.getSprite().getGlobalBounds().contains(curBullet->getBulletPos()))//global bounds considers the rotation of the sprite
            {
                _curPlayer.getShot();
                curBullet->setInActive();//Disable the bullet once it has hit the player
                std::cout<<"PLAYER WAS SHOT!"<<"\n";
            }
        }
    }
    //Note, the bullets are not being set inactive yet, thus causing more damage than once to the player. This is likely due to the fact that the returned vectors are CONSTANT, thus no changes to the bullet can be made
}

Player PlayerManager::theCurrentPlayer() const
{
    return _curPlayer;
}
