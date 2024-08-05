#ifndef CHANNEL_HPP_
    #define CHANNEL_HPP_
    #include <iostream>
    #include <string>
    #include <vector>
    class Channel {
        public:
            Channel();
            ~Channel();
        private:
        std::string name;
        std::vector<std::string> messages;
    };
#endif /* !CHANNEL_HPP_ */
