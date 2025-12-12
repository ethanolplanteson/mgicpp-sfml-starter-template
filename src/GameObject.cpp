//
// Created by Ethan on 12/12/2025.
//

#include "GameObject.h"
#include <iostream>
#include <SFML/Graphics.hpp>

GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

sf::Sprite* GameObject::getSprite()
{
    return sprite;
}


bool GameObject::initialiseSprite(sf::Texture &texture, std::string filename)
{
    sprite = new sf::Sprite();
    if (!texture.loadFromFile(filename))
    {
        std::cout << "character texture did not load at all\n";
    }
    sprite->setTexture(texture);
    return true;
}