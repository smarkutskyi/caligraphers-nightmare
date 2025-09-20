#include "SFML/Graphics.hpp"
#include "ClassForGame.h"

wordOnScreen::wordOnScreen(float xP, float yP, bool allVisible) : xP(xP), yP(yP), allVisible(allVisible) {}

auto wordOnScreen::letterFormation(const std::string &word, const sf::Font &font) -> void {
    for (char c: word) {
        sf::Text letter;
        letter.setFont(font);
        letter.setString(c);
        letter.setCharacterSize(30);
        letter.setFillColor(sf::Color::White);
        letters.push_back(letter);
    }
}