#include "Engine.h"

Engine::Engine():_bulletManager(),_window(sf::VideoMode(1920,1080),"Game", sf::Style::Default),

    _player(static_cast<sf::Vector2f>(_window.getSize()), 400, &_bulletManager)


{
    Engine::drawSplashScreen();
    if(!_backgroundTexture.loadFromFile("Images/background.jpg")) throw FileNotFound();//Load background texture)
    _backgroundSprite.setTexture(_backgroundTexture);//Set background texture

//    sf::Vector2f resolution;
//    resolution = _window.getSize();
//    _player = Player(const sf::Vector2f& displaySize);

}

Engine::~Engine()
{
    //dtor
}

void Engine::start()
{
    //Timing
    sf::Clock sysClock;
    while(_window.isOpen())
    {
        sf::Time dt = sysClock.restart();

        float dtAsSeconds = dt.asSeconds();
        input();
        update(dtAsSeconds);
        draw();
    }
}

void Engine::drawSplashScreen()
{
    sf::RenderWindow splashScreen(sf::VideoMode(1920,1080), "Splash Screen", sf::Style::Default);
    sf::Texture splashImage;
    if(!splashImage.loadFromFile("Images/splashscreen.png")) throw FileNotFound();
    sf::Sprite splashscreenSprite;
    splashscreenSprite.setTexture(splashImage);

    while(splashScreen.isOpen())
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) splashScreen.close();
        else
        {
            splashScreen.clear();
            splashScreen.draw(splashscreenSprite);
            splashScreen.display();
        }
    }


}
