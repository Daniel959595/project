#include "Timers.h"

Timers::Timers()
{
	m_font.loadFromFile("C:/Windows/Fonts/arial.ttf");
	m_timeText.setFont(m_font);
	m_timeText.setCharacterSize(60);
	m_timeText.setFillColor(sf::Color::Black);
	m_timeText.setPosition(sf::Vector2f(80.0f, 50.0f));
	m_timeText.setOutlineThickness(4);
	m_timeText.setOutlineColor(sf::Color::Red);

	m_timerText.setFont(m_font);
	m_timerText.setCharacterSize(60);
	m_timerText.setFillColor(sf::Color::Black);
	m_timerText.setPosition(sf::Vector2f(80.0f, 200.0f));
	m_timerText.setOutlineThickness(4);
	m_timerText.setOutlineColor(sf::Color::Red);
}

bool Timers::handleTime()
{
	int indexMin = m_gameClock.getElapsedTime().asSeconds() / 60;
	int indexSec = static_cast<int>(m_gameClock.getElapsedTime().asSeconds()) % 60;
	m_timeText.setString("Time played:\n" + std::to_string(indexMin) + ":" + std::to_string(indexSec));

	if (m_isTimer)
		return handleTimer();
	else
		return true;
}

bool Timers::handleTimer()
{
	int indexMin = (m_limitTime - m_timer.getElapsedTime().asSeconds()) / 60;
	int indexSec = static_cast<int>(m_limitTime - m_timer.getElapsedTime().asSeconds()) % 60;
	m_timerText.setString("Time left:\n" + std::to_string(indexMin) + ":" + std::to_string(indexSec));

	if (indexMin <= 0 && indexSec <= 0)
		return false;
	return true;
}

void Timers::restartTimer()
{
	m_timer.restart();
}

int Timers::getTimePassed()
{
	return m_gameClock.getElapsedTime().asSeconds();
}

void Timers::draw(sf::RenderWindow& window)
{
	window.draw(m_timeText);
	if (m_isTimer)
		window.draw(m_timerText);
}

void Timers::startGameTime()
{
	m_gameClock.restart();
}

void Timers::setIsTimer(bool statement, float limitTime)
{
	m_isTimer = statement;
	if (statement)
	{
		restartTimer();
		m_limitTime = limitTime;
	}
}

void Timers::addTime(int seconds)
{
	m_limitTime += seconds;
}

void Timers::redTime(int seconds)
{
	m_limitTime -= seconds;
}