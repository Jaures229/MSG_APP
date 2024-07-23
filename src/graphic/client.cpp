#include "../../include/client.hpp"

Client::Client(/* args */)
{

}

Client::~Client()
{

}

void Client::create_client(size_t _port, std::string &machine)
{
    // Set the host and port to the machine.
    if (machine.size() == 0) {
        _ip = "localhost";
    } else {
        port = _port;
        _ip = machine;
    }
    initialize_address();
    sf::IpAddress serverAddress(real_ip);
    connect_client(serverAddress);
}

void Client::connect_client(sf::IpAddress& serverAddress)
{
    if (_socket.connect(serverAddress, port) != sf::Socket::Done) {
        std::cerr << "Erreur lors de la connexion au serveur." << std::endl;
        std::exit(84);
    }
    selector.add(_socket);
}

void Client::initialize_address()
{
    host = gethostbyname(_ip.c_str());
    // Exit with 80 characters.
    if (host == NULL) {
        perror("hostname");
        std::exit(84);
    }
    addr_list = (struct in_addr **)host->h_addr_list;

    real_ip = inet_ntoa(*addr_list[0]);
}

std::string Client::read_messages()
{
    char buffer[1024];
    std::size_t received = 0;
    sf::Socket::Status status = _socket.receive(buffer, sizeof(buffer), received);
    if (status == sf::Socket::Done) {
        buffer[received] = '\0'; // Null-terminate the buffer
        //std::cout << "Message reçu du serveur : " << buffer << std::endl;
        return std::string(buffer);
    } else
        return "";
}

std::string Client::get_ip()
{
    return real_ip;
}

void Client::send_messages(std::string _messages)
{
    if (_socket.send(_messages.c_str(), _messages.length()) != sf::Socket::Done) {
        std::cerr << "Erreur lors de l'envoi du message." << std::endl;
    }
}

std::string Client::single_read_msg()
{
    float time = 0.001f;
    char buffer[1024];
    std::size_t received = 0;

    if (selector.wait(sf::seconds(time))) {
        if (selector.isReady(_socket)) {
            sf::Socket::Status status = _socket.receive(buffer, sizeof(buffer), received);
            if (status == sf::Socket::Done) {
                buffer[received] = '\0';
                //std::cout << "Message reçu du serveur : " << buffer << std::endl;
                return std::string(buffer);
            } else
                return "";
        }
    }
    return "";
}
