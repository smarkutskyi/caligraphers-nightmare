#include "SFML/Graphics.hpp"
#include <fmt/ranges.h>

auto mouseMenuButton(sf::Event const& event, sf::Vector2i & mousePosition,
                     sf::RectangleShape& buttonMenuFrame1,sf::RectangleShape& buttonMenuFrame2,
                     sf::RectangleShape& buttonMenuFrame3, int& action) -> void {
    if (event.mouseButton.button == sf::Mouse::Left) {

        if (buttonMenuFrame1.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                         static_cast<float>(mousePosition.y)})) {

            action = 1;
        } else if (buttonMenuFrame2.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                                static_cast<float>(mousePosition.y)})) {

            action = 5;
        } else if (buttonMenuFrame3.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                                static_cast<float>(mousePosition.y)})) {

            action = -1;
        }
    }


}

auto mouseGFPoButton(sf::Event const& event, sf::Vector2i & mousePosition, sf::RectangleShape &buttonFrame1,
                     sf::RectangleShape &buttonFrame2, sf::RectangleShape& buttonFrame3,
                     int& action, int& actionFont) -> void {
    if (event.mouseButton.button == sf::Mouse::Left) {

        if (buttonFrame1.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                         static_cast<float>(mousePosition.y)})) {

            action = 20;
            actionFont = 3;
        } else if (buttonFrame2.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                                static_cast<float>(mousePosition.y)})) {

            action = 20;
            actionFont = 4;
        }else if (buttonFrame3.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                                static_cast<float>(mousePosition.y)})) {

            action = 0;
        }
    }
}

auto mouseGameButton(sf::Event const& event, sf::Vector2i & mousePosition, sf::RectangleShape &exitFrame,
                     int& action) -> void {
    if (event.mouseButton.button == sf::Mouse::Left) {

        if (exitFrame.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                     static_cast<float>(mousePosition.y)})) {

            action = 1;
        }
    }

}

auto mouseFontButton(sf::Event const& event, sf::Vector2i & mousePosition, sf::RectangleShape &frameFront1,
                     sf::RectangleShape &frameFront2, sf::RectangleShape &frameFront3,
                     sf::RectangleShape &frameFront4,int& action, sf::Font& font, int &actionFont) -> void {
    if (event.mouseButton.button == sf::Mouse::Left) {

        if (frameFront1.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                         static_cast<float>(mousePosition.y)})) {
            font = sf::Font();
            if (!font.loadFromFile("../Salvador.ttf")) {
                fmt::println("NO FILE");

            }

            action = actionFont;
        } else if (frameFront2.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                                static_cast<float>(mousePosition.y)})) {

            font = sf::Font();
            if (!font.loadFromFile("../aAntiCorona.ttf")) {
                fmt::println("NO FILE");

            }

            action = actionFont;

        } else if (frameFront3.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                                static_cast<float>(mousePosition.y)})) {

            font = sf::Font();
            if (!font.loadFromFile("../Arto.ttf")) {
                fmt::println("NO FILE");

            }
            action = actionFont;
        } else if (frameFront4.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                           static_cast<float>(mousePosition.y)})){

            font = sf::Font();
            if (!font.loadFromFile("../Bodoni.ttf")){
                fmt::println("NO FILE");
            }
            action = actionFont;
        }
    }

}

auto mouseArcadeButton(sf::Event const& event, sf::Vector2i & mousePosition, sf::RectangleShape &buttonFrame1,
                     sf::RectangleShape &buttonFrame2, sf::RectangleShape& buttonFrame3,
                     int& action) -> void {
    if (event.mouseButton.button == sf::Mouse::Left) {

        if (buttonFrame1.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                     static_cast<float>(mousePosition.y)})) {


            action = 6;
        } else if (buttonFrame2.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                            static_cast<float>(mousePosition.y)})) {


            action = 7;
        }else if (buttonFrame3.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                           static_cast<float>(mousePosition.y)})) {

            action = 0;
        }
    }
}

auto mouseGameArcadeButton(sf::Event const& event, sf::Vector2i & mousePosition, sf::RectangleShape &exitFrame,
                     int& action) -> void {
    if (event.mouseButton.button == sf::Mouse::Left) {

        if (exitFrame.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                  static_cast<float>(mousePosition.y)})) {

            action = 5;
        }
    }

}
