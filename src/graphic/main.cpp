#include "../../include/graphic.hpp"
#include <vector>

std::pair<std::string, int>graphic_arg(int ac, char **av)
{
    if (ac != 3) {
        std::cout << "./@Server [LAN IP ADRESS] [PORT]\n";
        exit(84);
    } else {
        std::pair<std::string, int> p;
        p.first = std::string(av[1]);
        p.second = std::stoi(av[2]);
        std::cout << " ip == " <<  p.first << " Port == " << p.second << std::endl;
        return p;
    }
    std::pair<std::string, int> p;
    return p;
}

int main(int ac, char **av)
{
    std::pair<std::string, int> arg = graphic_arg(ac, av);
    Graphic graph;

    try {
        graph.launch(arg.second, arg.first);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
