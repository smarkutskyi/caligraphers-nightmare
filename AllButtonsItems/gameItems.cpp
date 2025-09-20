#include "SFML/Graphics.hpp"

auto initializeItemsGame(sf::Text& textExit, sf::RectangleShape & frameExit,
                         sf::Text& textGame, sf::Text& yourText, sf::Text &numberOfHearts) -> void {
    textExit = sf::Text();
    frameExit = sf::RectangleShape();
    textGame = sf::Text();
    yourText = sf::Text();
    numberOfHearts = sf::Text();

}
auto itemsGame(sf::Font& font, sf::Font & font2, sf::Text& textExit, sf::RectangleShape& frameExit,
               sf::Text& textGame, sf::Text& yourText, sf::Sprite & heartImage, sf::Text &numberOfHearts) -> void {
    textExit.setString("EXIT");
    textExit.setFillColor(sf::Color::White);
    textExit.setFont(font);
    textExit.setCharacterSize(50);
    textExit.setPosition(15, 0);

    frameExit.setSize(sf::Vector2f(110,50));
    frameExit.setPosition(10,5);
    frameExit.setFillColor(sf::Color::Black);

    textGame.setString("Your text: ");
    textGame.setFont(font);
    textGame.setFillColor(sf::Color::Red);
    textGame.setCharacterSize(50);
    textGame.setPosition(500, 745);


    yourText.setFont(font);
    yourText.setFillColor(sf::Color::White);
    yourText.setCharacterSize(50);
    yourText.setPosition(750, 745);

    heartImage.setPosition(1425, 5);

    numberOfHearts.setString("15");
    numberOfHearts.setCharacterSize(40);
    numberOfHearts.setFillColor(sf::Color::White);
    numberOfHearts.setFont(font2);
    numberOfHearts.setPosition(1500, 0);


}

auto buttonIlluminationGame(sf::Vector2i const& mousePosition, sf::RectangleShape& frameExit) -> void {
    if (frameExit.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                              static_cast<float>(mousePosition.y)})) {
        frameExit.setFillColor(sf::Color::Red);
    } else {
        frameExit.setFillColor(sf::Color::Black);
    }

}

auto drawGameItems(sf::RenderWindow& window, sf::RectangleShape& frameExit, sf::Text &textExit,
                   sf::Text& textGame, sf::Text& yourText, sf::Sprite & heartImage, sf::Text &numberOfHearts) -> void {
    window.draw(frameExit);
    window.draw(textExit);
    window.draw(textGame);
    window.draw(yourText);
    window.draw(heartImage);
    window.draw(numberOfHearts);
}