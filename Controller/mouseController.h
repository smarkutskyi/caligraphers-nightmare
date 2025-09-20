#include "SFML/Graphics.hpp"

auto mouseMenuButton(sf::Event const& event, sf::Vector2i & mousePosition,
                     sf::RectangleShape& buttonMenuFrame1,
                     sf::RectangleShape& buttonMenuFrame2, sf::RectangleShape& buttonMenuFrame3, int& action) -> void;

auto mouseGFPoButton(sf::Event const& event, sf::Vector2i & mousePosition, sf::RectangleShape &buttonFrame1,
                     sf::RectangleShape &buttonFrame2, sf::RectangleShape& buttonFrame3,
                     int& action, int& actionFont) -> void;

auto mouseGameButton(sf::Event const& event, sf::Vector2i & mousePosition, sf::RectangleShape &exitFrame,
                     int& action) -> void;

auto mouseFontButton(sf::Event const& event, sf::Vector2i & mousePosition, sf::RectangleShape &frameFront1,
                     sf::RectangleShape &frameFront2, sf::RectangleShape &frameFront3,
                     sf::RectangleShape &frameFront4,int& action, sf::Font& font, int& actionFont) -> void;

auto mouseArcadeButton(sf::Event const& event, sf::Vector2i & mousePosition, sf::RectangleShape &buttonFrame1,
                       sf::RectangleShape &buttonFrame2, sf::RectangleShape& buttonFrame3,
                       int& action) -> void;

auto mouseGameArcadeButton(sf::Event const& event, sf::Vector2i & mousePosition, sf::RectangleShape &exitFrame,
                           int& action) -> void;


