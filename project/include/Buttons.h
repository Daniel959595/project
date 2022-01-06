#pragma once

#include <SFML/Graphics.hpp>

enum class Button
{
    ButtonRun = 0,
    ButtonRun2,
    ButtonHelp,
    ButtonHelp2,
    ButtonExit,
    ButtonExit2,

};

class Buttons
{
public:
    Buttons();
    sf::Texture& getButton(Button button);

private:
    sf::Texture m_ButtonRun;
    sf::Texture m_ButtonRun2;
    sf::Texture m_ButtonHelp;
    sf::Texture m_ButtonHelp2;
    sf::Texture m_ButtonExit;
    sf::Texture m_ButtonExit2;
    
    //more picture nedeed!
};