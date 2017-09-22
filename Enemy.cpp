#include "Enemy.h"


Enemy Enemy::_default {};
Enemy::Enemy()
{
    //ctor
    if (!_objTexture.loadFromFile("Images/EnemyCharacter.png")) throw enemy_FileNotFound();
    _objSprite.setTexture(_objTexture);
    _curPosition.x = 960;
    _curPosition.y = 540;
    _isAlive = true;
}

Enemy::Enemy(const sf::Vector2f& displaySize, BulletManager* BulMan, EnemyMovement* EnemyMover)
{
    Enemy::generateRotation();
    _speed = 100;
    _objSprite = _default._objSprite;
    _curPosition.x = _default._curPosition.x;
    _curPosition.y = _default._curPosition.y;
    _objSprite.setRotation(_rotation*(180/PI));
    _objSprite.setPosition(_curPosition);


    _BulletManager = BulMan;
    _moveEnemy = EnemyMover;
    _displaySize = displaySize;


}

Enemy::~Enemy()
{
    //dtor
}

sf::Sprite Enemy::getSprite() const
{
    return _objSprite;
}

void Enemy::update(const float& elapsedTime)
{

    _moveEnemy->MoveEnemy(_curPosition,_speed,elapsedTime);
//    _curPosition.x -= _speed * elapsedTime;
    if(_curPosition.x >= _displaySize.x || _curPosition.x <= 0) _curPosition.x = 960;
    _objSprite.setPosition(_curPosition);
}

void Enemy::generateRotation()
{
    srand(time(NULL));
    float random = rand()%100;
    _rotation = 2 * PI * (random/100);
}
