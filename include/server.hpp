#ifndef SERVER_HPP_
    #define SERVER_HPP_
    #pragma once
    #include <iostream>
    #include <cstring>
    #include <unistd.h>
    #include <memory>
    #include <vector>
    #include <netinet/in.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <sys/socket.h>
    #include <sys/types.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <libgen.h>
    #include <unistd.h>
    #include <netdb.h>
    #include <sys/select.h>
    #include "stdlib.h"

    class Server_client
    {
        private:
            int _socket;
            std::string username, password;
            int id;
        public:
            Server_client(int socket);
            ~Server_client();
    };

    class Server
    {
        private:
            int server_socket;
            struct sockaddr_in server_address;
            int client_socket;
            fd_set readfds;
            std::vector<Server_client> clients;
            socklen_t server_address_len;
            int server_port;
            std::string _ip;
            int _height;
            int _widht;
            int max_sd;
            int max_cl;
            fd_set all_sockets;
            void create_new_client();
            void handle_client_data(int socket);
        public:
            Server();
            ~Server();
            void set_sprite();
            void launch_server(std::string ip, int port);
            void create_server_socket();
            void bind_server(int port, std::string ip);
            void listen_server();
            void server_select();
            void launch();

    };

#endif /* !SERVER_HPP_ */
