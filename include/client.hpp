
#ifndef CLIENT_HPP_
    #define CLIENT_HPP_
    #include <iostream>
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
    #include <SFML/Network.hpp>

    class Client
    {
        private:
            std::string _ip;
            sf::TcpSocket _socket;
            sf::SocketSelector selector;
            size_t port;
            int n;
            int val_read;
            struct hostent *host;
            struct in_addr **addr_list;
            std::string real_ip;
            sf::IpAddress serverAddress;
            void connect_client(sf::IpAddress& serverAddress);
            void initialize_address();
        public:
            Client(/* args */);
            ~Client();
            void create_client(size_t _port, std::string &machine);
            std::string read_messages();
            void send_messages(std::string _messages);
            std::string get_ip();
            std::string single_read_msg();
    };
#endif /* !CLIENT_HPP_ */
