#ifndef MENUSCREEN_HPP
#define MENUSCREEN_HPP

#include "Screen.hpp"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Game.hpp"
#include "Button.hpp"
<<<<<<< HEAD
=======
#include "GameScreen.hpp"
>>>>>>> Game_Screen

class MenuScreen : public Screen
{
public:
	MenuScreen();
	void handleInput(sf::RenderWindow& window);
	void update(sf::Time delta);
	void render(sf::RenderWindow& window);

private:
	void createScreen();
	void createMenu();

private:
	sf::Font mFont;
	sf::Text mTitle;

	Button startButton;
	Button exitButton;
};

#endif