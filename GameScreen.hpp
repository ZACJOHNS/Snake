#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include "Screen.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

class GameScreen : public Screen
{
public:
	GameScreen();
	void handleInput(sf::RenderWindow& window);
	void update(sf::Time delta); 
	void render(sf::RenderWindow& window);
};

#endif