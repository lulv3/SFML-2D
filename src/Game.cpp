#include "Game.h"

Game::Game(int screenWidth, int screenHeight, const std::string& title)
    : window(screenWidth, screenHeight, title), fireballTimer(), score(0), isGameOver(false),
    timeSinceLastSpawn(sf::Time::Zero), spawnInterval(sf::seconds(2.f)), fireballSpeed(600.f), fireballDirection(1){
    //Set window view to full screen
    window.adjustView();
}

void Game::init()
{
    // TODO: Fix ImGui initialization and add Docking to the ConfigFlags
	
    ImGui::SFML::Init(window.getWindow(), true);
    ImGuiIO io = ImGui::GetIO(); (void)io;
    
}

void Game::run() {
	init();                                     // Initialize the game and for example ImGui
    while (window.isOpen()) {
		handleEvents();                         // Handle all events
		handleInput();                          // Handle all input events
		update();                               // Update the game state
		render();                               // Render the game
    }
	ImGui::SFML::Shutdown();                    // Shutdown the game and engine
}

void Game::handleEvents() {
	sf::Event event;                                            // Create an event object
    while (window.pollEvent(event)) {
        ImGui::SFML::ProcessEvent(event);                       // Handle the ImGui events
        if (event.type == sf::Event::Closed) 
			window.close();                                     // Close/Destroy the window if the window was closed
    }
	ImGui::SFML::Update(window.getWindow(), clock.restart());   // Update ImGui 
}

void Game::handleInput()
{
    player.handleInput();                                       // Handle the Player Input Events
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

        // TODO: Fix the del method
        // Remove off-screen fireballs
        fireballs.erase(std::remove_if(fireballs.begin(), fireballs.end(),
            [this](const Fireball& fireball) {
                return fireball.getBounds().left > window.getSize().x || fireball.getBounds().left + fireball.getBounds().width < 0;
            }), fireballs.end());
        
#pragma endregion

        checkCollisions();

        // Check if the game is over
        if(player.isPlayerDead())
			isGameOver = true;
    }
    window.update();
}

void Game::render() {
    window.beginDraw();

    // Draw players
    //window.draw(player.getSprite());
    player.draw(window.getWindow());

    // Draw fireballs
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
            // Delete the fireball that collided with the player
            deleteFireball(i);
        }
    }
}

void Game::deleteFireball(int index) {
    if (index >= 0 && index < fireballs.size()) {
        // Delete the Fireball from the list
        fireballs.erase(fireballs.begin() + index);
    }
}

void Game::spawnFireball() {
    float minSpeed = 300.0f;    // Example: Minimum speed of 100 pixels per second
    float maxSpeed = 1200.0f;   // Example: Maximum speed of 300 pixels per second
    float randomSpeed = minSpeed + static_cast<float>(rand()) / (RAND_MAX / (maxSpeed - minSpeed + 1));

    float startY = static_cast<float>(rand() % window.getSize().y);
    bool moveRight = rand() % 2 == 0;
    float startX = moveRight ? 0.0f : static_cast<float>(window.getSize().x);
    fireballs.emplace_back(startX, startY, moveRight, randomSpeed);
}