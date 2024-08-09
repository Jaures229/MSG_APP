#ifndef GRAPHIC_HPP_
    #define GRAPHIC_HPP_
    #include <iostream>
    #include <fstream>
    #include <sstream>
    #include <vector>
    #include <SFML/Graphics.hpp>
    #include <SFML/Audio.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Window.hpp>
    #include "imgui.h"
    #include "imgui-SFML.h"
    #include "client.hpp"

    class Graphic
    {
        private:
            sf::RenderWindow window;
            Client graphic_client;
            sf::Clock deltaClock;
            sf::Event event;
            void graphic_aunthentificate();
            void update();
            void Login();
            void menu_bar();
            void chat_widget();
            void group_widget();
            bool showLoginWindow;
            bool has_authentificate;
            char username[128];
            char password[128];
            bool showPassword;
        public:
            Graphic(/* args */);
            ~Graphic();
            void launch(int port, std::string machine);
            void open();
    };
#endif /* !GRAPHIC_HPP_ */
