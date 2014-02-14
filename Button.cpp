#include "Button.hpp"

#include <iostream>
using namespace std;

Button::Button()
: mIsClicked(false)
, mFont()
, mText()
{
	mFont.loadFromFile("Media/Minecraftia.ttf");
	mButtonShape.setFillColor(sf::Color::Green);
}

void Button::setString(std::string buttonText)
{
	mText.setFont(mFont);
	mText.setString(buttonText);
	mText.setCharacterSize(30);
	mText.setColor(sf::Color::Black);
	mText.setPosition(mButtonShape.getPosition().x, mButtonShape.getPosition().y);
}

void Button::setPosition(sf::Vector2f position)
{
	mButtonShape.setPosition(position.x, position.y);
}

void Button::setSize(sf::Vector2f size)
{
	mButtonShape.setSize(size);
}

void Button::handleInput(sf::RenderWindow& window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		/// get the mouse coordinates relative to the render window
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		sf::Vector2f buttonPosition = mButtonShape.getPosition();

		if (mousePosition.x >= buttonPosition.x &&
		    mousePosition.x <= buttonPosition.x + mButtonShape.getSize().x &&
		    mousePosition.y >= buttonPosition.y &&
		    mousePosition.y <= buttonPosition.y + mButtonShape.getSize().y)
		{
			mIsClicked = true;
		}
	}
}

void Button::draw(sf::RenderTarget& renderTarget, sf::RenderStates states) const
{
	renderTarget.draw(mButtonShape, sf::RenderStates::Default);
	renderTarget.draw(mText, sf::RenderStates::Default);
}

bool Button::isClicked()
{
	return mIsClicked;
}