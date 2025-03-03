// #include <SFML/Graphics.hpp>
#include <iostream>
#include <optional>

#include "RenderingGame.h"

sf::RenderWindow CreateGameWindow()
{
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800,600)), "Monster Battle Arena");
    return window;
}

void UpdateGameWindow(sf::RenderWindow& RndrWindow, Monsters& Mon1, Monsters& Mon2)
{
    if(RndrWindow.isOpen())
    {
        if(const std::optional event = RndrWindow.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
                RndrWindow.close();
        }

        RndrWindow.clear(sf::Color::Black);
        RndrWindow.display();
    }    
}