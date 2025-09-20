#include "SFML/Graphics.hpp"

auto initializeItemsGame(sf::Text& textExit, sf::RectangleShape & frameExit,
                         sf::Text &textGame, sf::Text &yourText, sf::Text &numberOfHearts) -> void;

auto itemsGame(sf::Font& font, sf::Font & font2, sf::Text& textExit, sf::RectangleShape& frameExit,
               sf::Text& textGame, sf::Text& yourText, sf::Sprite & heartImage, sf::Text &numberOfHearts) -> void;

auto buttonIlluminationGame(sf::Vector2i const& mousePosition, sf::RectangleShape& frameExit) -> void;

auto drawGameItems(sf::RenderWindow& window, sf::RectangleShape& frameExit, sf::Text &textExit,
                   sf::Text& textGame, sf::Text& yourText, sf::Sprite & heartImage, sf::Text &numberOfHearts) -> void;