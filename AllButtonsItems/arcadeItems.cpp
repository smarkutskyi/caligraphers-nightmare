#include "SFML/Graphics.hpp"


auto initializeItemsArcade(sf::Text& basedText, sf::RectangleShape& buttonFrame1,
                        sf::RectangleShape &buttonFrame2, sf::RectangleShape& buttonFrame3,
                        sf::Text &buttonText1, sf::Text &buttonText2, sf::Text& buttonText3) -> void {
    basedText = sf::Text();
    buttonFrame1 = sf::RectangleShape();
    buttonFrame2 = sf::RectangleShape();
    buttonFrame3 = sf::RectangleShape();

    buttonText1 = sf::Text();
    buttonText2 = sf::Text();
    buttonText3 = sf::Text();
}

auto itemsArcade(sf::Text& titleText, sf::Font& font, sf::Text& basedText, sf::RectangleShape& buttonFrame1,
              sf::RectangleShape &buttonFrame2, sf::RectangleShape& buttonFrame3,
              sf::Text &buttonText1, sf::Text &buttonText2, sf::Text& buttonText3)-> void {

    titleText.setString("Calligrapher's Nightmare");
    titleText.setFont(font);
    titleText.setFillColor(sf::Color::Red);
    titleText.setCharacterSize(90);
    titleText.setPosition({350, 100});

    basedText.setString("Arcade Games");
    basedText.setFont(font);
    basedText.setFillColor(sf::Color::Red);
    basedText.setCharacterSize(50);
    basedText.setPosition({660, 260});

    buttonText1.setString("For Alien");
    buttonText1.setFont(font);
    buttonText1.setFillColor(sf::Color::White);
    buttonText1.setCharacterSize(40);
    buttonText1.setPosition({550, 380});

    buttonText2.setString("For Accountants");
    buttonText2.setFont(font);
    buttonText2.setFillColor(sf::Color::White);
    buttonText2.setCharacterSize(40);
    buttonText2.setPosition({900, 380});

    buttonText3.setString("Back");
    buttonText3.setFont(font);
    buttonText3.setFillColor(sf::Color::White);
    buttonText3.setCharacterSize(40);
    buttonText3.setPosition({770, 490});

    buttonFrame1.setSize(sf::Vector2f(190, 70));
    buttonFrame1.setPosition({535, 370});
    buttonFrame1.setFillColor(sf::Color::Black);

    buttonFrame2.setSize(sf::Vector2f(330, 70));
    buttonFrame2.setPosition({890, 370});
    buttonFrame2.setFillColor(sf::Color::Black);

    buttonFrame3.setSize(sf::Vector2f(150, 70));
    buttonFrame3.setPosition({735, 480});
    buttonFrame3.setFillColor(sf::Color::Black);

}

auto buttonIlluminationArcade(sf::Vector2i const& mousePosition, sf::RectangleShape& buttonFrame1,
                           sf::RectangleShape& buttonFrame2, sf::RectangleShape& buttonFrame3) -> void {

    if (buttonFrame1.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                 static_cast<float>(mousePosition.y)})) {
        buttonFrame1.setFillColor(sf::Color::Red);
    } else {
        buttonFrame1.setFillColor(sf::Color::Black);
    }

    if (buttonFrame2.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                 static_cast<float>(mousePosition.y)})) {
        buttonFrame2.setFillColor(sf::Color::Red);
    } else {
        buttonFrame2.setFillColor(sf::Color::Black);
    }

    if (buttonFrame3.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                 static_cast<float>(mousePosition.y)})) {
        buttonFrame3.setFillColor(sf::Color::Red);
    } else {
        buttonFrame3.setFillColor(sf::Color::Black);
    }

}

auto drawArcadeItems(sf::RenderWindow& window, sf::Text& titleText, sf::Text &basedText,
                     sf::RectangleShape &buttonFrame1,sf::RectangleShape &buttonFrame2,
                     sf::RectangleShape& buttonFrame3,sf::Text &buttonText1, sf::Text &buttonText2,
                     sf::Text& buttonText3) -> void {

    window.draw(titleText);
    window.draw(basedText);
    window.draw(buttonFrame1);
    window.draw(buttonFrame2);
    window.draw(buttonFrame3);

    window.draw(buttonText1);
    window.draw(buttonText2);
    window.draw(buttonText3);
}
