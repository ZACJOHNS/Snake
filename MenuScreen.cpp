#include "MenuScreen.hpp"

MenuScreen::MenuScreen()
: mFont()
, mTitle()
{
	createScreen();
	createMenu();
}

void MenuScreen::handleInput(sf::RenderWindow& window)
{
	startButton.handleInput(window);

	if (startButton.isClicked())
		Game::Screen = std::make_shared<MenuScreen>();
}

void MenuScreen::update(sf::Time delta)
{

}

void MenuScreen::render(sf::RenderWindow& window)
{
	window.draw(mTitle);
	window.draw(startButton);
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
}