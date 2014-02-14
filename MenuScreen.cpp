#include "MenuScreen.hpp"

MenuScreen::MenuScreen()
{ 
	createScreen();
	createMenu();
}

void MenuScreen::handleInput(sf::RenderWindow& window)
{
	startButton.handleInput(window);
	exitButton.handleInput(window);

	if (startButton.isClicked())
	{
		Game::mScreen = std::make_shared<GameScreen>();
	}

	else if (exitButton.isClicked())
	{
		window.close();
	}
}

void MenuScreen::update(sf::Time delta)
{

}

void MenuScreen::render(sf::RenderWindow& window)
{
	window.draw(mTitle);
	window.draw(startButton);
	window.draw(exitButton);

}

void MenuScreen::createScreen()
{
	mFont.loadFromFile("Media/Minecraftia.ttf");
	mTitle.setFont(mFont);
	mTitle.setPosition(Game::ScreenWidth / 2 - 115, 10.f);
	mTitle.setCharacterSize(60);
	mTitle.setColor(sf::Color::Green);
	mTitle.setString("SNAKE");
}

void MenuScreen::createMenu()
{
	startButton.setPosition(sf::Vector2f(Game::ScreenWidth / 2, Game::ScreenHeight / 2));
	startButton.setSize(sf::Vector2f(250.f, 250.f));
	startButton.setString("START");
	sf::Vector2f buttonSize = sf::Vector2f(250.f, 50.f);

	startButton.setPosition(sf::Vector2f(Game::ScreenWidth / 2 - (buttonSize.x/2), 
		Game::ScreenHeight / 2 - (buttonSize.y/2)));
	startButton.setSize(buttonSize);
	startButton.setString("START");

	exitButton.setPosition(sf::Vector2f(Game::ScreenWidth / 2 - (buttonSize.x/2), 
		Game::ScreenHeight / 2 - (buttonSize.y/2) + 120));
	exitButton.setSize(buttonSize);
	exitButton.setString("EXIT");
}