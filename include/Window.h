#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include <string>
#include <imgui.h>
#include <imgui-SFML.h>

class Window {
public:
    Window(int width, int height, const std::string& title);
    void beginDraw();
    void endDraw();
    bool isOpen() const;
    void close();
    void draw(const sf::Drawable& drawable);
    bool pollEvent(sf::Event& event);
    void adjustView();
    sf::RenderWindow& getWindow();

    void zoomView(float factor);
    sf::Vector2u Window::getSize() const {
        return window.getSize();
    }

    void renderImGui();


private:
    sf::RenderWindow window;
    sf::View view;
    sf::Color backgroundColor;
	bool imguiEnabled;
};

#endif
