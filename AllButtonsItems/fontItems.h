#include "SFML/Graphics.hpp"

auto initializeItemsFont(sf::Text &titleForFont, sf::RectangleShape &frameFront1,
                         sf::RectangleShape &frameFront2, sf::RectangleShape &frameFront3,
                         sf::RectangleShape &frameFront4, sf::Text &textFont1, sf::Text &textFont2,
                         sf::Text &textFont3, sf::Text &textFont4) -> void;

auto itemsFont(sf::Text &titleForFont, sf::RectangleShape &frameFront1,
               sf::RectangleShape &frameFront2, sf::RectangleShape &frameFront3,
               sf::RectangleShape &frameFront4, sf::Text &textFont1, sf::Text &textFont2,
               sf::Text &textFont3, sf::Text &textFont4, sf::Font &font1, sf::Font &font2,
               sf::Font &font3, sf::Font &font4) -> void;

auto buttonIlluminationFont(sf::Vector2i const& mousePosition, sf::RectangleShape &frameFront1,
                            sf::RectangleShape &frameFront2, sf::RectangleShape &frameFront3,
                            sf::RectangleShape &frameFront4 ) -> void;

auto drawFontItems(sf::RenderWindow& window, sf::Text &titleForFont, sf::RectangleShape &frameFront1,
                   sf::RectangleShape &frameFront2, sf::RectangleShape &frameFront3,
                   sf::RectangleShape &frameFront4, sf::Text &textFont1, sf::Text &textFont2,
                   sf::Text &textFont3, sf::Text &textFont4) -> void;


