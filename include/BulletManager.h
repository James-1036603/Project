#ifndef BULLETMANAGER_H
#define BULLETMANAGER_H
#include "Bullet.h"
#include <vector>

class BulletManager
{
    public:
        BulletManager();
        virtual ~BulletManager();
        std::vector<Bullet> deleteInactiveBullets(std::vector<Bullet>* bulletVector);

    private:


};

#endif // BULLETMANAGER_H
