//
// Created by jared on 2022-11-29.
//
#include "link.h"

using namespace std;

std::map<std::string, sf::Texture> LoadTextures(){
    string texturesPath = "../assets/sprites";
    auto iterator = filesystem::directory_iterator(texturesPath);
    static std::map<std::string, sf::Texture> returnMap;

    int textureCount = 0;

    for (auto& entry : iterator) {
        sf::Texture texture;
        texture.loadFromFile(entry.path().generic_string());
        sf::Texture::bind(&texture);
        returnMap.insert(pair<string, sf::Texture>(entry.path().filename().string(), texture));
        textureCount++;
    };
    cout << "Found " << textureCount << " texture(s) in LoadTextures function." << endl;

    return returnMap;
}

std::map<std::string, sf::Sprite> LoadSprites(sf::RenderWindow &window){
    static std::map<std::string, sf::Texture> textures = LoadTextures();
    static std::map<std::string, sf::Sprite> returnMap;
    int spriteCount = 0;
    for(auto const& [key, val] : textures) {
        sf::Sprite sprite;
        sprite.setTexture(val);
        returnMap.insert({key, sprite});
        spriteCount++;
        cout << "Loaded " << spriteCount << " sprite(s) in LoadSprites function." << endl;

    }
    return returnMap;
}

//

