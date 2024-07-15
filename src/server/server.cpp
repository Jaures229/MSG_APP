#include "../../include/server.hpp"

Server::Server()
{

}
    
Server::~Server()
{

}

void Server::create_server_socket()
{
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        std::cerr << "Erreur lors de la création du socket serveur" << std::endl;
        exit(84);
    }
}

void Server::bind_server(int port, std::string ip)
{
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ip.c_str());
    server_address.sin_port = htons(port);

    if (bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        std::cerr << "Erreur lors de la liaison du socket" << std::endl;
        exit(84);
    }
}

void Server::listen_server()
{
    if (listen(server_socket, 5) == -1) {
        std::cerr << "Erreur lors de l'écoute des connexions" << std::endl;
        exit(84);
    }
}
