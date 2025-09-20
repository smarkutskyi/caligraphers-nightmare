#include "SFML/Graphics.hpp"
#include "../GameHeart/ClassForGame.h"

auto speedChange(sf::Event const& event, float & wordSpeed) -> void {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.control && event.key.code == sf::Keyboard::A) {
            wordSpeed -= 10;
            if (wordSpeed < 50) wordSpeed = 50;
        }
        if (event.key.control && event.key.code == sf::Keyboard::D) {
            wordSpeed += 10;
            if (wordSpeed > 400) wordSpeed = 400;
        }
    }
}

auto playerWordProcessing(sf::Event const &event, std::string &textFromPlayer,
                          std::vector<wordOnScreen>& wordsOnScreen, sf::Text& yourTextGame) -> void {
    if (event.type == sf::Event::TextEntered) {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)
            || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)){
            return;
        }

        if (event.text.unicode == '\b') { // jeżeli backspace
            if (!textFromPlayer.empty()) {

                textFromPlayer.pop_back();
            }
        } else if (event.text.unicode == '\r' || event.text.unicode == '\n') { // jeżeli enter
            for (auto i = wordsOnScreen.begin(); i != wordsOnScreen.end();) {
                std::string entireText;
                for (const auto& letter : (*i).letters) {
                    entireText += letter.getString();
                }
                if (entireText == textFromPlayer) {
                    i = wordsOnScreen.erase(i);
                } else {
                    i++;
                }
            }
            textFromPlayer.clear();
        } else if (event.text.unicode < 128) {
            textFromPlayer += (char)event.text.unicode;
        }

        yourTextGame.setString(textFromPlayer);


        for (auto& word : wordsOnScreen) { // kolory

            auto stringCorrect = true; // jeżeli przeszłe litery tego słowa czerwone

            for (auto i = 0; i < word.letters.size(); i++) {


                if (i < textFromPlayer.length() && stringCorrect &&
                    word.letters[i].getString()[0] == textFromPlayer[i]) {

                    word.letters[i].setFillColor(sf::Color::Red);

                } else {

                    word.letters[i].setFillColor(sf::Color::White);
                    stringCorrect = false;
                }
            }
        }
    }
}



