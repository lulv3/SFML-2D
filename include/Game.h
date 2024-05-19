#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Fireball.h"
#include "Window.h"
#include <vector>
#include <string>

#include <imgui.h>
#include <imgui-SFML.h>

class Game {
public:
    Game(int screenWidth, int screenHeight, const std::string& title);
    void run();

private:
    sf::Clock clock;
    Window window;
    Player player;
    std::vector<Fireball> fireballs;

    bool collisionsVisible;

    sf::Time timeSinceLastSpawn;
    sf::Time spawnInterval;
    sf::Clock fireballTimer;


    float fireballSpeed;
    int fireballDirection;
    int score;
    bool isGameOver;

    void handleEvents();
    void handleInput();
    void update();
    void render();
    void updatePlayer();
    void updateFireballs();
    void checkCollisions();
    void init();
    void spawnFireball();
    void deleteFireball(int index);
};

#endif // GAME_H
