#ifndef SERVER_HPP_
    #define SERVER_HPP_
    #include <iostream>
    #include <cstring>
    #include <unistd.h>
    #include <sys/socket.h>
    #include <arpa/inet.h>
    #include <memory>
    #include <vector>
    #include <SFML/Graphics.hpp>
    #include <SFML/Audio.hpp>
    #include <SFML/System.hpp>
    #include <SFML/Window.hpp>

    class Server_client
    {
        private:
            int _socket;
        public:
            Server_client(int socket);
            ~Server_client();
    };

    class Server_Render
    {
        private:
            sf::RenderWindow windows;
            int _height;
            int _widht;
            int nb_clients;
            void create_windows(int height, int widht);
        public:
            Server_Render();
            ~Server_Render();
            void launch(int port, std::string ip, int height, int widht);
    };

    class Server
    {
        private:
            int server_socket;
            struct sockaddr_in server_address;
            int client_socket;
            fd_set read_fds;
            std::vector<Server_client> clients;

            int server_port;
            std::string _ip;
            sf::RenderWindow windows;
            int _height;
            int _widht;
            void create_windows(int height, int widht);

            sf::Event event;
        public:
            Server(/* args */);
            ~Server();
            void launch_server(std::string ip, int port);
            void create_server_socket();
            void bind_server(int port, std::string ip);
            void listen_server();
            void server_select();
            void launch();
    };

#endif /* !SERVER_HPP_ */
