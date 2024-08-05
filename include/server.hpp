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
    #include <map>
    #include <bits/stdc++.h>
    #include <regex>
    #include "security.hpp"

    class Server_client
    {
        private:
            int _socket;
            std::string _username, _password;
            int _id;
            bool _is_login;
            int ok;
            std::string client_info;
            std::string _info;
        public:
            Server_client(int socket);
            ~Server_client();
            void set_log(bool connection) {_is_login = connection; ok = connection;}
            bool get_log() { return _is_login;}
            int get_id() { return _id;}
            void set_id(int id) { _id = id;}
            void set_username(std::string username) { _username = username;}
            std::string get_username() const { return _username;}
            void set_password(std::string password) { _password = password;}
            std::string get_password() const { return _password;}
            void set_caption(std::string info) { _info = info;}
            std::string get_caption() { return _info;}
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
            std::vector<Server_client> client_vec;
            std::vector<Server_client> disconnect_client;
            int server_port;
            std::string _ip;
            int _height;
            int _widht;
            int max_sd;
            int max_cl;
            fd_set all_sockets;
            void create_new_client();
            void handle_client_data(int socket);
            void check_protocol(int sock, char *buffer);
            void init_new_client(int sock, char *buffer);
            bool check_log(int sock, bool log);
            security _server_security;
            int check_client_exist(std::string name);
            void login_client(int sock, char *buffer);
            void quit_client(int sock);
            void erase_client_at(std::string name);
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
