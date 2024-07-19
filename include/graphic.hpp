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
    #include <TGUI/TGUI.hpp>
    #include <TGUI/Core.hpp>
    #include <TGUI/Backends/SFML.hpp>
    #include <TGUI/AllWidgets.hpp>

    class Graphic
    {
        private:
            sf::RenderWindow window;
        public:
            Graphic(/* args */);
            ~Graphic();
    };
#endif /* !GRAPHIC_HPP_ */
