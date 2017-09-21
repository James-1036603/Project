#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <vector>
#include <doctest.h>
#include <SFML/Graphics.hpp>
#include "Engine.h"
#include "Player.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "BulletMovement.h"

TEST_CASE("Bullet Initialised Correctly")
{
    sf::Vector2f position(500.0f, 500.0f);
    auto speed = 1000.0;
    Bullet bullet1(position, 0);


    CHECK(bullet1.getBulletPos() == position);
    CHECK(bullet1.getSpeed() == speed);


}

TEST_CASE("Bullet Texture Found")
{
    CHECK_NOTHROW(Bullet bullet1(sf::Vector2f(50.0f,50.0f),0));
}
//Test bullet movement along line
TEST_CASE("Correct gradient and intercept are found")
{
    BulletMovement movable(sf::Vector2f(1060,640));
    CHECK(movable.getGradient() == 1);
    CHECK(movable.getIntercept() == -420);
}
//Bullet Movement
TEST_CASE("Bullet Moved Correct Amount")
{
    Bullet bullet1(sf::Vector2f(50.0f,50.0f),0);
    bullet1.update(1);
    CHECK(bullet1.getBulletPos().x == doctest::Approx(50.5));
    CHECK(bullet1.getBulletPos().y == doctest::Approx(50.2692));
}

//Player Tests

TEST_CASE("Player is initialised correctly")
{
    Player player1(sf::Vector2f(1920,1080),400, NULL);
    sf::Vector2f playerStartPos(560,540);
    auto speed = 200.0;

    CHECK(player1.getPlayerPos()==playerStartPos);
    CHECK(player1.getSpeed() == speed);

}

TEST_CASE("Player found correct texture")
{
    CHECK_NOTHROW(Player player1(sf::Vector2f(1920,1080),400, NULL));
}


TEST_CASE("Player moves along circular path")
{
    Player player1(sf::Vector2f(1920,1080),400, NULL);

    player1.moveRight();
    player1.update(1);


    CHECK(player1.getPlayerPos().x == doctest::Approx(1125.88f));
    CHECK(player1.getPlayerPos().y == doctest::Approx(176.016f));

    player1.stopRight();
    player1.moveLeft();
    player1.update(1);


    CHECK(player1.getPlayerPos().x == doctest::Approx(560.0f));
    CHECK(player1.getPlayerPos().y == doctest::Approx(540.637f));

}

TEST_CASE("Player can shoot a bullet")
{
    Player player1(sf::Vector2f(1920,1080),400, NULL);
    player1.Shoot();
    std::vector<Bullet> bulletsCur = player1.getPlayerBullets();
    CHECK(bulletsCur.size()!=0);
}

//Test Bullet Manager
TEST_CASE("Inactive Bullets Are Deleted")
{
    Bullet bullet1(sf::Vector2f(50.0f,50.0f),0);
    bullet1.setActive(true);
    Bullet bullet2(sf::Vector2f(50.0f,50.0f),0);
    bullet2.setActive(false);
    std::vector<Bullet> vectorBullets= {bullet1, bullet2};
    BulletManager aBulletManager;
    vectorBullets = aBulletManager.deleteInactiveBullets(&vectorBullets);
    CHECK(vectorBullets.size() == 1);
}


