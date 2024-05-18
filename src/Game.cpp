#include "Game.h"

Game::Game(int screenWidth, int screenHeight, const std::string& title)
    : window(screenWidth, screenHeight, title), fireballTimer(), score(0), isGameOver(false),
    timeSinceLastSpawn(sf::Time::Zero), spawnInterval(sf::seconds(2.f)), fireballSpeed(200.f), fireballDirection(1){
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
    if(!isGameOver)
        player.handleInput();
}

void Game::update() {
    if (!isGameOver) {
        float deltaTime = clock.restart().asSeconds();

        // Update player and fireballs
        // player.update(deltaTime);

#pragma region Fireballs
        
        for (auto& fireball : fireballs) {
            fireball.update(deltaTime);
        }

        /*
        // Remove off-screen fireballs
        fireballs.erase(std::remove_if(fireballs.begin(), fireballs.end(),
            [this](const Fireball& fireball) {
                return fireball.getBounds().left > window.getSize().x || fireball.getBounds().left + fireball.getBounds().width < 0;
            }), fireballs.end());

        */
        // Spawn new fireballs
        if (fireballTimer.getElapsedTime().asSeconds() > 5.0f) { // alle 2 Sekunden
            spawnFireball();
            fireballTimer.restart();
        }
#pragma endregion

        checkCollisions();

        // Überprüfen, ob das Spiel vorbei ist
        if(player.isPlayerDead())
			isGameOver = true;  
    }
}

void Game::render() {
    window.beginDraw();

    // Spieler zeichnen
    window.draw(player.getSprite());

    // Fireballs zeichnen
    for (auto& fireball : fireballs) { // maybe as const
        fireball.render(window.getWindow());
    }

    player.renderImGui();
    window.renderImGui();
    ImGui::SFML::Render(window.getWindow());

    window.endDraw();
}
void Game::checkCollisions() {
    for (const auto& fireball : fireballs) {
        if (fireball.checkCollision(player.getBounds())) {
            player.tageDamage(1);
            // fireball
            // TODO: delete Fireball who collide with the player
        }
    }
}

void Game::spawnFireball() {
    float startY = static_cast<float>(rand() % window.getSize().y);
    bool moveRight = rand() % 2 == 0;
    float startX = moveRight ? 0.0f : static_cast<float>(window.getSize().x);
    fireballs.emplace_back(startX, startY, moveRight, 100.0f);
}