#include "Engine.h"

Engine::Engine():
    _window(sf::VideoMode(1920,1080),"Game", sf::Style::Default),
    _thePlayer(static_cast<sf::Vector2f>(_window.getSize()), 400, &_bulletManager),
    _bulletManager()
{
    Engine::drawSplashScreen();
    if(!_backgroundTexture.loadFromFile("Images/background.jpg")) throw FileNotFound();//Load background texture)
    _backgroundSprite.setTexture(_backgroundTexture);//Set background texture

    if(!_gameMusic.openFromFile("Audio/theme.wav")) throw FileNotFound();//Load Music from file
    _gameMusic.play();//Play
    _gameMusic.setLoop(true);//Loop the music

    _window.setMouseCursorVisible(false);
    _window.setFramerateLimit(60);
    //Spawn the enemies
    _theEnemies.spawnEnemies();
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
        endGame();//Game will end once the player loses 3 lives
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

