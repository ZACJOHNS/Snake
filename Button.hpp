#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Mouse.hpp>

#include <string>

class Button : public sf::Drawable
{
public:
	Button();
	void setString(std::string buttonText);
	void setPosition(sf::Vector2f position);
	void setSize(sf::Vector2f size);

	void handleInput(sf::RenderWindow& window);
	void draw(sf::RenderTarget&, sf::RenderStates states) const override;

	bool isClicked();

private:
	sf::RectangleShape mButtonShape;
	sf::Font mFont;
	sf::Text mText;
	bool mIsClicked;
};

#endif