#ifndef CHANNEL_HPP_
    #define CHANNEL_HPP_
    #include <iostream>
    #include <string>
    #include <vector>
    #include <iostream>
    #include <sys/types.h>
    #include <sys/socket.h>
    #include <unistd.h>
    #include <cstring>
    #include "protocol.hpp"
    class Channel {
        public:
            Channel(const std::string& name, int type) {
                _channel_name = name;
                _channel_type = type;
            }
            ~Channel() {}
            void add_user(std::string user, int id);
            int get_channel_type(void) { return _channel_type;}
            std::string get_channel_name(void) {return _channel_name;}
        private:
            void add_message(std::string message, int user);
            void send_messages(std::string msg, int user);
            bool isUserConnected(int socket);
            std::string name;
            std::vector<std::pair<std::string, int>> _users;
            std::vector<std::pair<std::string, int>> _messages;
            int _channel_type;
            std::string _channel_name;
    };
#endif /* !CHANNEL_HPP_ */
