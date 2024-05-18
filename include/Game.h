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
    // Fensterobjekt f�r das Spiel
    sf::Clock clock;
    Window window;

    // Spielerobjekt
    Player player;

    // Liste der Feuerb�lle
    std::vector<Fireball> fireballs;

    // Timer f�r die Feuerb�lle
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

    // Aktualisiert die Bewegung und Position der Feuerb�lle
    void updateFireballs();

    // �berpr�ft Kollisionen zwischen Spieler und Feuerb�llen
    void checkCollisions();
    void init();
};

#endif // GAME_H
