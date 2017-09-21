#include "Enemy.h"


Enemy Enemy::_default{};
Enemy::Enemy()
{
    //ctor
    if (!_objTexture.loadFromFile("Images/EnemyCharacter.png")) throw enemy_FileNotFound();
    _objSprite.setTexture(_objTexture);
    _curPosition.x = 960;
    _curPosition.y = 540;
}

Enemy::Enemy(const sf::Vector2f& displaySize, BulletManager* BulMan)
{
    _objSprite = _default._objSprite;
    _curPosition.x = _default._curPosition.x;
    _curPosition.y = _default._curPosition.y;
    _speed = 100;

    _BulletManager = *BulMan;
    _displaySize = displaySize;
}

Enemy::~Enemy()
{
    //dtor
}

sf::Sprite Enemy::getSprite() const {return _objSprite;}

void Enemy::update(const float& elapsedTime)
{
    _curPosition.x -= _speed * elapsedTime;
    if(_curPosition.x >= _displaySize.x || _curPosition.x <= 0) _curPosition.x = 960;
    _objSprite.setPosition(_curPosition);
}
