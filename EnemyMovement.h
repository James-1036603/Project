#ifndef ENEMYMOVEMENT_H
#define ENEMYMOVEMENT_H
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <cmath>
//#include "Enemy.h"

class EnemyMovement
{
    public:
        EnemyMovement();
        virtual ~EnemyMovement();

        void MoveEnemy(sf::Vector2f& enemyPos, const float& speed, const float& elapsedTime, const float& rotation);


    private:
};

#endif // ENEMYMOVEMENT_H
