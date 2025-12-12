//
// Created by Ethan on 12/12/2025.
//

#ifndef PLATFORMERSFML_GAMEOBJECT_H
#define PLATFORMERSFML_GAMEOBJECT_H
#include <iostream>
#include <SFML/Graphics.hpp>


class GameObject {
public:
    GameObject();
    ~GameObject();
    bool initialiseSprite(sf::Texture &texture, std::string filename);
    sf::Sprite* getSprite();
    bool ISvisible;





private:
    sf::Sprite* sprite = nullptr;

};


#endif //PLATFORMERSFML_GAMEOBJECT_H
