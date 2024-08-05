#include <iostream>
#include <string>
#include <iomanip>

std::string xor_encrypt_decrypt(const std::string& message, char key) {
    std::string output = message;
    for (size_t i = 0; i < message.size(); ++i) {
        output[i] = message[i] ^ key; // XOR operation
    }
    return output;
}

int main() {
    std::string message;
    char key;

    // Input the message and key
    std::cout << "Enter the message: ";
    std::getline(std::cin, message);
    std::cout << "Enter the key (single character): ";
    std::cin >> key;

    // Encrypt the message
    std::string encrypted = xor_encrypt_decrypt(message, key);
    
    // Display the encrypted message in hex format
    std::cout << "Encrypted (hex): ";
    for (unsigned char c : encrypted) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << (int)c; // Print in hex
    }
    std::cout << std::dec << std::endl; // Switch back to decimal output

    // Decrypt the message
    std::string decrypted = xor_encrypt_decrypt(encrypted, key);
    
    // Display the decrypted message
    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}
