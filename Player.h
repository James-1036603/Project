#ifndef Player_H
#define Player_H

#define PI 3.14
#include <vector>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "BulletManager.h"
#include <cmath>

#include <iostream>

class player_FileNotFound{};

class Player
{
public:
    Player(const sf::Vector2f& displaySize, const float& radius, BulletManager* BulMan);
    virtual ~Player();
    sf::Sprite getSprite();//Get a copy of the current sprite

    void moveLeft();//Move the object left
    void moveRight();//Move the object right
    void stopLeft();//Stop moving left
    void stopRight();//Stop moving right

    void Shoot();

    void update(const float& elapsedTime);//Called once per frame
    std::vector<Bullet> getPlayerBullets() const;
    void drawBullets(sf::RenderWindow* currentWindow);

    sf::Vector2f getPlayerPos() const {return _curPosition;}//ONLY FOR TESTS
    float getSpeed() const {return _speed;}//ONLY FOR TESTS


private:
    sf::Vector2f _curPosition;//Where is the current object
    sf::Sprite _objSprite;//Sprite for the object
    sf::Texture _objTexture;//Texture for the object . Static because it is slow to load the texture each time from file!!
    float _speed;//Speed of pixels per second
    bool _rightPressed;//Object is moving right
    bool _leftPressed;//Object is moving left

    float _circleRadius;
    float _curAngle;
    void moveClockwise(const float& elapsedTime);//Move player clockwise along the circle
    void moveCounterClockwise(const float& elapsedTime);//Move player anti-clockwise along the circle

    std::vector<Bullet> _playerBullets;
    void updateBullets(const float& elapsedTime);

    BulletManager _playerBulletManager;


    sf::Vector2f _displaySize;//The resolution of the display. Ensure that out player does not go out of bounds (This will not be needed for the angular movement)

};

#endif // Player_H
