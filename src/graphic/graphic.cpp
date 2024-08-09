#include "../../include/graphic.hpp"
#include "../../include/protocol.hpp"

Graphic::Graphic()
{
    username[0] = '\0';
    password[0] = '\0';
    showPassword = false;
}

Graphic::~Graphic()
{
    ImGui::SFML::Shutdown();
}

void Graphic::graphic_aunthentificate()
{
    Login();
}

void Graphic::launch(int port, std::string machine)
{
    has_authentificate = false;
    showLoginWindow = true;
    graphic_client.create_client(port, machine);
    open();
}

void Graphic::open()
{
    window.create(sf::VideoMode(1920, 1080), "Client");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                graphic_client.send_messages(protocol::exit_protocol());
                window.close();
            }
            // Pass events to ImGui
            ImGui::SFML::ProcessEvent(event);
        }
        update();
    }
}

void Graphic::update()
{
    ImGui::SFML::Update(window, deltaClock.restart());
    window.clear(sf::Color(240, 240, 255)); // Light purple background
    if (!has_authentificate) {
        graphic_aunthentificate();
    }
    ImGui::SFML::Render(window);
    window.display();

}

void Graphic::Login()
{
    const char* errorMessage = nullptr; // Pointer for error message

    if (showLoginWindow) {
        ImGui::SetNextWindowSize(ImVec2(500, 300)); // Set window size (width, height)
        ImGui::SetNextWindowPos(ImVec2(200, 150));  // Set window position (x, y)
        // Create the ImGui window
        ImGui::Begin("Login/Register");

        ImGui::Text("USERNAME");
        ImGui::InputText("##Username", username, sizeof(username));
        ImGui::Text("PASSWORD");
        ImGui::InputText("##Password", password, sizeof(password), showPassword ? ImGuiInputTextFlags_None : ImGuiInputTextFlags_Password);
        ImGui::Checkbox("Show Password", &showPassword);

        if (ImGui::Button("Register")) {
            if (username[0] == '\0' || password[0] == '\0') {
                errorMessage = "Username and password cannot be empty!";
            } else {
                
                // Handle login logic here
                std::string msg = protocol::create_protocol(std::string(username), std::string(password));
                std::cout << msg << std::endl;
                graphic_client.send_messages(msg);
                std::string recv_msg = graphic_client.read_messages();

                if (recv_msg == "ok\n") {
                    // ok now the user is login
                    errorMessage = nullptr; // Clear error message on success
                    showLoginWindow = false;
                    has_authentificate = true;
                } else {
                    errorMessage = recv_msg.c_str();
                }
            }
        }

        ImGui::Text("OR");
        if (ImGui::Button("Login")) {
            if (username[0] == '\0' || password[0] == '\0') {
                errorMessage = "Username and password cannot be empty!";
            } else {
                // Handle login logic here
                std::string msg = protocol::login_protocol(std::string(username), std::string(password));
                graphic_client.send_messages(msg);
                std::string recv_msg = graphic_client.read_messages();

                if (recv_msg == "ok") {
                    // ok now the user is login
                    errorMessage = nullptr; // Clear error message on success
                    showLoginWindow = false;
                    has_authentificate = true;
                } else {
                    errorMessage = recv_msg.c_str();
                }
            }
        }

        // Display error message if any
        if (errorMessage) {
            ImGui::TextColored(ImVec4(1, 0, 0, 1), "%s", errorMessage); // Red color for error
        }
        ImGui::End();
    }
}
