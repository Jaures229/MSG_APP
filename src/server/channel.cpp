#include "../../include/channel.hpp"


// function use to check if a user is at the moment connected to ther server
bool Channel::isUserConnected(int socket)
{
    char buffer;
    // Use MSG_PEEK to check if data is available
    ssize_t result = recv(socket, &buffer, 1, MSG_PEEK);
    
    if (result == 0) {
        // Connection has been closed
        return false;
    } else if (result < 0) {
        // An error occurred
        perror("recv");
        return false;
    }
    
    // If we reach here, the user is still connected
    return true;
}

// function use to save a save in a vector
void Channel::add_user(std::string user, int id)
{
    std::pair<std::string, int> p{user, id};

    _users.emplace_back(p);
}

// function use to save a message
void Channel::add_message(std::string msg, int user)
{
    std::pair<std::string, int> p{msg, user};

    _users.emplace_back(p);
}

// function use to send a messages to all the user in the channel

void Channel::send_messages(std::string msg, int user)
{

    // check if ali    
}
