#include "../../include/security.hpp"

security::security(/* args */)
{

}

security::~security()
{

}

std::string security::xor_encrypt_decrypt(const std::string& message, char key)
{
    std::string output = message;

    for (size_t i = 0; i < message.size(); ++i) {
        output[i] = message[i] ^ key; // XOR operation
    }
    return output;
}
std::string security::encrypt(const std::string &input, char key)
{
    return this->xor_encrypt_decrypt(input, key);
}

std::string security::decrypt(const std::string &encrypt, char key)
{
    return this->xor_encrypt_decrypt(encrypt, key);
}
