#ifndef SECURITY_HPP_
    #define SECURITY_HPP_
    #include <iostream>
    #include <string>
    #include <regex>
    #include <vector>

    class security
    {
        private:
            std::string xor_encrypt_decrypt(const std::string &input, char key);
        public:
            security();
            ~security();
            std::string encrypt(const std::string &input, char key);
            std::string decrypt(const std::string &input, char key);
            
    };
#endif /* !SECURITY_HPP_ */
