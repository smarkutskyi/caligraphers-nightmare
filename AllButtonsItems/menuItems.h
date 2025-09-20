#include "SFML/Graphics.hpp"


auto initializeItemsMenu(sf::Text& titleText, sf::RectangleShape& bMF1,
                         sf::RectangleShape &bMF2, sf::RectangleShape& bMF3, sf::Text& bMT1,
                         sf::Text& bMT2, sf::Text& bMT3) -> void;

auto ItemsMenu(sf::Font &font, sf::Text &titleText, sf::RectangleShape& buttonMenuFrame1,
               sf::RectangleShape &buttonMenuFrame2, sf::RectangleShape& buttonMenuFrame3, sf::Text& buttonMenuText1,
               sf::Text& buttonMenuText2, sf::Text& buttonMenuText3) -> void;

auto buttonIlluminationMenu(sf::Vector2i const& mousePosition, sf::RectangleShape& buttonMenuFrame1,
                            sf::RectangleShape& buttonMenuFrame2, sf::RectangleShape& buttonMenuFrame3 ) -> void;

auto drawMenuItems(sf::RenderWindow& window,sf::Text &titleText, sf::RectangleShape &buttonMenuFrame1,
                   sf::RectangleShape &buttonMenuFrame2, sf::RectangleShape &buttonMenuFrame3,
                   sf::Text &buttonMenuText1,
                   sf::Text &buttonMenuText2, sf::Text &buttonMenuText3) -> void;