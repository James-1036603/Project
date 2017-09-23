#include "Player.h"

Player::Player(const sf::Vector2f& displaySize, const float& radius, BulletManager* BulMan)//IMPLEMENT THESE BETTER!
{
    //ctor
    _speed = 200;//How fast should the character move
    if(!_objTexture.loadFromFile("Images/PlayerCharacterSmall.png")) throw player_FileNotFound();//load texture
    _objSprite.setTexture(_objTexture);//set object texture

    //Starting position
    _curPosition.x = 960-400;
    _curPosition.y = 540;
    _circleRadius = radius;
    _curAngle = PI;

    _playerBulletManager = *BulMan;


}

Player::~Player()
{
    //dtor
}

sf::Sprite Player::getSprite()
{
    return _objSprite;
}

void Player::moveRight()
{
    _rightPressed = true;
}

void Player::moveLeft()
{
    _leftPressed = true;
}

void Player::stopRight()
{
    _rightPressed = false;
}

void Player::stopLeft()
{
    _leftPressed = false;
}

void Player::Shoot()
{
    Bullet bullletShot(_curPosition,  _curAngle);//Create a new bullet
    _playerBullets.push_back(bullletShot);
}

void Player::update(const float& elapsedTime)
{
    //Update the player postion
    if(_rightPressed) Player::moveClockwise(elapsedTime);

    if(_leftPressed) Player::moveCounterClockwise(elapsedTime);

    _objSprite.setPosition(_curPosition);
    _objSprite.setRotation((_curAngle * (180/PI)));//Rotate the sprite (degrees)


    Player::updateBullets(elapsedTime);//Update the bullets


}

void Player::updateBullets(const float& elapsedTime)
{
    //Update the bullets position
    for(auto i = 0u; i != _playerBullets.size(); i++)
    {

        _playerBullets.at(i).updatePlayerBullet(elapsedTime);

    }
    _playerBullets =  _playerBulletManager.deleteInactiveBullets(&_playerBullets);//Delete inactive Bullets
}

std::vector<Bullet> Player::getPlayerBullets() const {return _playerBullets;}

void Player::moveClockwise(const float& elapsedTime)
{
    double angle = _curAngle + ((_speed*elapsedTime)/100);

    _curPosition.y = _circleRadius * std::sin(angle)+540;
    _curPosition.x = _circleRadius * std::cos(angle)+960;
    _curAngle = angle;
}

void Player::moveCounterClockwise(const float& elapsedTime)
{
    auto angle = _curAngle - ((_speed*elapsedTime)/100);

    _curPosition.y = _circleRadius * std::sin(angle)+540;
    _curPosition.x = _circleRadius * std::cos(angle)+960;
    _curAngle = angle;
}


void Player::drawBullets(sf::RenderWindow* currentWindow)
{
    for(auto currentBullet : _playerBullets)
        if(currentBullet.bulletIsAlive())currentWindow->draw(currentBullet.getSprite());//Draw the bullet to the screen, but only if it is active
}
