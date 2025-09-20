#include "ClassForGame.h"
#include "SFML/Graphics.hpp"

auto updatingTextPositions(std::vector<wordOnScreen>& wordsOnScreen, const float &timeLeft,
                           float const& wordSpeed) -> void {
    for (auto& word : wordsOnScreen) {

        word.xP += wordSpeed * timeLeft; // pozycja = piksely na secunde
        auto letterX = word.xP;
        for (auto& letter : word.letters) {

            letter.setPosition(letterX, word.yP);

//                        word.letters[i].setPosition(word.xP + i * 20, word.yP);

            letterX += letter.getLocalBounds().width + 2; // spójnosć liter

        }
        if (word.xP >= 0 && !word.allVisible) {
            word.allVisible = true;
        }
    }
}

auto deleteWords(std::vector<wordOnScreen>& wordsOnScreen, int& numberHeartsInteger, int &action) -> void {
    for (auto it = wordsOnScreen.begin(); it != wordsOnScreen.end();) {
        if ((*it).xP > 1600) {

            numberHeartsInteger--;
            it = wordsOnScreen.erase(it);
            if (numberHeartsInteger <= 0){
                action = 10;

            }
        } else {
            it++;
        }
    }
}

auto checkVerticalCollision(const wordOnScreen& word1, const wordOnScreen& word2) -> bool {
    auto size = 0;

    if(word1.letters.size() > word2.letters.size()){
        size = word2.letters.size();
    } else {
        size = word1.letters.size();
    }
    auto word1Top = word1.yP;
    auto word2Top = word2.yP;

    auto overlap = true;

    for(auto i = 0; i < size; i++){ // każda litera sprawdza
        auto word1Bottom = word1.yP + word1.letters[i].getGlobalBounds().height + 5;

        auto word2Bottom = word2.yP + word2.letters[i].getGlobalBounds().height + 5;

        overlap = word1Bottom > word2Top && word1Top < word2Bottom;

        if (!overlap){
            break;
        }

    }

    return overlap;
}

auto randomWordFromFile(std::vector<std::string> &wordsFromFile) -> std::string {
    auto randomIndex = std::rand() % wordsFromFile.size();

    std::string newString = wordsFromFile[randomIndex];

    return newString;
}

auto randomWordFromRandom() -> std::string {
    auto lettres = std::vector<char>{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                                     'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

    auto wordSize = rand() % 9 + 3;
    auto word = std::string();
    for (auto i = 0; i < wordSize; i++) {
        auto randomIndex = rand() % lettres.size();
        auto letter = lettres[randomIndex];

        word += letter;
    }
    return word;

}

auto randomWordFromAlien() -> std::string {
    auto what = std::vector<char>{'$', '#', '@', '/', '&','%', '^', '0', '!', '>', '<'};

    auto wordSize = rand() % 8 + 2;

    auto wordAlien = std::string();
    for (auto i = 0; i < wordSize; i++) {
        auto randomIndex = rand() % what.size();
        auto letter = what[randomIndex];

        wordAlien += letter;
    }
    return wordAlien;
}

auto randomWordForAccountants() -> std::string {
    auto numbers = std::vector<char>{'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    auto fos = std::vector<char>{'*', '/', '+', '-'};

    auto firstSize = rand() % 5 + 1;
    auto secondSize = rand() % 5 + 1;

    auto wordAccountants = std::string();
    for (auto i = 0; i < firstSize; i++) {
        auto randomIndex = rand() % numbers.size();
        auto letter = numbers[randomIndex];

        wordAccountants += letter;
    }

    auto randomFos = rand() % fos.size();
    wordAccountants += randomFos;

    for (auto i = 0; i < secondSize; i++) {
        auto randomIndex = rand() % numbers.size();
        auto letter = numbers[randomIndex];

        wordAccountants += letter;
    }

    return wordAccountants;
}

auto createNewWord(sf::Font const &font, std::vector<wordOnScreen>& wordsOnScreen,
                   std::vector<std::string> &wordsFromFile, sf::RenderWindow& window, int const &howToCreat) -> void {
    sf::Text newText;
    newText.setFont(font);
    newText.setCharacterSize(30);
    newText.setFillColor(sf::Color::White);
    auto newString = std::string("");
    if (howToCreat == 1) {
        newString = randomWordFromFile(wordsFromFile);

    } else if (howToCreat == 2){

        newString = randomWordFromRandom();
    } else if (howToCreat == 3){

        newString = randomWordFromAlien();
    } else if (howToCreat == 4){

        newString = randomWordForAccountants();
    }

    newText.setString(newString);

    auto oYrandom = 0.f;
    auto errorWord = false; // jeżeli słowo będzie pokrywało inne słowo
    auto numberOfPossibilities = 50; // ilosć prób specjalnie żeby program się nie zawieszaw
    auto possibilities = 0;
    while (possibilities < numberOfPossibilities) {
        errorWord = false;
        oYrandom = 50 + std::rand() % (window.getSize().y - 120);

        auto newWord = wordOnScreen(-100.0f, oYrandom, false);

        newWord.letterFormation(newString, font);

        for (const auto& word : wordsOnScreen) {
            if (checkVerticalCollision(newWord, word)) {
                errorWord = true;
                break;
            }
        }

        if (!errorWord) { // wyskakujemy z pętli żeby stworzyć nowe słowo
            break;
        }

        possibilities++;

    }

    if (!errorWord) {
        wordOnScreen newWord(-100.0f, oYrandom, false); // tutaj
        newWord.letterFormation(newString, font);
        wordsOnScreen.push_back(newWord);
    }

}




auto drawWords(std::vector<wordOnScreen> &wordsOnScreen, sf::RenderWindow & window) -> void {
    for (const auto& w : wordsOnScreen) {
        for (const auto& l : w.letters) {
            window.draw(l);
        }
    }
}
