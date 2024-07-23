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
        if (FD_ISSET(i, &readfds)) {
            if (i == server_socket) {
                // New connection iconming
                create_new_client();
                
            } else {
                // read data
                handle_client_data(i);
            }
        }
    }
}

void Server::create_new_client()
{
    int acpt = accept(server_socket, (struct sockaddr *)&server_address, (socklen_t*)&server_address_len);

    if (acpt == -1) {
        perror("accept failed");
        exit(84);
    }

    Server_client new_client(acpt);
    clients.emplace_back(new_client);
    
    FD_SET(acpt, &all_sockets);
    if (acpt > max_sd) {
        max_sd = acpt;
    }

    std::cout << "New client connected: " << acpt << std::endl; // Log new connection
}

void Server::handle_client_data(int client_socket)
{
    char buffer[1024] = {0};
    int valread = read(client_socket, buffer, sizeof(buffer));

    if (valread == 0) {
        // Client disconnected
        std::cout << "Client disconnected: " << client_socket << std::endl;
        close(client_socket);
        FD_CLR(client_socket, &all_sockets);
        // Remove client from the list (if necessary)
    } else if (valread < 0) {
        perror("read error");
    } else {
        // Process the received data
        std::cout << "Received data from client " << client_socket << ": " << buffer << std::endl;
        // Optionally, send a response back to the client
    }
}