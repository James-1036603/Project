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
    _stepsTaken = 0;
}

Enemy::Enemy(const sf::Vector2f& displaySize, BulletManager* BulMan, EnemyMovement* EnemyMover)
{
    Enemy::generateRotation();
    _speed = 100;
    _objSprite = _default._objSprite;
    _curPosition.x = _default._curPosition.x;
    _curPosition.y = _default._curPosition.y;
    _stepsTaken = _default._stepsTaken;
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
    //Move the enemy
    _moveEnemy->MoveEnemy(_curPosition,_speed,elapsedTime, _rotation);
    Enemy::checkBounds();
    _objSprite.setPosition(_curPosition);
    //Enemy Shoot
    _stepsTaken++;
    Enemy::Shoot();
    //Update Bullets
    Enemy::updateBullets(elapsedTime);


}

void Enemy::generateRotation()
{
    float random = rand()%100;
    _rotation = 2 * PI * (random/100);
}

void Enemy::checkBounds()
{
    if(_curPosition.x >= _displaySize.x || _curPosition.x <= 0 ||
            _curPosition.y >= _displaySize.y || _curPosition.y <= 0)
    {
        _curPosition.x = 960;//Reset if out of bounds x
        _curPosition.y = 540;//Reset if out of bounds y
    }

}

void Enemy::Shoot()
{
    int steps = _stepsTaken;
    if(steps == 20)//Shoot a bullet after every X amount of steps
    {
        Bullet newBullet(_curPosition, _rotation);
        _enemyBullets.push_back(newBullet);
        _stepsTaken = 0;
    }

}

void Enemy::updateBullets(const float& elapsedTime)
{
    for(auto i = 0u; i != _enemyBullets.size(); i++)
    {
        _enemyBullets[i].updateEnemyBullet(elapsedTime);
    }
    _enemyBullets = _BulletManager->deleteInactiveBullets(&_enemyBullets);

}

void Enemy::drawBullets(sf::RenderWindow* currentWindow)
{
    for(auto currentBullet : _enemyBullets)  if(currentBullet.bulletIsAlive())  currentWindow->draw(currentBullet.getSprite());

}

std::vector<Bullet> Enemy::getEnemyBullets() const
{
    return _enemyBullets;
}
