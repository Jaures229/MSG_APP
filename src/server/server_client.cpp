#include "../../include/server.hpp"

std::string to_hex_string(const std::string &input)
{
    std::ostringstream oss;
    for (unsigned char c : input) {
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)c; // Convert each char to hex
    }
    return oss.str();
}

void Server::init_new_client(int sock, char *buffer)
{
    std::string input = std::string(buffer);
    std::regex pattern(R"(\[(.*?)\])"); // Regex to match content within brackets
    std::smatch matches;
    std::vector<std::string> sequences; // Vector to store extracted sequences
    char key;

    // Iterate through all matches
    auto it = std::sregex_iterator(input.begin(), input.end(), pattern);
    auto end = std::sregex_iterator();
    unsigned long long hexValue = 0;

    while (it != end) {
        sequences.push_back(it->str(1)); // Store the content without brackets
        ++it;
    }

    if (check_client_exist(sequences[0]) == 1) { // check if the client exist in the server
        std::cout << "Client already exist in the server\n";
        int msg = write(sock, "ko\n", 3);
    } else {
        //std::cout << sequences[0];
        key = sequences[1][0];

        std::string encrypted = _server_security.encrypt(sequences[1], key);
        
        for (auto& client : clients) {
            if (client.get_id() == sock) {
                client.set_username(sequences[0]);
                client.set_password(_server_security.encrypt(sequences[1], key));
                client.set_log(true);

                std::cout << "[Server]: New client: " << client.get_username() << " with hash ";
                dprintf(sock, "%s", "ok\n");

            }
        }

        for (unsigned char c : encrypted) {
            std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)c; // Print in hex
        }
        std::cout << "\n";
    }
}

int Server::check_client_exist(std::string &name)
{
    for (int i = 0; i < clients.size(); i++) {
        if (clients[i].get_username() == name) {
            return 1;
        }
    }
    return 0;
}

void Server::login_client(int sock, char *buffer)
{
    std::string input = std::string(buffer);
    std::regex pattern(R"(\[(.*?)\])"); // Regex to match content within brackets
    std::smatch matches;
    std::vector<std::string> sequences; // Vector to store extracted sequences
    char key;
    bool clientFound = false;

    // Iterate through all matches
    auto it = std::sregex_iterator(input.begin(), input.end(), pattern);
    auto end = std::sregex_iterator();
    unsigned long long hexValue = 0;

    while (it != end) {
        sequences.push_back(it->str(1)); // Store the content without brackets
        ++it;
    }

    // Check if the client is in the list of disconnected

    for (int i = 0; i < clients.size(); i++) {
        if (clients[i].get_id() == sock) {
            for (int j = 0; j < disconnect_client.size(); j++) {
                if (disconnect_client[j].get_username() == sequences[0] && _server_security.decrypt(disconnect_client[j].get_password(), sequences[1][0]) == sequences[1]) {
                    clients[i].set_username(sequences[0]);
                    clients[i].set_password(disconnect_client[j].get_password());
                    clients[i].set_caption(disconnect_client[j].get_caption());

                    // Erase the disconnected client
                    erase_client_at(sequences[0]);

                    // Client login
                    clientFound = true; // Client found
                    std::cout << "Client " << sequences[0] << " sucessfully login\n";
                    int msg = write(sock, "ok\n", 3);
                    break; // Exit the inner loop since we found a match
                }
            }
            if (clientFound) {
                break; // Exit the outer loop if the client was found
            }
        }
    }

    // Check if the client was not found in the disconnected list
    if (!clientFound) {
        int msg = write(sock, "ko\n", 3);
        std::cout << "Error while login client USERNAME or PASSWORD incorrect" << std::endl;
    }
}

void Server::quit_client(int sock)
{
    //write(r_socket, "221 Goodbye\n", 12);
    shutdown(sock, SHUT_RDWR);
    close(sock);
    FD_CLR(sock, &all_sockets);
    //client->is_logged_in = false;

    // save the disconnect client in the disconect vector by erasing it of the client vec

    for (auto it = clients.begin(); it != clients.end();) {
        if (it->get_id() == sock) {
            // create a new disconnected client with all the user of the last user
            Server_client new_disconnect_client(0);
            new_disconnect_client.set_username(it->get_username());
            new_disconnect_client.set_password(it->get_password());
            new_disconnect_client.set_caption(it->get_caption());

            // real erase
            disconnect_client.emplace_back(new_disconnect_client);
            it = clients.erase(it);
        } else {
            ++it;
        }
    }
}

void Server::erase_client_at(std::string name)
{
    for (auto it = disconnect_client.begin(); it != disconnect_client.end();) {
        if (it->get_username() == name) {
            it = disconnect_client.erase(it);
        } else {
            ++it;
        }
    }
}
