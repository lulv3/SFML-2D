#include "Window.h"

Window::Window(int width, int height, const std::string& title)
    : window(sf::VideoMode(width, height), title), view(sf::FloatRect(0.f, 0.f, static_cast<float>(width), static_cast<float>(height))), 
    imguiEnabled(true), backgroundColor(sf::Color::Black), viewZoom(1){
    window.setView(view);
}

#pragma region ImGui
void Window::renderImGui()
{
    ImGui::Begin("Window Controller");

    // Zoom Factor Slider with reduced sensitivity
    float minZoomFactor = 0.5f; // Min zoom factor
    float maxZoomFactor = 2.0f; // Max zoom factor
    float stepZoomFactor = 0.1f; // Step size for zoom factor

    // ImGui::SliderFloat("Zoom Factor", &viewZoom, minZoomFactor, maxZoomFactor, "%.1f", ImGuiSliderFlags_Logarithmic);

    ImGui::SliderFloat("Zoom", &viewZoom, 0.5f, 2.0f);

    ImGui::NewLine();
    // Background Color
    float color[4] = {
            backgroundColor.r / 255.0f,
            backgroundColor.g / 255.0f,
            backgroundColor.b / 255.0f,
            backgroundColor.a / 255.0f
    };
    if (ImGui::ColorEdit4("Background Color", color)) {
        backgroundColor.r = static_cast<sf::Uint8>(color[0] * 255);
        backgroundColor.g = static_cast<sf::Uint8>(color[1] * 255);
        backgroundColor.b = static_cast<sf::Uint8>(color[2] * 255);
        backgroundColor.a = static_cast<sf::Uint8>(color[3] * 255);
    }

    ImGui::End();
}
#pragma endregion

void Window::beginDraw() {
    window.clear(backgroundColor);
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
    viewZoom = factor;
    view.zoom(viewZoom);
    window.setView(view);
}

void Window::update()
{
    // zoomView(viewZoom);
}