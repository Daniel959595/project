#pragma once

#include <SFML/Graphics.hpp>

enum class Figure
{
    m_king = 0,
    m_warrior,
    m_mage,
    m_thief,
    m_ork,
    m_wall,
    m_fire,
    m_gate,
    m_key,
    m_teleporter,
    m_throne,
    m_gift,
    m_dwarf,
};

class Figures
{
public :
    Figures();
	sf::Texture& getFigure(Figure figure);

private:
    sf::Texture m_king;
    sf::Texture m_warrior;
    sf::Texture m_mage;
    sf::Texture m_thief;
    sf::Texture m_ork;
    sf::Texture m_wall;
    sf::Texture m_fire;
    sf::Texture m_gate;
    sf::Texture m_key;
    sf::Texture m_teleporter;
    sf::Texture m_throne;
    sf::Texture m_gift;
    sf::Texture m_dwarf;
};