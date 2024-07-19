#ifndef SERVER_HPP_
    #define SERVER_HPP_
    #include <iostream>
    #include <cstring>
    #include <unistd.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <memory>
    #include <vector>

    class Server_client
    {
        private:
            int _socket;
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

            int server_port;
            std::string _ip;
            int _height;
            int _widht;
            int max_sd;
            int max_cl;
            fd_set all_sockets;
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
