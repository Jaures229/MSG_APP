#include "../../include/server.hpp"

Server_Render::Server_Render(/* args */)
{

}

Server_Render::~Server_Render()
{

}

void Server_Render::launch(int port, std::string ip, int height, int widht)
{

}

void Server_Render::create_windows(int height, int widht)
{
}

void Server::create_windows(int height, int widht)
{
    // windows.create(sf::VideoMode(height, widht), "SERVER_RENDER");
}

void Server::launch()
{
    windows.create(sf::VideoMode(1920, 1080), "SERVER_RENDER");

    while (windows.isOpen()) {
        while (windows.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                windows.close();
                close(server_socket);
            }
        }
        server_select();
    }
}

void Server::server_select()
{
    
}