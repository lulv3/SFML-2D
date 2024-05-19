#include "Game.h"

Game::Game(int screenWidth, int screenHeight, const std::string& title)
    : window(screenWidth, screenHeight, title), fireballTimer(), score(0), isGameOver(false),
    timeSinceLastSpawn(sf::Time::Zero), spawnInterval(sf::seconds(2.f)), fireballSpeed(600.f), fireballDirection(1){
    // Setze die Fensteransicht auf den gesamten Bildschirm
}

void Game::init()
{
    ImGui::SFML::Init();
    // Setup ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; // Enable Docking
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
        float deltaTime = clock.restart().asSeconds();

        // Update player and fireballs

#pragma region Fireballs
        
        for (auto& fireball : fireballs) {
            fireball.update(deltaTime);
        }

        // Spawn new fireballs
        if (fireballTimer.getElapsedTime().asSeconds() > 2.0f) { // alle 2 Sekunden
            spawnFireball();
            fireballTimer.restart();
        }

        // Remove off-screen fireballs
        fireballs.erase(std::remove_if(fireballs.begin(), fireballs.end(),
            [this](const Fireball& fireball) {
                return fireball.getBounds().left > window.getSize().x || fireball.getBounds().left + fireball.getBounds().width < 0;
            }), fireballs.end());
        
#pragma endregion

        checkCollisions();

        // Überprüfen, ob das Spiel vorbei ist
        if(player.isPlayerDead())
			isGameOver = true;
    }
    window.update();
}

void Game::render() {
    window.beginDraw();

    // Spieler zeichnen
    //window.draw(player.getSprite());
    player.draw(window.getWindow());

    // Fireballs zeichnen
    for (auto& fireball : fireballs) { // maybe as const
        fireball.render(window.getWindow());
    }

    ImGui::Begin("Global Controller");

    if (ImGui::Button("Restart Game"))
    {
        isGameOver = false;
    }

    ImGui::NewLine();
    ImGui::Checkbox("Show Collisions", &collisionsVisible);
    ImGui::End();

    player.renderImGui();
    window.renderImGui();
    ImGui::SFML::Render(window.getWindow());

    window.endDraw();
}
void Game::checkCollisions() {

    if (collisionsVisible)
    {
        player.toggleCollisionBox();
        for (auto& fireball : fireballs) { // maybe as const
            fireball.setCollisionBoxVisibility(collisionsVisible);
        }
    }

    for (size_t i = 0; i < fireballs.size(); ++i) {
        const auto& fireball = fireballs[i];
        if (fireball.checkCollision(player.getBounds())) {
            player.tageDamage(1);
            // Lösche den Fireball, der mit dem Spieler kollidiert ist
            deleteFireball(i);
        }
    }
}

void Game::deleteFireball(int index) {
    if (index >= 0 && index < fireballs.size()) {
        // Lösche den Fireball aus der Liste
        fireballs.erase(fireballs.begin() + index);
    }
}

void Game::spawnFireball() {
    float minSpeed = 300.0f; // Beispiel: Mindestgeschwindigkeit von 100 Pixeln pro Sekunde
    float maxSpeed = 1200.0f; // Beispiel: Höchstgeschwindigkeit von 300 Pixeln pro Sekunde
    float randomSpeed = minSpeed + static_cast<float>(rand()) / (RAND_MAX / (maxSpeed - minSpeed + 1));

    float startY = static_cast<float>(rand() % window.getSize().y);
    bool moveRight = rand() % 2 == 0;
    float startX = moveRight ? 0.0f : static_cast<float>(window.getSize().x);
    fireballs.emplace_back(startX, startY, moveRight, randomSpeed);
}