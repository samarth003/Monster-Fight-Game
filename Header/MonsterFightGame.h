#pragma once

#include<iostream>
#include<vector>

#include "RenderingGame.h"
#include "Monsters.h"

/**
 * CreateRoster()
 * @brief Roster creation to have all monsters in once place 
 * @param[out] roster Reference to a vector of pointers of type Monsters  
 */
void CreateRoster(std::vector<Monsters*>& roster);

/**
 * MonSelection()
 * @brief From the populated roster list, select two monsters for battle
 * @param[in]       roster  Reference to vector of pointers of type Monsters 
 * @param[out]      Mon1    Reference to pointer of type Monsters, updated with choice of 1st monster
 * @param[out]      Mon2    Reference to pointer of type Monsters, updated with choice of 2nd monster
 * @param[in,out]   PlayBot Flag set to true if user wants to play with Bot, otherwise false  
 */
void MonSelection(std::vector<Monsters*>& roster, Monsters*& Mon1, Monsters*& Mon2, bool& PlayBot);

/**
 * MonBattle()
 * @brief Turn based Battle system where it will alternate between 2 monsters move selection
 * @param[in] RndrGameWindow    Reference to 2D game rendering window 
 * @param[in] Mon1              Reference to a Monsters object (can be any of the monster type defined)
 * @param[in] Mon2              Reference to a Monsters object (can be any of the monster type defined)
 * @param[in] PlayBot           Reference to a bool flag indicating if user wants to play with Bot  
 */
void MonBattle(sf::RenderWindow& RndrGameWindow ,Monsters& Mon1, Monsters& Mon2, bool& PlayBot);

/**
 * ExitBattle()
 * @brief Custom exit for safely cleaning out the battlefield before exit
 * @param[in] roster Reference to a vector of pointers of type Monsters 
 */
void ExitBattle(std::vector<Monsters*>& roster);
