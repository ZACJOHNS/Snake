#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

<<<<<<< HEAD
class GameScreen : public Screen
{

}
=======
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
>>>>>>> Game_Screen

#endif