
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
        std::cout << "background loaded\n";
    }
    background.setTexture(background_texture);


    character_texture.loadFromFile("C:\\uni\\year 3\\mgicpp-sfml-starter-template\\Critter Crossing Customs\\buffalo.png");
    character.setTexture(character_texture);
    character.setPosition(100,100);
    character.setScale(2.0f,2.0f);

    character2_texture.loadFromFile("C:\\uni\\year 3\\mgicpp-sfml-starter-template\\Critter Crossing Customs\\chicken.png");
    character2.setTexture(character2_texture);
    character2.setPosition(730,475);
    character2.setScale(0.8f,0.8f);
    character2.rotate(90);

    accept_texture.loadFromFile("C:\\uni\\year 3\\mgicpp-sfml-starter-template\\Critter Crossing Customs\\accept button.png");
    accept.setTexture(accept_texture);
    accept.setPosition(900, 475);
    accept.setScale(0.6f, 0.6f);

    reject_texture.loadFromFile("C:\\uni\\year 3\\mgicpp-sfml-starter-template\\Critter Crossing Customs\\reject button.png");
    reject.setTexture(reject_texture);
    reject.setPosition(900, 575);
    reject.setScale(0.6f, 0.6f);

    Passport_texture.loadFromFile("C:\\uni\\year 3\\mgicpp-sfml-starter-template\\Critter Crossing Customs\\default passport.png");
    Passport.setTexture(Passport_texture);
    Passport.setPosition(600,200);
    Passport.setScale(0.7f,0.7f);


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



  return true;
}

void Game::update(float dt)
{

}

void Game::render()
{
    if (in_menu)
    {
        window.draw(menu_text);
        window.draw(play_option);
        window.draw(quit_option);
    }
    else {
        window.draw(background);
        window.draw(character);
        window.draw(Passport);
        window.draw(character2);
        window.draw(accept);
        window.draw(reject);


    }
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);

  // check if button works
    if (collisionCheck(click, accept))
    {
        std::cout << "win" << std::endl;
    }
    if (collisionCheck(click, reject))
    {
        window.close();
    }

}

bool Game::collisionCheck(sf::Vector2i click, sf::Sprite sprite)
{
    if (sprite.getPosition().x + sprite.getGlobalBounds().width > click.x)
    {
        if (click.x > sprite.getPosition().x)
        {
            if (sprite.getPosition().y + sprite.getGlobalBounds().height > click.y)
            {
                if (click.y > sprite.getPosition().y)
                {
                    return true;
                }
            }

        }
    }


    return false;
}
void Game::keyPressed(sf::Event event)
{
    if (event.key.code == sf::Keyboard::Escape)
    {
        window.close();
    }

    if (
            (event.key.code == sf::Keyboard::Left) ||
            (event.key.code == sf::Keyboard::Right))
    {
        play_selected = !play_selected;
        if (play_selected)
        {
            play_option.setString("> Play <");
            quit_option.setString("Quit");
        }
        else
        {
            play_option.setString("Play");

            quit_option.setString("> Quit <");
        }
    }
        else if (event.key.code == sf::Keyboard::Enter)
        {
        if (play_selected)
        {
            in_menu = false;
        }
        }
}


