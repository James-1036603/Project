#ifndef ENEMY_H
#define ENEMY_H
#include <vector>
#include <SFML/Graphics.hpp>
#include "EnemyMovement.h"
#include "Bullet.h"
#include "BulletManager.h"
#define PI 3.14

#include <iostream>

class enemy_FileNotFound{};
class Enemy
{
    public:
    Enemy();
    Enemy(const sf::Vector2f& displaySize, BulletManager* BulMan, EnemyMovement* EnemyMover);
    virtual ~Enemy();
    sf::Sprite getSprite() const;//Get a copy of the current sprite

    void Shoot();

    void update(const float& elapsedTime);//Called once per frame
    std::vector<Bullet> getEnemyBullets() const;
    void drawBullets(sf::RenderWindow* currentWindow);

    sf::Vector2f getEnemyPos() const {return _curPosition;}//ONLY FOR TESTS
    float getSpeed() const {return _speed;}//ONLY FOR TESTS


private:
    sf::Vector2f _curPosition;//Where is the current object
    sf::Sprite _objSprite;//Sprite for the object
    sf::Texture _objTexture;//Texture for the object . Static because it is slow to load the texture each time from file!!
    float _speed;//Speed of pixels per second
    float _rotation;
    int _stepsTaken;//The idea is, a bullet will be shot every 5 steps taken
    void generateRotation();


    std::vector<Bullet> _enemyBullets;
    void updateBullets(const float& elapsedTime);
    void checkBounds();//Check if the enemy has moved out of bounds

    static Enemy _default;//Static enemy as default to prevent unwanted load times per init
    BulletManager* _BulletManager;
    EnemyMovement* _moveEnemy;

    sf::Vector2f _displaySize;//When the enemy goes off the screen

    bool _isAlive;

};

#endif // ENEMY_H
