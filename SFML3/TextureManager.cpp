#include <cassert>
#include "TextureManager.hpp"

using namespace sf;
using namespace std;

///////////////////////////////////////
void TextureManager::load(TextureId id, const string& path)
{

    unique_ptr<Texture> texture(new Texture());

    if (!texture->loadFromFile(path))
        throw runtime_error("Failed to load texture: " + path);

    auto inserted = m_textures.insert(make_pair(id, move(texture)));

    assert(inserted.second);

}

///////////////////////////////////////
Texture& TextureManager::get(TextureId id)
{

    auto texture = m_textures.find(id);

    assert(texture != m_textures.end());

    return *texture->second;

}