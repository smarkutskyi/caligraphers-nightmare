#include <fmt/ranges.h>
#include <SFML/Graphics.hpp>
#include "AllButtonsItems/menuItems.h"
#include "AllButtonsItems/gForPointsItems.h"
#include "Controller/mouseController.h"
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "AllButtonsItems/gameItems.h"
#include "GameHeart/ClassForGame.h"
#include "Controller/keyboardController.h"
#include "GameHeart/MethodsForGame.h"
#include "AllButtonsItems/fontItems.h"
#include "AllButtonsItems/arcadeItems.h"



sf::Text titleText;
sf::RectangleShape buttonMenuFrame1, buttonMenuFrame2, buttonMenuFrame3;
sf::Text buttonMenuText1, buttonMenuText2, buttonMenuText3;

sf::Text basedGameForPointsText;
sf::RectangleShape buttonGFPointsFrame1, buttonGFPointsFrame2,buttonGFPointsFrame3;
sf::Text buttonGFPointsText1, buttonGFPointsText2, buttonGFPointsText3;

std::vector<std::string> wordsFromFile;

sf::Text exitGameText;
sf::RectangleShape exitGameFrame;
sf::Text textGame;
sf::Text yourTextGame;
sf::Text numberHearts;
sf::Sprite heartImage;
sf::Text gameOver;

int numberHeartsInteger;

std::string textFromPlayer;

sf::Text titleForFont;
sf::Text textFont1, textFont2, textFont3, textFont4;
sf::RectangleShape frameFront1, frameFront2, frameFront3, frameFront4;

sf::Font fontForGamePoint;
sf::Font fontForArcade;

sf::Text basedArcadeGameText;
sf::RectangleShape buttonArcadeFrame1, buttonArcadeFrame2, buttonArcadeFrame3;
sf::Text buttonArcadeText1, buttonArcadeText2, buttonArcadeText3;


auto readWordsFromFile(std::ifstream& file, std::vector<std::string>& words) -> void {
    std::string word;
    while (file >> word) {
        words.push_back(word);
    }
}




auto main() -> int{
    std::srand(std::time(nullptr)); // można było w bardziej nowoczesny sposób zrobić
                                                                       // ale ten jest bardziej prosty
    numberHeartsInteger = 15;

    auto window = sf::RenderWindow(
            sf::VideoMode({1600, 800}), "Calligrapher's Nightmare",
            sf::Style::Titlebar | sf::Style::Close, sf::ContextSettings(0, 0, 8)
    );

    auto fontBased = sf::Font();
    if (!fontBased.loadFromFile("../Salvador.ttf")) {
        fmt::println("NO FILE");
        return 1;
    }
    auto fontAntiCorona = sf::Font();
    if (!fontAntiCorona.loadFromFile("../aAntiCorona.ttf")) {
        fmt::println("NO FILE");
        return 1;
    }
    auto fontArto = sf::Font();
    if (!fontArto.loadFromFile("../Arto.ttf")) {
        fmt::println("NO FILE");

    }
    auto fontBodoni = sf::Font();
    if (!fontBodoni.loadFromFile("../Bodoni.ttf")) {
        fmt::println("NO FILE");
        return 1;
    }
    auto fontArcade = sf::Font();
    if (!fontArcade.loadFromFile("../lol.ttf")) {
        fmt::println("NO FILE");
        return 1;
    }


    auto texture = sf::Texture();
    if(!texture.loadFromFile("../Serdce.png")){
        fmt::println("NO IMAGE");
    }

    heartImage = sf::Sprite(texture);


    initializeItemsMenu(titleText, buttonMenuFrame1, buttonMenuFrame2, buttonMenuFrame3,
                        buttonMenuText1, buttonMenuText2, buttonMenuText3);

    ItemsMenu(fontBased, titleText, buttonMenuFrame1, buttonMenuFrame2, buttonMenuFrame3,
              buttonMenuText1, buttonMenuText2, buttonMenuText3);

    gameOver = sf::Text();
    gameOver.setString("Game Over");
    gameOver.setFillColor(sf::Color::Red);
    gameOver.setFont(fontBased);
    gameOver.setCharacterSize(100);
    gameOver.setPosition(550, 250);


    initializeItemsGFP(basedGameForPointsText, buttonGFPointsFrame1, buttonGFPointsFrame2,
                       buttonGFPointsFrame3, buttonGFPointsText1, buttonGFPointsText2,
                       buttonGFPointsText3);

    itemsGFP(titleText, fontBased, basedGameForPointsText, buttonGFPointsFrame1, buttonGFPointsFrame2,
             buttonGFPointsFrame3, buttonGFPointsText1, buttonGFPointsText2, buttonGFPointsText3);


    initializeItemsGame(exitGameText, exitGameFrame, textGame,yourTextGame, numberHearts);

    itemsGame(fontBased, fontAntiCorona, exitGameText, exitGameFrame, textGame, yourTextGame,
              heartImage, numberHearts);


    initializeItemsFont(titleForFont, frameFront1, frameFront2, frameFront3, frameFront4,
                        textFont1,  textFont2, textFont3, textFont4);

    itemsFont(titleForFont, frameFront1, frameFront2, frameFront3, frameFront4, textFont1,
              textFont2, textFont3, textFont4, fontBased, fontAntiCorona, fontArto, fontBodoni);

    initializeItemsArcade(basedArcadeGameText, buttonArcadeFrame1, buttonArcadeFrame2, buttonArcadeFrame3,
                        buttonArcadeText1, buttonArcadeText2, buttonArcadeText3);

    itemsArcade(titleText, fontBased, basedArcadeGameText, buttonArcadeFrame1, buttonArcadeFrame2,
                buttonArcadeFrame3, buttonArcadeText1, buttonArcadeText2, buttonArcadeText3);

    std::ifstream file("../words.txt");
    readWordsFromFile(file, wordsFromFile);

    std::vector<wordOnScreen> wordsOnScreen;
    sf::Clock clock;


    auto action = 0;
    auto actionFont = 0;
    auto wordSpeed = 200.f;

    while (window.isOpen()) {
        auto mousePosition = sf::Mouse::getPosition(window);
        auto event = sf::Event();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (action == 3 || action == 4 || action == 6 || action == 7){
                speedChange(event, wordSpeed);

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)
                    || sf::Keyboard::isKeyPressed(sf::Keyboard::RControl)) { // ignorujemy przyspieszenie
                    continue;
                } else {
                    playerWordProcessing(event, textFromPlayer, wordsOnScreen,yourTextGame);
                }
            }


        }


        switch (action) {
            case -1: {
                window.close();
                break;
            }

            case 0: {
                window.clear();
                buttonIlluminationMenu(mousePosition, buttonMenuFrame1, buttonMenuFrame2, buttonMenuFrame3);
                drawMenuItems(window, titleText, buttonMenuFrame1, buttonMenuFrame2, buttonMenuFrame3,
                              buttonMenuText1, buttonMenuText2, buttonMenuText3);
                if (event.type == sf::Event::MouseButtonPressed) {
                    mouseMenuButton(event, mousePosition, buttonMenuFrame1, buttonMenuFrame2,
                                    buttonMenuFrame3, action);
                }
                break;
            }
            case 1: {
                window.clear();
                buttonIlluminationGFP(mousePosition, buttonGFPointsFrame1, buttonGFPointsFrame2,
                                      buttonGFPointsFrame3);
                drawGFPItems(window, titleText,basedGameForPointsText, buttonGFPointsFrame1,
                             buttonGFPointsFrame2, buttonGFPointsFrame3, buttonGFPointsText1,
                             buttonGFPointsText2, buttonGFPointsText3);
                if (event.type == sf::Event::MouseButtonPressed) {
                    mouseGFPoButton(event, mousePosition, buttonGFPointsFrame1, buttonGFPointsFrame2,
                                    buttonGFPointsFrame3, action, actionFont);
                }


                numberHeartsInteger = 15;
                wordSpeed = 200.f;
                wordsOnScreen.clear();
                yourTextGame.setString("");


                break;
            }
            case 3: { // Jeżeli słowa z pliku
                window.clear();
                auto timeLeft = clock.restart().asSeconds();

                updatingTextPositions(wordsOnScreen, timeLeft, wordSpeed);

                deleteWords(wordsOnScreen, numberHeartsInteger, action);

                if ( wordsOnScreen.empty() || (wordsOnScreen.back().allVisible && wordsOnScreen.back().xP > 0)){
                    createNewWord(fontForGamePoint, wordsOnScreen, wordsFromFile, window, 1);
                }

                numberHearts.setString(std::to_string(numberHeartsInteger));

                drawWords(wordsOnScreen, window);
                drawGameItems(window, exitGameFrame, exitGameText, textGame,
                              yourTextGame, heartImage, numberHearts);

                buttonIlluminationGame(mousePosition, exitGameFrame);

                if (event.type == sf::Event::MouseButtonPressed){
                    mouseGameButton(event, mousePosition, exitGameFrame, action);
                }

                break;
            }

            case 4: { // Jeżeli słowa z syfu liter
                window.clear();
                auto timeLeft = clock.restart().asSeconds();

                updatingTextPositions(wordsOnScreen, timeLeft, wordSpeed);

                deleteWords(wordsOnScreen, numberHeartsInteger, action);

                if ( wordsOnScreen.empty() || (wordsOnScreen.back().allVisible && wordsOnScreen.back().xP > 0)){
                    createNewWord(fontForGamePoint, wordsOnScreen, wordsFromFile, window, 2);
                }

                numberHearts.setString(std::to_string(numberHeartsInteger));

                drawWords(wordsOnScreen, window);
                drawGameItems(window, exitGameFrame, exitGameText, textGame,
                              yourTextGame, heartImage, numberHearts);

                buttonIlluminationGame(mousePosition, exitGameFrame);

                if (event.type == sf::Event::MouseButtonPressed){
                    mouseGameButton(event, mousePosition, exitGameFrame, action);
                }

                break;
            }
            case 5: {
                window.clear();

                buttonIlluminationArcade(mousePosition, buttonArcadeFrame1, buttonArcadeFrame2,
                                         buttonArcadeFrame3);
                drawArcadeItems(window, titleText, basedArcadeGameText, buttonArcadeFrame1,
                                buttonArcadeFrame2,buttonArcadeFrame3, buttonArcadeText1,
                                buttonArcadeText2, buttonArcadeText3);

                if (event.type == sf::Event::MouseButtonPressed){
                    mouseArcadeButton(event, mousePosition, buttonArcadeFrame1,
                                      buttonArcadeFrame2,buttonArcadeFrame3, action);
                }
                yourTextGame.setFont(fontBased);
                yourTextGame.setString("");
                wordsOnScreen.clear();
                wordSpeed = 200.f;
                numberHeartsInteger = 15;


                break;

            }
            case 6: {
                window.clear();
                auto timeLeft = clock.restart().asSeconds();

                updatingTextPositions(wordsOnScreen, timeLeft, wordSpeed);

                deleteWords(wordsOnScreen, numberHeartsInteger, action);

                if ( wordsOnScreen.empty() || (wordsOnScreen.back().allVisible && wordsOnScreen.back().xP > 0)){
                    createNewWord(fontArcade, wordsOnScreen, wordsFromFile, window, 3);
                }

                yourTextGame.setFont(fontArcade);

                numberHearts.setString(std::to_string(numberHeartsInteger));

                drawWords(wordsOnScreen, window);
                drawGameItems(window, exitGameFrame, exitGameText, textGame,
                              yourTextGame, heartImage, numberHearts);

                buttonIlluminationGame(mousePosition, exitGameFrame);

                if (event.type == sf::Event::MouseButtonPressed){
                    mouseGameArcadeButton(event, mousePosition, exitGameFrame, action);
                }

                break;

            }
            case 7:{
                window.clear();
                auto timeLeft = clock.restart().asSeconds();

                updatingTextPositions(wordsOnScreen, timeLeft, wordSpeed);

                deleteWords(wordsOnScreen, numberHeartsInteger, action);

                yourTextGame.setFont(fontBodoni);

                if ( wordsOnScreen.empty() || (wordsOnScreen.back().allVisible && wordsOnScreen.back().xP > 0)){
                    createNewWord(fontBodoni, wordsOnScreen, wordsFromFile, window, 4);
                }

                numberHearts.setString(std::to_string(numberHeartsInteger));

                drawWords(wordsOnScreen, window);
                drawGameItems(window, exitGameFrame, exitGameText, textGame,
                              yourTextGame, heartImage, numberHearts);

                buttonIlluminationGame(mousePosition, exitGameFrame);

                if (event.type == sf::Event::MouseButtonPressed){
                    mouseGameArcadeButton(event, mousePosition, exitGameFrame, action);
                }

                break;
            }

            case 10: {

                window.clear();

                buttonIlluminationGame(mousePosition, exitGameFrame);
                drawGameItems(window, exitGameFrame, exitGameText,
                              textGame, yourTextGame, heartImage, numberHearts);
                window.draw(gameOver);

                if (event.type == sf::Event::MouseButtonPressed) {
                    mouseGameButton(event, mousePosition, exitGameFrame,action);

                }

                break;
            }
            case 20: {
                window.clear();
                drawFontItems(window, titleForFont, frameFront1, frameFront2, frameFront3,
                              frameFront4,textFont1,  textFont2, textFont3, textFont4);
                buttonIlluminationFont(mousePosition, frameFront1, frameFront2, frameFront3, frameFront4);

                if (event.type == sf::Event::MouseButtonPressed) {
                    mouseFontButton(event, mousePosition, frameFront1, frameFront2, frameFront3, frameFront4,
                                    action, fontForGamePoint, actionFont);

                }

            }
        }


        window.display();
    }

}

