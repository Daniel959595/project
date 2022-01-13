#include "Buttons.h"

Buttons::Buttons()
{
    m_ButtonRun.loadFromFile("ButtonRun.png");
    m_ButtonRun2.loadFromFile("ButtonRun2.png");
    m_ButtonHelp.loadFromFile("ButtonHelp.png");
    m_ButtonHelp2.loadFromFile("ButtonHelp2.png");
    m_ButtonExit.loadFromFile("ButtonExit.png");
    m_ButtonExit2.loadFromFile("ButtonExit2.png");
    m_BackGround.loadFromFile("BackGround.png");

    m_ButtonReturn.loadFromFile("ButtonReturn.png");
}

sf::Texture& Buttons::getButton(Button button)
{
    switch (button)
    {
    case Button::ButtonRun:
        return m_ButtonRun;
        break;

    case Button::ButtonRun2:
        return m_ButtonRun2;
        break;

    case Button::ButtonHelp:
        return m_ButtonHelp;
        break;

    case Button::ButtonHelp2:
        return m_ButtonHelp2;
        break;

    case Button::ButtonExit:
        return m_ButtonExit;
        break;

    case Button::ButtonExit2:
        return m_ButtonExit2;
        break;

    case Button::ButtonReturn:
        return m_ButtonReturn;
        break;

    default:
        return m_ButtonExit2;
        break;
    }
}

sf::Texture& Buttons::getBackGround()
{
    return m_BackGround;
}



