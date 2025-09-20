#include "SFML/Graphics.hpp"


auto initializeItemsArcade(sf::Text& basedText, sf::RectangleShape& buttonFrame1,
                           sf::RectangleShape &buttonFrame2, sf::RectangleShape& buttonFrame3,
                           sf::Text &buttonText1, sf::Text &buttonText2, sf::Text& buttonText3) -> void;

auto itemsArcade(sf::Text& titleText, sf::Font& font, sf::Text& basedText, sf::RectangleShape& buttonFrame1,
                 sf::RectangleShape &buttonFrame2, sf::RectangleShape& buttonFrame3, sf::Text &buttonText1,
                 sf::Text &buttonText2, sf::Text& buttonText3)-> void;

auto buttonIlluminationArcade(sf::Vector2i const& mousePosition, sf::RectangleShape& buttonFrame1,
                              sf::RectangleShape& buttonFrame2, sf::RectangleShape& buttonFrame3) -> void;

auto drawArcadeItems(sf::RenderWindow& window, sf::Text& titleText, sf::Text &basedText,
                     sf::RectangleShape &buttonFrame1, sf::RectangleShape &buttonFrame2,
                     sf::RectangleShape& buttonFrame3,
                     sf::Text &buttonText1, sf::Text &buttonText2, sf::Text& buttonText3) -> void;