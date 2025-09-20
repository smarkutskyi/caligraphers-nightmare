#include "SFML/Graphics.hpp"
auto speedChange(sf::Event const& event, float & wordSpeed) -> void;

auto playerWordProcessing(sf::Event const &event, std::string &textFromPlayer,
                          std::vector<wordOnScreen> &wordsOnScreen, sf::Text& yourTextGame) -> void;

