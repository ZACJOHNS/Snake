#include "Game.h"

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game()
: mWindow(sf::VideoMode(640, 480), "SFML SNAKE")
, mFont()
, mStatText()
, mStatUpdateTime()
, mStatNumFrames(0)
{
	mFont.loadFromFile("Media/Sansation.ttf");
	mStatText.setFont(mFont);
	mStatText.setPosition(5.f, 5.f);
	mStatText.setCharacterSize(10);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
			update(TimePerFrame);
		}

		updateStats(elapsedTime);
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			mWindow.close();
	}
}

void Game::update(sf::Time elapsedTime) 
{
	// update class
}

void Game::render() 
{
	mWindow.clear();
	mWindow.draw(mStatText);
	mWindow.display();
}

void Game::updateStats(sf::Time elapsedTime)
{
	mStatUpdateTime += elapsedTime;
	mStatNumFrames += 1;

	if (mStatUpdateTime >= sf::seconds(1.0f))
	{
		mStatText.setString(
			"Frames / Second = " + std::to_string(mStatNumFrames) + "\n" +
			"Time / Update = " + std::to_string(mStatUpdateTime.asMicroseconds() / mStatNumFrames) + "us");

		mStatUpdateTime -= sf::seconds(1.0f);
		mStatNumFrames = 0;
	}
}

