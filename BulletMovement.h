#ifndef BULLETMOVEMENT_H
#define BULLETMOVEMENT_H
#include <SFML/Graphics.hpp>
#include <cmath>
#define CENTER_X 960
#define CENTER_Y 540//Center of the circle, x and y. This is known due to fixed resolution

class BulletMovement
{
    public:
        BulletMovement(const sf::Vector2f& bulletStartingPosition);//This point is defined at the start of the bullet
        virtual ~BulletMovement();

        void MovePlayerBullet(sf::Vector2f* curPos, const float& elapsedTime, bool& bulletSatus);
        void MoveEnemyBullet(sf::Vector2f* curPos, const float& elapsedTime, bool& bulletSatus, const float& rotation, const float& speed);

        float getGradient(){return _gradient;}//ONLY FOR TESTING
        float getIntercept(){return _yIntercept;}//ONLY FOR TESTING
    private:
    sf::Vector2f _bulletStartPos;
    float _gradient, _yIntercept;
    float gradient();
    float yIntercept();
};

#endif // BULLETMOVEMENT_H
