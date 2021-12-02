//
// Created by fiana on 4/9/2020.
//
#include <string>
#include "TextureManager.h"
using namespace std;
std::unordered_map<std::string,sf::Texture> TextureManager::textures;

void TextureManager::LoadTexture(const char *filename){

    string filepath = "images/";
    filepath += filename;
    filepath += ".PNG";
    textures[filename].loadFromFile(filepath);
}

sf::Texture &TextureManager::GetTexture(const char *textureKey) {

    if(textures.find(textureKey) == textures.end()){
        LoadTexture(textureKey);
    }
    return textures[textureKey];
}

void TextureManager::Clear() {
    textures.clear();
}
