#ifndef ENEMYMANAGER_H
#define ENEMYMANAGER_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include "EnemyMovement.h"
#include "BulletManager.h"


class EnemyManager
{
    public:
        EnemyManager();
        virtual ~EnemyManager();
        void spawnEnemies();//Spawn new enemies in a level
        void updateEnemies(const float& elapsedTime);
        void drawEnemies(sf::RenderWindow* _curWindow);//Draw enemies to the current window
    private:
        std::vector<Enemy> _curEnemies;//The current enemies on display
        EnemyMovement _enemyMover;
        BulletManager _enemyBulletManager;
};

#endif // ENEMYMANAGER_H
