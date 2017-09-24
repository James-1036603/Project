#include "Bullet.h"
Bullet Bullet::_default {};

Bullet::Bullet():_bulletMovement(sf::Vector2f(0,0))
{
    _isAlive = 1;
    _speed = 1000;
    if(!_bulletTexture.loadFromFile("Images/Bullet.png")) throw bullet_FileNotFound();
    _bulletSprite.setTexture(_bulletTexture);
}

Bullet::Bullet(const sf::Vector2f& startingPos, const float& rotation): _bulletMovement(startingPos)
{
    //ctor
    _speed=_default._speed;
    _isAlive = 1;
    _rotation = rotation;
    _bulletSprite=_default.getSprite();
    _bulletPos = startingPos;
    _bulletSprite.setRotation((rotation*180/3.14)+90);

    //_displaySize = displaySize;
}

Bullet::~Bullet()
{
    //dtor
}

bool Bullet::bulletIsAlive()
{
    return _isAlive;
};

void Bullet::updatePlayerBullet(const float& elapsedTime)
{
    _bulletMovement.MovePlayerBullet(&_bulletPos, elapsedTime, _isAlive);//Move the player bullet
    _bulletSprite.setPosition(_bulletPos);
}

void Bullet::updateEnemyBullet(const float& elapsedTime)
{
    _bulletMovement.MoveEnemyBullet(&_bulletPos, elapsedTime, _isAlive, _rotation, _speed);//Move the enemy bullet
    _bulletSprite.setPosition(_bulletPos);

}
sf::Sprite Bullet::getSprite()
{
    return _bulletSprite;
}

void Bullet::setInActive()
{
    _isAlive = false;
}
