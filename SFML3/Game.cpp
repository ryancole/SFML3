#include "Game.h"

using namespace sf;

/////////////////////////////////////
Game::Game()
    : m_window(VideoMode(800, 600), "SFML3")
{
    m_window.setVerticalSyncEnabled(true);

    m_player.setRadius(40.f);
    m_player.setPosition(100.f, 100.f);
    m_player.setFillColor(Color::Cyan);

    m_isMovingUp = false;
    m_isMovingLeft = false;
    m_isMovingDown = false;
    m_isMovingRight = false;
}

/////////////////////////////////////
void Game::run()
{
    Clock clock;
    auto timePerFrame = seconds(1.f / 60.f);
    auto timeSinceLastUpdate = Time::Zero;

    while (m_window.isOpen())
    {
        timeSinceLastUpdate += clock.restart();

        // process Winform events
        processEvents();

        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;

            // process Winform events
            processEvents();

            // update the state
            update(timePerFrame);
        }

        // render the frame
        render();
    }
}

/////////////////////////////////////
void Game::processEvents()
{
    Event event;

    while (m_window.pollEvent(event))
    {
        switch (event.type)
        {

            case Event::Closed:
                m_window.close();
                break;

            case Event::KeyPressed:
                handleInput(event.key.code, true);
                break;

            case Event::KeyReleased:
                handleInput(event.key.code, false);
                break;

        }
    }
}

/////////////////////////////////////
void Game::update(Time deltaTime)
{
    Vector2f movement(0.f, 0.f);

    if (m_isMovingUp)
    {
        movement.y -= 100.f;
    }

    if (m_isMovingDown)
    {
        movement.y += 100.f;
    }

    if (m_isMovingLeft)
    {
        movement.x -= 100.f;
    }

    if (m_isMovingRight)
    {
        movement.x += 100.f;
    }

    m_player.move(movement * deltaTime.asSeconds());
}

/////////////////////////////////////
void Game::render()
{
    m_window.clear();
    m_window.draw(m_player);
    m_window.display();
}

/////////////////////////////////////
void Game::handleInput(Keyboard::Key key, bool pressed)
{
    if (key == Keyboard::Key::W)
    {
        m_isMovingUp = pressed;
    }
    else if (key == Keyboard::Key::A)
    {
        m_isMovingLeft = pressed;
    }
    else if (key == Keyboard::Key::D)
    {
        m_isMovingRight = pressed;
    }
    else if (key == Keyboard::Key::S)
    {
        m_isMovingDown = pressed;
    }
}