//
// Created by jared on 2022-11-29.
//

#ifndef LYDIAN_LINK_H
#define LYDIAN_LINK_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>



// Global Variables
void CenterSprite(sf::Sprite sprite, sf::RenderWindow &window, int xoffset, int yoffset);
void CenterText(sf::Text text, sf::RenderWindow &window, int xoffset, int yoffset);
std::map<std::string, sf::Texture> LoadTextures();
std::map<std::string, sf::Sprite> LoadSprites(sf::RenderWindow &window);
void StartButton();

#endif //LYDIAN_LINK_H
