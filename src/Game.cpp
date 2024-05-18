#include "Game.h"

Game::Game(int screenWidth, int screenHeight, const std::string& title)
    : window(screenWidth, screenHeight, title), fireballTimer(0), score(0), lives(3), isGameOver(false) {
    // Setze die Fensteransicht auf den gesamten Bildschirm
}

void Game::init()
{
    ImGui::SFML::Init(window.getWindow());
}
void Game::run() {
    init();
    while (window.isOpen()) {
        handleEvents();
        handleInput();
        update();
        render();
    }
    ImGui::SFML::Shutdown();
    
}

void Game::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        ImGui::SFML::ProcessEvent(event);
        if (event.type == sf::Event::Closed)
            window.close();
    }
    ImGui::SFML::Update(window.getWindow(), clock.restart());
}
void Game::handleInput()
{
    player.handleInput();
}

void Game::update() {
    if (!isGameOver) {

        // Kollisionen überprüfen
        checkCollisions();

        // Score und Timer aktualisieren
        score += 1; // Beispiel für Score-Update
        fireballTimer += 1; // Beispiel für Timer-Update

        // Überprüfen, ob das Spiel vorbei ist
        if (lives <= 0) {
            isGameOver = true;
            // Hier könntest du weitere Aktionen ausführen, z. B. den Highscore speichern oder zum Hauptmenü zurückkehren
        }
    }
}

void Game::render() {
    window.beginDraw();

    // Spieler zeichnen
    window.draw(player.getSprite());

    player.renderImGui();
    window.renderImGui();
    ImGui::SFML::Render(window.getWindow());

    window.endDraw();
}

void Game::checkCollisions() 
{

}
