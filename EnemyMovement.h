#ifndef ENEMYMOVEMENT_H
#define ENEMYMOVEMENT_H
#include <cstdlib>
#include <SFML/Graphics.hpp>
//#include "Enemy.h"

class EnemyMovement
{
    public:
        EnemyMovement();
        virtual ~EnemyMovement();

        void MoveEnemy(sf::Vector2f& enemyPos, const float& speed, const float& elapsedTime);


    private:

};

#endif // ENEMYMOVEMENT_H
