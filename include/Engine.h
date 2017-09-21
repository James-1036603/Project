#ifndef ENGINE_H
#define ENGINE_H
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include"Player.h"
#include "BulletManager.h"

class FileNotFound {};

class Engine
{
    public:
        Engine();
        virtual ~Engine();
        void start();

    private:
        sf::RenderWindow _window;//Regular Window
        sf::Sprite _backgroundSprite;//Sprite for background
        sf::Texture _backgroundTexture;//Background texture

        Player _player;//Instance for player
        BulletManager _bulletManager;


        const int _height = sf::VideoMode::getDesktopMode().height;
        const int _width = sf::VideoMode::getDesktopMode().width;

        void drawSplashScreen();
        void input();
        void update(float& dtAsSeconds);
        void draw();
        void drawBullets();

};

#endif // ENGINE_H
