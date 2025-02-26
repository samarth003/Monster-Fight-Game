#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Monsters.h"

sf::RenderWindow CreateGameWindow();
void UpdateGameWindow(sf::RenderWindow& RndrWindow, Monsters& Mon1, Monsters& Mon2);