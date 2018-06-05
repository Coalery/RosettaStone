/*************************************************************************
> File Name: GameManager.cpp
> Project Name: Hearthstone++
> Author: Chan-Ho Chris Ohk
> Purpose: Game manager of Hearthstone++ GUI program.
> Created Time: 2018/05/31
> Copyright (c) 2018, Chan-Ho Chris Ohk
*************************************************************************/
#include <Manager/GameManager.h>

namespace Hearthstonepp
{
GameManager* GameManager::GetInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new GameManager();

        const sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
        m_instance->m_windowWidth = videoMode.width / 2;
        m_instance->m_windowHeight = videoMode.height / 2;
    }

    return m_instance;
}

void GameManager::Start(sf::RenderWindow* window)
{
    // Set the window
    m_window = window;
}

void GameManager::Finish()
{
    RemoveBackground();
}

void GameManager::SetBackground(const char* imageFileName)
{
    m_backgroundTexture.loadFromFile(std::string(IMAGES_DIR) + imageFileName);
    m_backgroundSprite.setTexture(m_backgroundTexture);
    m_backgroundSprite.setOrigin(0.0f, 0.0f);
    m_backgroundSprite.setPosition(0.0f, 0.0f);
    m_backgroundSprite.setScale(
        GetWindowWidth() / m_backgroundSprite.getLocalBounds().width,
        GetWindowHeight() / m_backgroundSprite.getLocalBounds().height);
}

void GameManager::RemoveBackground()
{
    m_backgroundTexture.create(1, 1);
    m_backgroundSprite.setTexture(m_backgroundTexture);
}

void GameManager::ClearDrawList()
{
    RemoveBackground();
}

bool GameManager::IsOpen() const
{
    bool isOpened = m_window->isOpen();

    // Clear screen
    m_window->clear(sf::Color::White);

    return isOpened;
}

void GameManager::CloseWindow() const
{
    m_window->close();
}

bool GameManager::HasWindowFocus() const
{
    return m_window->hasFocus();
}

void GameManager::Draw()
{
    // Draw the background
    m_window->draw(m_backgroundSprite);
}

int GameManager::GetWindowWidth() const
{
    return m_windowWidth;
}

int GameManager::GetWindowHeight() const
{
    return m_windowHeight;
}
}