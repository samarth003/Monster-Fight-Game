#include <iostream>
#include <optional>

#include "RenderingGame.h"

sf::RenderWindow CreateGameWindow()
{
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800,600)), "Monster Battle Arena");
    return window;
}

sf::Vector2f GetBackgndImage(sf::RenderWindow& RndrWindow, sf::Texture& backgroundTexture)
{
    static bool isBackgndImageLoaded = false;
    
    if(!isBackgndImageLoaded)
    {
        if(!backgroundTexture.loadFromFile("../assets/battleground.png"))
        {
            std::cerr << "Error loading background image" << std::endl;
            return sf::Vector2f(1.0f, 1.0f);
        }  
        isBackgndImageLoaded = true;
    }
    sf::Vector2f windowSize = static_cast<sf::Vector2f>(RndrWindow.getSize());
    sf::Vector2f backgroundSize = static_cast<sf::Vector2f>(backgroundTexture.getSize());   
    float scaleX = (windowSize.x)/(backgroundSize.x);
    float scaleY = (windowSize.y)/(backgroundSize.y); 

    return sf::Vector2f(scaleX, scaleY);

}

void UpdateGameWindow(sf::RenderWindow& RndrWindow, Monsters& Mon1, Monsters& Mon2)
{
    static sf::Texture backgndImgTexture; 
    if(RndrWindow.isOpen())
    {
        if(const std::optional event = RndrWindow.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
                RndrWindow.close();
        }
        sf::Vector2f imageDims = GetBackgndImage(RndrWindow, backgndImgTexture);

        sf::Sprite battleScene(backgndImgTexture);   
        battleScene.setScale(imageDims);     

        RndrWindow.clear();
        RndrWindow.draw(battleScene);
        RndrWindow.display();
    }    
}