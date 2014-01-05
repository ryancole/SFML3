#ifndef _TEXTUREMANAGER_H_
#define _TEXTUREMANAGER_H_

#include <memory>
#include <SFML\Graphics.hpp>

enum class TextureId
{

    PlayerStanding

};

class TextureManager
{

public:

    ///////////////////////////////////////
    ///
    /// Load the Texture for the given Id
    ///
    ///////////////////////////////////////
    void load(TextureId id, const std::string& path);

    ///////////////////////////////////////
    ///
    /// Get the Texture for the given Id
    ///
    ///////////////////////////////////////
    sf::Texture& get(TextureId id);

private:

    std::map<TextureId, std::unique_ptr<sf::Texture>> m_textures;

};

#endif