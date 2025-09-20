#include "SFML/Graphics.hpp"

auto initializeItemsFont(sf::Text &titleForFont, sf::RectangleShape &frameFront1,
                         sf::RectangleShape &frameFront2, sf::RectangleShape &frameFront3,
                         sf::RectangleShape &frameFront4, sf::Text &textFont1, sf::Text &textFont2,
                         sf::Text &textFont3, sf::Text &textFont4) -> void {

    titleForFont = sf::Text();

    frameFront1 = sf::RectangleShape();
    frameFront2 = sf::RectangleShape();
    frameFront3 = sf::RectangleShape();
    frameFront4 = sf::RectangleShape();

    textFont1 = sf::Text();
    textFont2 = sf::Text();
    textFont3 = sf::Text();
    textFont4 = sf::Text();
}

auto itemsFont(sf::Text &titleForFont, sf::RectangleShape &frameFront1,
               sf::RectangleShape &frameFront2, sf::RectangleShape &frameFront3,
               sf::RectangleShape &frameFront4, sf::Text &textFont1, sf::Text &textFont2,
               sf::Text &textFont3, sf::Text &textFont4, sf::Font &font1, sf::Font &font2,
               sf::Font &font3, sf::Font &font4) -> void {

    titleForFont.setString("Select font");
    titleForFont.setFont(font1);
    titleForFont.setFillColor(sf::Color::Red);
    titleForFont.setCharacterSize(70);
    titleForFont.setPosition({350, 100});


    textFont1.setString("abcd");
    textFont1.setFont(font1);
    textFont1.setFillColor(sf::Color::White);
    textFont1.setCharacterSize(40);
    textFont1.setPosition({760, 260});

    textFont2.setString("abcd");
    textFont2.setFont(font2);
    textFont2.setFillColor(sf::Color::White);
    textFont2.setCharacterSize(40);
    textFont2.setPosition({760, 360});

    textFont3.setString("abcd");
    textFont3.setFont(font3);
    textFont3.setFillColor(sf::Color::White);
    textFont3.setCharacterSize(40);
    textFont3.setPosition({760, 460});

    textFont4.setString("abcd");
    textFont4.setFont(font4);
    textFont4.setFillColor(sf::Color::White);
    textFont4.setCharacterSize(40);
    textFont4.setPosition({760, 560});

    frameFront1.setSize(sf::Vector2f(100, 65));
    frameFront1.setPosition({750, 255});
    frameFront1.setFillColor(sf::Color::Black);

    frameFront2.setSize(sf::Vector2f(100, 65));
    frameFront2.setPosition({750, 355});
    frameFront2.setFillColor(sf::Color::Black);

    frameFront3.setSize(sf::Vector2f(100, 65));
    frameFront3.setPosition({750, 450});
    frameFront3.setFillColor(sf::Color::Black);

    frameFront4.setSize(sf::Vector2f(100, 65));
    frameFront4.setPosition({755, 550});
    frameFront4.setFillColor(sf::Color::Black);

}

auto buttonIlluminationFont(sf::Vector2i const& mousePosition, sf::RectangleShape &frameFront1,
                            sf::RectangleShape &frameFront2, sf::RectangleShape &frameFront3,
                            sf::RectangleShape &frameFront4 ) -> void {



    if (frameFront1.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                     static_cast<float>(mousePosition.y)})) {
        frameFront1.setFillColor(sf::Color::Red);
    } else {
        frameFront1.setFillColor(sf::Color::Black);
    }

    if (frameFront2.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                     static_cast<float>(mousePosition.y)})) {
        frameFront2.setFillColor(sf::Color::Red);
    } else {
        frameFront2.setFillColor(sf::Color::Black);
    }

    if (frameFront3.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                     static_cast<float>(mousePosition.y)})) {
        frameFront3.setFillColor(sf::Color::Red);
    } else {
        frameFront3.setFillColor(sf::Color::Black);
    }

    if (frameFront4.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                static_cast<float>(mousePosition.y)})) {
        frameFront4.setFillColor(sf::Color::Red);
    } else {
        frameFront4.setFillColor(sf::Color::Black);
    }

}

auto drawFontItems(sf::RenderWindow& window, sf::Text &titleForFont, sf::RectangleShape &frameFront1,
                   sf::RectangleShape &frameFront2, sf::RectangleShape &frameFront3,
                   sf::RectangleShape &frameFront4, sf::Text &textFont1, sf::Text &textFont2,
                   sf::Text &textFont3, sf::Text &textFont4) -> void {

    window.draw(titleForFont);
    window.draw(frameFront1);
    window.draw(frameFront2);
    window.draw(frameFront3);
    window.draw(frameFront4);
    window.draw(textFont1);
    window.draw(textFont2);
    window.draw(textFont3);
    window.draw(textFont4);

}

