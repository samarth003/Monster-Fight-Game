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
    while(RndrWindow.isOpen())
    {
        while(const std::optional event = RndrWindow.pollEvent())
        {
            if(event->is<sf::Event::Closed>())
                RndrWindow.close();
        }

        RndrWindow.clear(sf::Color::Black);

        RndrWindow.display();
    }    
}

// int main()
// {
//     // sf::RenderWindow window(sf::VideoMode(sf::Vector2u(800,600)), "Monster Battle Arena");
//     sf::RenderWindow window = CreateGameWindow();

//     std::cout << "Window created successfully" <<std::endl;

//     while(window.isOpen())
//     {
//         while(const std::optional event = window.pollEvent())
//         {
//             if(event->is<sf::Event::Closed>())
//                 window.close();
//         }

//         window.clear(sf::Color::Black);

//         window.display();
//     }

//     std::cout << "Window closed successfully" << std::endl;
//     return 0;
// }