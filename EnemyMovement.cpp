#include "EnemyMovement.h"

EnemyMovement::EnemyMovement()
{
    //ctor

}

EnemyMovement::~EnemyMovement()
{
    //dtor
}

void EnemyMovement::MoveEnemy(sf::Vector2f& enemyPos, const float& speed, const float& elapsedTime)
{
    enemyPos.x += speed * elapsedTime;
}
