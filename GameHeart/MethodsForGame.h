#include "SFML/Graphics.hpp"
#include "ClassForGame.h"

auto updatingTextPositions(std::vector<wordOnScreen>& wordsOnScreen, const float &timeLeft,
                           float const& wordSpeed) -> void;

auto deleteWords(std::vector<wordOnScreen>& wordsOnScreen, int& numberHeartsInteger, int &action) -> void;

auto createNewWord(sf::Font const &font, std::vector<wordOnScreen>& wordsOnScreen,
                   std::vector<std::string> &wordsFromFile, sf::RenderWindow& window, int const &howToCreat) -> void;

auto drawWords(std::vector<wordOnScreen> &wordsOnScreen, sf::RenderWindow & window) -> void;
