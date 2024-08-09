#ifndef PROTOCOL_HPP_
    #define PROTOCOL_HPP_
    #include <iostream>
    #include <string>

    namespace protocol
    {
        std::string create_protocol(const std::string& username, const std::string& password);
        std::string login_protocol(const std::string& username, const std::string& password);
        std::string send_protocol(const std::string& message);
        std::string info_protocol(const std::string& info);
        std::string exit_protocol();
    } 
#endif /* !PROTOCOL_HPP_ */
