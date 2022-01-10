#pragma once

#include <SFML/Graphics.hpp>


class Timers
{
public:
	Timers();

	bool handleTime();
	bool handleTimer();
	void restartTimer();
	int getTimePassed();
	void draw(sf::RenderWindow& window);
	void startGameTime();
	void setIsTimer(bool statemant, int limitTime = 180);
	void addTime(int seconds);
	void redTime(int seconds);

private:
	sf::Clock m_gameClock;
	sf::Clock m_timer;

	sf::Font m_font;
	sf::Text m_timeText;
	sf::Text m_timerText;

	bool m_isTimer = false;
	int m_limitTime;  //seconds.
};