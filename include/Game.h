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

    // Startet das Spiel
    void run();

private:
    // Fensterobjekt für das Spiel
    sf::Clock clock;
    Window window;

    // Spielerobjekt
    Player player;

    // Liste der Feuerbälle
    std::vector<Fireball> fireballs;

    // Timer für die Feuerbälle
    int fireballTimer;

    // Spielstand
    int score;

    // Anzahl der Leben des Spielers
    int lives;

    // Zeigt an, ob das Spiel vorbei ist
    bool isGameOver;

    // Behandelt Ereignisse
    void handleEvents();
    void handleInput();

    // Aktualisiert den Spielzustand
    void update();

    // Zeichnet die Spielobjekte
    void render();

    // Aktualisiert die Bewegung und Position des Spielers
    void updatePlayer();

    // Aktualisiert die Bewegung und Position der Feuerbälle
    void updateFireballs();

    // Überprüft Kollisionen zwischen Spieler und Feuerbällen
    void checkCollisions();
    void init();
};

#endif // GAME_H
