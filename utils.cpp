#include "utils.h"

#include <iostream>

namespace utils
{
    bool isWordValid(const std::string& word)
    {
        if (word.size() != 5)
        {
            std::cout << "The word should contain 5 letters\n";
            return false;
        }

        for (auto c : word)
        {
            if (!std::isalpha(c))
            {
                std::cout << "Please use only the letters from alphabet\n";
                return false;
            }
        }

        return true;
    }
} // namespace utils