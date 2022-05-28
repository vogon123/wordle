#include "wordle.h"

#include <ctime>
#include <fstream>
#include <iostream>
#include <locale>
#include <sstream>
#include <vector>

Wordle::Wordle(const std::string& dictionary)
    : secret_word(get_word(dictionary))
    , secret_letters(secret_word.begin(), secret_word.end())
{
}

GuessResponse Wordle::guess(const std::string& word)
{
    bool isMatch{ true };
    std::string checkedWord;

    for (int i{ 0 }; i < secret_word.size(); ++i)
    {
        const auto letterToCheck{ word[i] };
        const auto loweredLetter{ std::tolower(letterToCheck, std::locale()) };


        if (loweredLetter == secret_word[i])
        {
            checkedWord += exact_print(letterToCheck);
        }
        else
        {
            if (secret_letters.count(loweredLetter))
            {
                checkedWord += contains_print(letterToCheck);
            }
            else
            {
                checkedWord += letterToCheck;
            }

            isMatch = false;
        }
    }
    return {isMatch, checkedWord};
}

std::string Wordle::get_word(const std::string& filename)
{
    std::srand(std::time(nullptr));

    std::vector<std::string> result;
    std::ifstream file(filename);
    std::string word;

    if (!file.is_open())
    {
        std::cout << "Can not open: " << filename << std::endl;
        return {};
    }

    while (std::getline(file, word))
        result.push_back(word);

    return result[std::rand() % result.size()];
}

std::string Wordle::exact_print(char c)
{
    std::stringstream ss;
    ss << "\033[1;32m" << c << "\033[0m";

    return ss.str();
}

std::string Wordle::contains_print(char c)
{
    std::stringstream ss;
    ss << "\033[1;33m" << c << "\033[0m";

    return ss.str();
}
