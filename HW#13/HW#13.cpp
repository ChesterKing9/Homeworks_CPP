#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>

std::vector<std::string> loadWordsFromFile(const std::string& filename) {
    std::vector<std::string> words;
    std::ifstream file(filename);
    std::string word;

    while (file >> word) {
        if (const unsigned WORD_LENGTH = 5) {
            words.push_back(word);
        }
    }

    return words;
}

std::string compareWords(const std::string& guessed, const std::string& target) {
    std::string result = "*****";
    std::vector<bool> used(5, false);

    for (size_t i = 0; i < 5; ++i) {
        if (guessed[i] == target[i]) {
            result[i] = toupper(guessed[i]);
            used[i] = true;
        }
    }

    for (size_t i = 0; i < 5; ++i) {
        if (result[i] == '*') {
            for (size_t j = 0; j < 5; ++j) {
                if (!used[j] && guessed[i] == target[j]) {
                    result[i] = tolower(guessed[i]);
                    used[j] = true;
                    break;
                }
            }
        }
    }

    return result;
}

int main() {
    std::vector<std::string> database = loadWordsFromFile("words.txt");

    if (database.empty()) {
        std::cerr << "Error: Could not load words from file." << std::endl;
        return 1;
    }

    std::srand(std::time(nullptr));
    std::string wordOfTheDay = database[std::rand() % database.size()];
    bool wordOfTheDayGuessed = false;

    int option;
    do {
        std::cout << "1 - Wordle of the day\n2 - Random Wordle\n0 - Exit\nEnter: ";
        std::cin >> option;

        if (option == 1 && wordOfTheDayGuessed) {
            std::cout << "Already found! Come back tomorrow!\n";
            continue;
        }

        if (option == 1 || option == 2) {
            std::string targetWord = (option == 1) ? wordOfTheDay : database[std::rand() % database.size()];
            int attempts = 0;
            std::string guess;

            std::cout << "\nRESULT : *****" << std::endl;

            while (true) {
                std::cout << "ENTER  : ";
                std::cin >> guess;

                if (guess.length() != 5) {
                    std::cout << "Please enter a 5-letter word.\n";
                    continue;
                }

                ++attempts;
                std::string result = compareWords(guess, targetWord);
                std::cout << "RESULT : " << result << std::endl;

                if (guess == targetWord) {
                    std::cout << "\nThat's right!\nYou made " << attempts << " tries!\n";
                    if (option == 1) wordOfTheDayGuessed = true;
                    break;
                }
            }
        }

    } while (option != 0);

    std::cout << "Goodbye!\n";
    return 0;
}
