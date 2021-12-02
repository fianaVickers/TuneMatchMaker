#pragma once
#include <unordered_map>
#include <string>
#include <SFML/Graphics.hpp>


class TextureManager {
    static std::unordered_map<std::string,sf::Texture> textures;
public:
    static void LoadTexture(const char* filename);
    static sf::Texture& GetTexture(const char * textureKey);
    static void Clear();
};
