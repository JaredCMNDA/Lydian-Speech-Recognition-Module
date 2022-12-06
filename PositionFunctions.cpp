//
// Created by jared on 2022-11-29.
//
#include "link.h"

void CenterSprite(sf::Sprite sprite, sf::RenderWindow &window, int xoffset, int yoffset) {
    sprite.setPosition(sf::Vector2f((400 - sprite.getGlobalBounds().width / 2) + xoffset, (300 - sprite.getGlobalBounds().height / 2) + yoffset));
    window.draw(sprite);
}
void CenterText(sf::Text text, sf::RenderWindow &window, int xoffset, int yoffset){
    text.setPosition(sf::Vector2f((400 - text.getGlobalBounds().width / 2) + xoffset, (300 - text.getGlobalBounds().height / 2) + yoffset));
    window.draw(text);
}