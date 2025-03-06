#include <iostream>
#include <optional>

#include "LogR.h"
#include "RenderingGame.h"

sf::RenderWindow CreateGameWindow(int WinWidth, int WinHeight, const std::string& GameName)
{
    if(WinHeight<=0  || WinWidth<=0)
        throw std::runtime_error("Game window dimensions incorrect!");
    if(GameName.empty())
        throw std::runtime_error("Name cannot be left empty!");

    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(WinWidth,WinHeight)), GameName);
    return window;
}

bool LoadBackgndImage(sf::Texture& backgroundTexture)
{
    static bool isBackgndImageLoaded = false;
    LogR logger;
    
    if((backgroundTexture.getSize().x <= 0) || (backgroundTexture.getSize().y <= 0))
    {
        if(!backgroundTexture.loadFromFile("../assets/battleground.png"))
        {
            logger.printMsg("Error loading background image");
            return isBackgndImageLoaded;
        }  
        isBackgndImageLoaded = true;
    }    
    return isBackgndImageLoaded;
}

sf::Vector2f GetScaledBackgndImage(sf::RenderWindow& RndrWindow, sf::Texture& backgroundTexture)
{    
    sf::Vector2f windowSize = static_cast<sf::Vector2f>(RndrWindow.getSize());
    sf::Vector2f backgroundSize = static_cast<sf::Vector2f>(backgroundTexture.getSize());   
    float scaleX = (windowSize.x)/(backgroundSize.x);
    float scaleY = (windowSize.y)/(backgroundSize.y); 

    return sf::Vector2f(scaleX, scaleY);
}

void UpdateGameWindow(sf::RenderWindow& RndrWindow, Monsters& Mon1, Monsters& Mon2)
{
    static sf::Texture backgndImgTexture; 

    if(!(LoadBackgndImage(backgndImgTexture)))
        throw std::runtime_error("Background image not loaded");
    
    if(RndrWindow.isOpen())
    {
        if(const std::optional event = RndrWindow.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
                RndrWindow.close();
        }
        sf::Vector2f imageDims = GetScaledBackgndImage(RndrWindow, backgndImgTexture);

        sf::Sprite battleScene(backgndImgTexture);   
        battleScene.setScale(imageDims);     

        RndrWindow.clear();
        RndrWindow.draw(battleScene);
        RndrWindow.display();
    }    
}