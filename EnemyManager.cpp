#include "EnemyManager.h"

EnemyManager::EnemyManager()
{
    //ctor
}

EnemyManager::~EnemyManager()
{
    //dtor
}

void EnemyManager::spawnEnemies()//First spawn one enemy, then 10 later, then use a level seed
{
    for(auto i = 0; i<10; i++)
    {
        sf::Vector2f displaySize(1920,1080);
        Enemy aNewEnemy(displaySize, &_enemyBulletManager, &_enemyMover);
        _curEnemies.push_back(aNewEnemy);
    }

}

void EnemyManager::updateEnemies(const float& elapsedTime)
{

    for(auto i = 0u; i != _curEnemies.size(); i++) _curEnemies[i].update(elapsedTime); //Update all the enemies in the vector
}

void EnemyManager::drawEnemies(sf::RenderWindow* _curWindow)
{
    for(auto curEnemy : _curEnemies) _curWindow->draw(curEnemy.getSprite());//Draw all enemies in the vector to the screen

}

void EnemyManager::drawEnemyBullets(sf::RenderWindow* _curWindow)
{
    for(auto curEnemy : _curEnemies) curEnemy.drawBullets(_curWindow);//Draw all enemy's in the vector to the screen
}
