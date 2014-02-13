#include "MenuScreen.hpp"

MenuScreen::MenuScreen()
: mFont()
, mTitle()
{
	mFont.loadFromFile("Media/Minecraftia.ttf");
	mTitle.setFont(mFont);
	mTitle.setPosition(0.f, 0.f);
	mTitle.setCharacterSize(20);
	mTitle.setColor(sf::Color::Green);
	mTitle.setString("SNAKE");
}

void MenuScreen::handleInput(sf::RenderWindow& window)
{

}

void MenuScreen::update(sf::Time delta)
{

}

void MenuScreen::render(sf::RenderWindow& window)
{
	window.draw(mTitle);
}