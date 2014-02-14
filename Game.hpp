#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

#include "Screen.hpp"
#include "MenuScreen.hpp"

#include <memory>

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
	void handleInput();

public:

public:
	static const sf::Time TimePerFrame;
	static const int ScreenWidth;
	static const int ScreenHeight;
	static std::shared_ptr<Screen> mScreen;
	
	
private:
	sf::RenderWindow mWindow;
	

	sf::Font mFont;
	sf::Text mStatText;
	sf::Time mStatUpdateTime;
	std::size_t	mStatNumFrames;
};

#endif