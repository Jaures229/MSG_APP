#include "../../include/server.hpp"

Server_client::Server_client(int socket)
{
    _socket = socket;   
}
    
Server_client::~Server_client()
{
    //close(_socket);
}
