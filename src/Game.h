
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);

 private:
    bool collisionCheck(sf::Vector2i click, sf::Sprite sprite);
  sf::RenderWindow& window;
  sf::Sprite background;
  sf::Texture background_texture;
  sf::Sprite character;
  sf::Texture character_texture;
  sf::Sprite character2;
  sf::Texture character2_texture;
  sf::Sprite Passport;
  sf::Texture Passport_texture;
  sf::Sprite accept;
  sf::Texture accept_texture;
  sf::Sprite reject;
  sf::Texture reject_texture;
  sf::Font font;


  bool in_menu = true;
  sf::Text menu_text;
  sf::Text play_option;
  sf::Text quit_option;
  bool play_selected = true;
  sf::Text end_text;


};

#endif // PLATFORMER_GAME_H
