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
        // Spielerbewegung aktualisieren
        updatePlayer();

        // Fireballs aktualisieren
        updateFireballs();

        // Kollisionen �berpr�fen
        checkCollisions();

        // Score und Timer aktualisieren
        score += 1; // Beispiel f�r Score-Update
        fireballTimer += 1; // Beispiel f�r Timer-Update

        // �berpr�fen, ob das Spiel vorbei ist
        if (lives <= 0) {
            isGameOver = true;
            // Hier k�nntest du weitere Aktionen ausf�hren, z. B. den Highscore speichern oder zum Hauptmen� zur�ckkehren
        }
    }
}

void Game::render() {
    window.beginDraw();

    // Spieler zeichnen
    window.draw(player.getSprite());

    // Fireballs zeichnen
    for (auto& fireball : fireballs) {
        window.draw(fireball.getSprite());
    }

    player.renderImGui();
    ImGui::SFML::Render(window.getWindow());

    window.endDraw();
}

void Game::updatePlayer() {
    // Beispiel f�r Spielerbewegung
    // Du k�nntest hier die Steuerung implementieren, z. B. Tastatureingaben abfragen und den Spieler entsprechend bewegen
}

void Game::updateFireballs() {
    // Feuerball-Timer erh�hen
    fireballTimer++;

    // Neue Feuerb�lle spawnen basierend auf Timer und Spielzeit
    if (fireballTimer > 60) { // Beispiel: Alle 60 Frames einen neuen Feuerball spawnen
        float spawnRate = std::max(60 - score, 30); // Spawnrate nimmt mit steigendem Score ab (mindestens alle 30 Frames)
        if (rand() % static_cast<int>(spawnRate) == 0) { // Zuf�llige Chance f�r jeden Frame, einen Feuerball zu spawnen
            float speed = 1.0f + score * 0.01f; // Geschwindigkeit der Feuerb�lle erh�ht sich mit dem Score
            float direction = rand() % 2 == 0 ? -1.0f : 1.0f; // Zuf�llige Richtung (links oder rechts)
            float startX = direction < 0 ? -50.0f : window.getSize().x + 50.0f; // Start-X-Position entweder ganz links oder ganz rechts
            float startY = static_cast<float>(rand() % window.getSize().y); // Zuf�llige Y-Position
            sf::Vector2f fireballStartPosition(startX, startY); // Startposition des Feuerballs
            sf::Vector2f fireballDirection(direction, 0.0f); // Richtungsvektor f�r den Feuerball
            Fireball newFireball("Assets/Star_Red.png", fireballStartPosition, fireballDirection, 16, 16); // Neue Fireball-Instanz mit den erforderlichen Parametern erstellen
            fireballs.push_back(newFireball); // Feuerball zur Liste hinzuf�gen
        }
        fireballTimer = 0; // Timer zur�cksetzen
    }

    // Feuerb�lle aktualisieren
    for (auto& fireball : fireballs) {
        fireball.update(); // Bewegung und Aktualisierung jedes Feuerballs
    }
}





void Game::checkCollisions() {
    // Beispiel f�r Kollisionserkennung zwischen Spieler und Feuerb�llen
    for (auto& fireball : fireballs) {
        if (player.getBounds().intersects(fireball.getBounds())) {
            // Hier k�nntest du die Aktionen ausf�hren, die bei einer Kollision stattfinden sollen
            // Zum Beispiel das Leben des Spielers verringern oder den Fireball zerst�ren
        }
    }
}
