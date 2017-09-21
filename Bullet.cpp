#include "Bullet.h"
Bullet Bullet::_default{};

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

bool Bullet::bulletIsAlive() {return _isAlive;};

void Bullet::update(const float& elapsedTime)
{
    //_bulletPos.x += _speed * elapsedTime;
    _bulletMovement.Move(&_bulletPos, elapsedTime, _isAlive);
    _bulletSprite.setPosition(_bulletPos);


    std::cout<<"Updated X: "<<_bulletPos.x<<"\n";
    std::cout<<"Updated Y: "<<_bulletPos.y<<"\n";
}

sf::Sprite Bullet::getSprite()
{
    return _bulletSprite;
}
