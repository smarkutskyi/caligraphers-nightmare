#include "SFML/Graphics.hpp"


auto initializeItemsMenu(sf::Text &titleText, sf::RectangleShape &bMF1,
                         sf::RectangleShape &bMF2, sf::RectangleShape &bMF3,
                         sf::Text &bMT1, sf::Text &bMT2, sf::Text &bMT3) -> void {
    titleText = sf::Text();
    bMF1 = sf::RectangleShape();
    bMF2 = sf::RectangleShape();
    bMF3 = sf::RectangleShape();
    bMT1 = sf::Text();
    bMT2 = sf::Text();
    bMT3 = sf::Text();
}

auto ItemsMenu(sf::Font &font, sf::Text &titleText, sf::RectangleShape &buttonMenuFrame1,
               sf::RectangleShape &buttonMenuFrame2, sf::RectangleShape &buttonMenuFrame3,
               sf::Text &buttonMenuText1,
               sf::Text &buttonMenuText2, sf::Text &buttonMenuText3) -> void {

    titleText.setString("Calligrapher's Nightmare");
    titleText.setFont(font);
    titleText.setFillColor(sf::Color::Red);
    titleText.setCharacterSize(90);
    titleText.setPosition({350, 100});


    buttonMenuText1.setString("Game for Points");
    buttonMenuText1.setFont(font);
    buttonMenuText1.setFillColor(sf::Color::White);
    buttonMenuText1.setCharacterSize(50);
    buttonMenuText1.setPosition({625, 260});

    buttonMenuText2.setString("Arcade Games");
    buttonMenuText2.setFont(font);
    buttonMenuText2.setFillColor(sf::Color::White);
    buttonMenuText2.setCharacterSize(50);
    buttonMenuText2.setPosition({645, 360});

    buttonMenuText3.setString("Exit");
    buttonMenuText3.setFont(font);
    buttonMenuText3.setFillColor(sf::Color::White);
    buttonMenuText3.setCharacterSize(50);
    buttonMenuText3.setPosition({760, 460});


    buttonMenuFrame1.setSize(sf::Vector2f(380, 75));
    buttonMenuFrame1.setPosition({615, 255});
    buttonMenuFrame1.setFillColor(sf::Color::Black);

    buttonMenuFrame2.setSize(sf::Vector2f(330, 75));
    buttonMenuFrame2.setPosition({640, 355});
    buttonMenuFrame2.setFillColor(sf::Color::Black);

    buttonMenuFrame3.setSize(sf::Vector2f(135, 75));
    buttonMenuFrame3.setPosition({735, 455});
    buttonMenuFrame3.setFillColor(sf::Color::Black);


}

auto buttonIlluminationMenu(sf::Vector2i const& mousePosition, sf::RectangleShape& buttonMenuFrame1,
                        sf::RectangleShape& buttonMenuFrame2, sf::RectangleShape& buttonMenuFrame3 ) -> void{
    if (buttonMenuFrame1.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                            static_cast<float>(mousePosition.y)})) {
        buttonMenuFrame1.setFillColor(sf::Color::Red);
    } else {
        buttonMenuFrame1.setFillColor(sf::Color::Black);
    }

    if (buttonMenuFrame2.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                                     static_cast<float>(mousePosition.y)})) {
        buttonMenuFrame2.setFillColor(sf::Color::Red);
    } else {
        buttonMenuFrame2.setFillColor(sf::Color::Black);
    }

    if (buttonMenuFrame3.getGlobalBounds().contains({static_cast<float>(mousePosition.x),
                                            static_cast<float>(mousePosition.y)})) {
        buttonMenuFrame3.setFillColor(sf::Color::Red);
    } else {
        buttonMenuFrame3.setFillColor(sf::Color::Black);
    }

}

auto drawMenuItems(sf::RenderWindow& window,sf::Text &titleText, sf::RectangleShape &buttonMenuFrame1,
                   sf::RectangleShape &buttonMenuFrame2, sf::RectangleShape &buttonMenuFrame3,
                   sf::Text &buttonMenuText1, sf::Text &buttonMenuText2, sf::Text &buttonMenuText3) -> void {

    window.draw(titleText);
    window.draw(buttonMenuFrame1);
    window.draw(buttonMenuText1);
    window.draw(buttonMenuFrame2);
    window.draw(buttonMenuText2);
    window.draw(buttonMenuFrame3);
    window.draw(buttonMenuText3);
}
