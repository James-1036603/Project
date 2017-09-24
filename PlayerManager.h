#ifndef PLAYERMANAGER_H
#define PLAYERMANAGER_H
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>

enum class MoveDirection {RIGHT, LEFT, STOP_RIGHT, STOP_LEFT};

class PlayerManager
{
    public:
        PlayerManager(const sf::Vector2f& windowSize, const float& radius, BulletManager* bullet_manager);
        virtual ~PlayerManager();
        void updatePlayer(const float& elapsedTime);//Update the player
        void checkEnemyBulletsToPlayer(const std::vector<Enemy>& curEnemies);//Check if the player is shot by an enemy
        void playerShoot();
        void drawPlayerToWindow(sf::RenderWindow* currentWindow);
        void drawPlayerBullets(sf::RenderWindow* currentWindow);
        bool playerIsAlive() const;
        void movePlayer(MoveDirection dirToMove);//Move the player

    private:
    Player _curPlayer;



};

#endif // PLAYERMANAGER_H
