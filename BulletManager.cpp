#include "BulletManager.h"

BulletManager::BulletManager()
{
    //ctor
}

BulletManager::~BulletManager()
{
    //dtor
}

std::vector<Bullet> BulletManager::deleteInactiveBullets(std::vector<Bullet>* bulletVector)
{
    std::vector<Bullet> tempBulletVec;//Temp vector to store the ACTIVE bullets
    for(auto curBullet : *bulletVector)  if(curBullet.bulletIsAlive()) tempBulletVec.push_back(curBullet);

    return tempBulletVec;


}

//void BulletManager::deleteBullet(std::vector<Bullet>* bulletVector, const iterator& elem)
//{
//    auto iter = bulletVector->begin() + elem;
//    *iter = std::move(bulletVector->back());
//    bulletVector->pop_back();
//}
