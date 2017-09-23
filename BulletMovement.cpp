#include "BulletMovement.h"

BulletMovement::BulletMovement(const sf::Vector2f& bulletStartingPosition)
{
    //ctor
    _bulletStartPos = bulletStartingPosition;
    _gradient = BulletMovement::gradient();
    _yIntercept= BulletMovement::yIntercept();
}

BulletMovement::~BulletMovement()
{
    //dtor
}

float BulletMovement::gradient()
{
    auto y1 = _bulletStartPos.y;
    auto x1 = _bulletStartPos.x;

    return((CENTER_Y-y1)/(CENTER_X-x1));
}

float BulletMovement::yIntercept()
{
    return CENTER_Y - (_gradient * CENTER_X);
}

void BulletMovement::MovePlayerBullet(sf::Vector2f* curPos, const float& elapsedTime, bool& bulletSatus)
{
    auto newX = 0.0f;
    if(curPos->x>CENTER_X) newX = curPos->x - 0.01*(curPos->x);
    if(curPos->x<CENTER_X) newX = curPos->x + 0.01*(curPos->x);
    if(newX > 950&&newX<970)//20 pixel radius for where the bullet cant go
    {
    newX = 960;
    bulletSatus =0;//Bullet is inactive once it reaches the center
    }


    auto newY = _gradient*newX + _yIntercept;

    curPos->x = newX;
    curPos->y = newY;
}
void BulletMovement::MoveEnemyBullet(sf::Vector2f* curPos, const float& elapsedTime, bool& bulletSatus, const float& rotation, const float& speed)
{
    curPos->x += -(speed*elapsedTime) * std::cos(rotation);
    curPos->y += -(speed*elapsedTime) * std::sin(rotation);
    if(curPos->x>1920 || curPos->x<0 || curPos->y > 1080 || curPos->y <0) bulletSatus = 0; //If the bullet has gone off the screen, set inactive
}
