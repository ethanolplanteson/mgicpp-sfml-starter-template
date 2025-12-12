
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
    if (!font.loadFromFile("C:\\uni\\year 3\\mgicpp-sfml-starter-template\\Data\\Fonts\\OpenSans-Bold.ttf"))
	{
		std::cout << "font loaded\n";
	}
    if (background_texture.loadFromFile("C:\\uni\\year 3\\mgicpp-sfml-starter-template\\Data\\WhackaMole Worksheet\\background.png"))
    {
        std::cout << "background texture loaded\n";
    }
    background.setTexture(background_texture);

    if (penguin_texture.loadFromFile("C:\\uni\\year 3\\mgicpp-sfml-starter-template\\Critter Crossing Customs\\penguin.png"))
    {
        std::cout << "penguin could loaded\n";
    }
    penguin.setTexture(penguin_texture);
    penguin.setPosition(100,100);
    penguin.setScale(0.5f,0.5f);

    GameState = 1; //main menu

    menu_text.setString("Passport Interception");
    menu_text.setFont(font);
    menu_text.setCharacterSize(100);
    menu_text.setFillColor(sf::Color(205, 0, 26, 128));
    menu_text.setPosition(
            float(window.getSize().x) / 2 - menu_text.getGlobalBounds().width / 2,
            menu_text.getGlobalBounds().height);

    play_option.setString("Play option");
    play_option.setFont(font);
    play_option.setCharacterSize(50);
    play_option.setFillColor(sf::Color(255, 255, 255, 128));
    play_option.setPosition(
            play_option.getGlobalBounds().width / 2,
            window.getSize().y / 2 - play_option.getGlobalBounds().height / 2);

    quit_option.setString("Quit option");
    quit_option.setFont(font);
    quit_option.setCharacterSize(50);
    quit_option.setFillColor(sf::Color(255, 255, 255, 128));
    quit_option.setPosition(
            window.getSize().x / 2 + quit_option.getGlobalBounds().width / 2,
            window.getSize().y / 2 - quit_option.getGlobalBounds().height / 2);

    GameState = 3; //end screen
    end_text.setString("Passport Intercepted");
    end_text.setFont(font);
    end_text.setCharacterSize(100);
    end_text.setFillColor(sf::Color(205,0,26,128));
    end_text.setPosition(
            float(window.getSize().x)/2 - end_text.getGlobalBounds().width/2,
            end_text.getGlobalBounds().height);
  return true;
}

void Game::update(float dt)
{
    if (GameState == 1)
    {
    }
    else if (GameState == 2)
    {

    }
}

void Game::render()
{
    if (GameState == 1)
    {
        window.draw(menu_text);
        window.draw(play_option);
        window.draw(quit_option);
    }
    else if (GameState == 2)
    {
        window.draw(background);
    }
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::keyPressed(sf::Event event)
{

}


