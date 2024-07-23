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
    #include "../src/graphic/imgui/imgui.h"
    #include "../src/graphic/imgui-SFML.h"

    class Graphic
    {
        private:
            sf::RenderWindow window;
        public:
            Graphic(/* args */);
            ~Graphic();
    };
#endif /* !GRAPHIC_HPP_ */
