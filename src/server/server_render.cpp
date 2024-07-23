#include "../../include/server.hpp"

void Server::set_sprite()
{

}

void Server::launch()
{

    FD_ZERO(&all_sockets);
    FD_ZERO(&readfds);
    FD_SET(server_socket, &all_sockets);
    max_sd = server_socket;

    while (1) {
        server_select();
    }
}

void Server::server_select()
{
    readfds = all_sockets;
    int activity = select(max_sd +1, &readfds, NULL, NULL, NULL);

    if (activity == -1) {
        perror("select");
        exit(84);
    }
    for (int i = 0; i <= max_sd; i++) {
        if (FD_ISSET(i, &readfds) != 1) {
            continue;
            }
        if (i == server_socket) {
            // New connection iconming
            std::cout << "COnnection...\n";
            
        } else {
            std::cout << "Nothing";
            // read data
        }
    }
}


void Server::create_new_client()
{
    int accept = accept(server_socket, NULL, NULL);
}