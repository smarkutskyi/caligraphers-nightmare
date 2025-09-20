#pragma once
#include "SFML/Graphics.hpp"

struct wordOnScreen {
//    sf::Text text;
    std::vector<sf::Text> letters;
    float xP;
    float yP;
    bool allVisible;

    wordOnScreen(float xP, float yP, bool allVisible);



    auto letterFormation(const std::string &word, const sf::Font &font) -> void;
};