#ifndef GAME_H
#define GAME_H

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Game : private sf::NonCopyable
{ 
public:
	Game();
	void run();

private:
	void processEvents();
	void update(sf::Time elapsedTime);
	void render();
	
private:
	static const sf::Time TimePerFrame;
	sf::RenderWindow mWindow;
};

#endif