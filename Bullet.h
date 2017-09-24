#ifndef BULLET_H
#define BULLET_H
#include "BulletMovement.h"
#include <SFML/Graphics.hpp>
#include <iostream>


class bullet_FileNotFound{};
//enum class Owner {PLAYER, ENEMY}//Who owns the shot bullet
class Bullet
{
    public:

        Bullet(const sf::Vector2f& startingPos,  const float& rotation);//Bullet will start at players position
        virtual ~Bullet();
        sf::Sprite getSprite();

        void updatePlayerBullet(const float& elapsedTime);//Player Bullet update
        void updateEnemyBullet(const float& elapsedTime);//Enemy bullet update (different movement to the player)
        bool bulletIsAlive();
        void setInActive();//Disable the bullet

        sf::Vector2f getBulletPos() const {return _bulletPos;}//ONLY USED FOR TESTING
        float getSpeed() const {return _speed;}//ONLY FOR TESTING
        void setActive(bool val) {_isAlive = val;}//ONLY FOR TESTING


    private:
        Bullet();//Private default constructor for static

        sf::Vector2f _bulletPos;//Bullet Position
        sf::Sprite _bulletSprite;//Bullet Sprite
        sf::Texture _bulletTexture;//Bullet Texture
        float _speed;//Speed of bullet
        float _rotation;
        bool _isAlive;
        BulletMovement _bulletMovement;//Object to move the current bullet
        static Bullet _default;//Default bullet, so only load from file once.

        sf::Vector2f _displaySize;



};

#endif // BULLET_H
