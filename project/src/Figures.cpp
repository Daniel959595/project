#include "Figures.h"

Figures::Figures()
{
    m_king.loadFromFile("king.png");
    m_warrior.loadFromFile("warrior.png");
    m_mage.loadFromFile("mage.png");
    m_thief.loadFromFile("thief.png");
    m_ork.loadFromFile("ork.png");
    m_wall.loadFromFile("wall.png");
    m_fire.loadFromFile("fire.png");
    m_gate.loadFromFile("gate.png");
    m_key.loadFromFile("key.png");
    m_teleporter.loadFromFile("teleporter.png");
    m_throne.loadFromFile("throne.png");
}

sf::Texture& Figures::getFigure(Figure figure)
{
    switch (figure)
    {
    case Figure::m_king:
        return m_king;
        break;
    case Figure::m_warrior:
        return m_warrior;
        break;

    case Figure::m_mage:
        return m_mage;
        break;

    case Figure::m_thief:
        return m_thief;
        break;

    case Figure::m_ork:
        return m_ork;
        break;

    case Figure::m_wall:
        return m_wall;
        break;

    case Figure::m_fire:
        return m_fire;
        break;

    case Figure::m_gate:
        return m_gate;
        break;

    case Figure::m_key:
        return m_key;
        break;

    case Figure::m_teleporter:
        return m_teleporter;
        break;

    case Figure::m_throne:
        return m_throne;
        break;

    default:
        return m_king;
        break;
    }
}
