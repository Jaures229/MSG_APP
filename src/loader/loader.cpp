#include "../../include/loader.hpp"

sf::Texture& AssetManager::getTexture(const std::string& filename)
{
    if (m_textures.find(filename) == m_textures.end()) {
        m_textures[filename].loadFromFile(filename);
    }

    return m_textures[filename];
}

sf::Font& AssetManager::getFont(const std::string& filename)
{
    if (m_fonts.find(filename) == m_fonts.end()) {
        m_fonts[filename].loadFromFile(filename);
    }

    return m_fonts[filename];
}

sf::SoundBuffer& AssetManager::getSoundBuffer(const std::string& filename)
{
    if (m_soundBuffers.find(filename) == m_soundBuffers.end()) {
        m_soundBuffers[filename].loadFromFile(filename);
    }

    return m_soundBuffers[filename];
}
