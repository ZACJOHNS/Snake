#ifndef GAME_H
#define GAME_H

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class Game : private sf::NonCopyable
{
public:
	Game();
	void run();

private:
	void processEvents();
	void update(sf::Time elapsedTime);
	void render();
	void updateStats(sf::Time elapsedTime);
	
private:
	static const sf::Time TimePerFrame;

	sf::RenderWindow mWindow;

	sf::Font mFont;
	sf::Text mStatText;
	sf::Time mStatUpdateTime;
	std::size_t	mStatNumFrames;
};

#endif