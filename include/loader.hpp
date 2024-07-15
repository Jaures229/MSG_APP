#ifndef LOADER_HPP_
    #define LOADER_HPP_
    #include <iostream>
    #include <map>
    #include <string>
    #include <SFML/Graphics.hpp>
    #include <SFML/Audio.hpp>

    class AssetManager {
        public:
            static AssetManager& getInstance() {
                static AssetManager instance;
                return instance;
            }
            sf::Texture& getTexture(const std::string& filename);
            sf::Font& getFont(const std::string& filename);
            sf::SoundBuffer& getSoundBuffer(const std::string& filename);

        private:
            AssetManager() {}
            AssetManager(const AssetManager&) = delete;
            AssetManager& operator=(const AssetManager&) = delete;
            std::map<std::string, sf::Texture> m_textures;
            std::map<std::string, sf::Font> m_fonts;
            std::map<std::string, sf::SoundBuffer> m_soundBuffers;
    };

#endif /* !LOADER_HPP_ */
