#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include "Screen.hpp"

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class MenuScreen : public Screen
{
public:
	MenuScreen();
	void handleInput(sf::RenderWindow& window);
	void update(sf::Time delta);
	void render(sf::RenderWindow& window);

private:
	sf::Font mFont;
	sf::Text mTitle;
};

#endif