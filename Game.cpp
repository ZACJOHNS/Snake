#include "Game.hpp"

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);
const int Game::ScreenWidth = 640;
const int Game::ScreenHeight = 480;
std::shared_ptr<Screen> Game::mScreen = std::make_shared<MenuScreen>();

Game::Game()
: mWindow(sf::VideoMode(Game::ScreenWidth, Game::ScreenHeight), "SFML SNAKE")
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

		handleInput();
		updateStats(elapsedTime);
		render();
	}
}

void Game::processEvents()
{
	mScreen->handleInput(mWindow);

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
	mScreen->render(mWindow);

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

void Game::handleInput()
{
	mScreen->handleInput(mWindow);
}



