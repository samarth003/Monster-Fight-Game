#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Monsters.h"

/**
 * CreateGameWindow()
 * @brief Creates a game window for 2D rendering 
 * @return a 2D window object 
 */
sf::RenderWindow CreateGameWindow();

/**
 * GetBackgndImage()
 * @brief Checks if there a battleground image. If not, loads it and scales it to the
 *        size of the game window.
 * @param [in] RndrWindow        reference to 2d window object 
 * @param [in] backgroundTexture reference to texture object for background image
 * @return scaled dimenstions for background image  
 */
sf::Vector2f GetBackgndImage(sf::RenderWindow& RndrWindow, sf::Texture& backgroundTexture);

/**
 * UpdateGameWindow()
 * @brief game window gets updated with stats - HP, energy. Monster animations rendered to 
 *        be displayed on the window. 
 * @param [in] RndrWindow reference to 2d window object
 * @param [in] Mon1       reference to an object of type monster
 * @param [in] Mon2       reference to an object of type monster
 */
void UpdateGameWindow(sf::RenderWindow& RndrWindow, Monsters& Mon1, Monsters& Mon2);