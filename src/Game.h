
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>

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
  sf::RenderWindow& window;
  GameObject background;
  sf::Texture background_texture;
  sf::Sprite penguin;
  sf::Texture penguin_texture;
  sf::Sprite Passport;
  sf::Texture Passport_texture;
  sf::Sprite chicken;
  sf::Texture chicken_texture;
  sf::Sprite accept;
  sf::Texture accept_texture;
  sf::Sprite reject;
  sf::Texture reject_texture;
  sf::Font font;


  int GameState = 1;
  sf::Text menu_text;
  sf::Text play_option;
  sf::Text quit_option;
  bool play_selected = true;
  sf::Text end_text;


};

#endif // PLATFORMER_GAME_H
