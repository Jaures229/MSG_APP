#include "../../include/protocol.hpp"


std::string protocol::create_protocol(const std::string& username, const std::string &password)
{
    std::string msg = "CRT [" + username + "] " + "[" + password + "]\n";
    return msg;
}

std::string protocol::login_protocol(const std::string &username, const std::string &password)
{
    std::string msg = "LGT [" + username + "] " + "[" + password + "]\n";
    return msg;
}

std::string protocol::send_protocol(const std::string& messages)
{
    std::string msg = messages;
    return msg;
}

std::string protocol::info_protocol(const std::string& info)
{
    std::string msg = "INFO [" + info + "]\n";
    return msg;
}

std::string protocol::exit_protocol()
{
    return "EXT";
}
