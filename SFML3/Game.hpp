#ifndef _GAME_H_
#define _GAME_H_

#include <SFML\Graphics.hpp>
#include "TextureManager.hpp"

class Game
{

public:

    ///////////////////////////////////////
    ///
    /// Ctor
    ///
    ///////////////////////////////////////
    Game();

    ///////////////////////////////////////
    ///
    /// Run the Game's main loop
    ///
    ///////////////////////////////////////
    void run();

private:

    ///////////////////////////////////////
    ///
    /// Handle Winform events
    ///
    ///////////////////////////////////////
    void processEvents();

    ///////////////////////////////////////
    ///
    /// Update the Game's state
    ///
    ///////////////////////////////////////
    void update(sf::Time deltaTime);

    ///////////////////////////////////////
    ///
    /// Render the Game's current frame
    ///
    ///////////////////////////////////////
    void render();

    ///////////////////////////////////////
    ///
    /// Handle device input
    ///
    ///////////////////////////////////////
    void handleInput(sf::Keyboard::Key key, bool pressed);

private:

    sf::Sprite m_player;
    sf::RenderWindow m_window;

private:

    bool m_isMovingUp;
    bool m_isMovingDown;
    bool m_isMovingLeft;
    bool m_isMovingRight;

    TextureManager m_textures;

};

#endif
