#include "Window.h"

Window::Window(int width, int height, const std::string& title)
    : window(sf::VideoMode(width, height), title), view(sf::FloatRect(0.f, 0.f, static_cast<float>(width), static_cast<float>(height))) {
    window.setView(view);
}

void Window::beginDraw() {
    window.clear(sf::Color::Black);
}

void Window::endDraw() {
    window.display();
}

bool Window::isOpen() const {
    return window.isOpen();
}

void Window::close() {
    window.close();
}

void Window::draw(const sf::Drawable& drawable) {
    window.draw(drawable);
}

bool Window::pollEvent(sf::Event& event) {
    return window.pollEvent(event);
}

void Window::adjustView() {
    sf::Vector2u windowSize = window.getSize();
    view.setSize(windowSize.x, windowSize.y);
    view.setCenter(windowSize.x / 2.f, windowSize.y / 2.f);
    window.setView(view);
}

sf::RenderWindow& Window::getWindow() {
    return window;
}
void Window::zoomView(float factor) {
    view.zoom(factor);
    window.setView(view);
}
