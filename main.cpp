#include "wordle.h"

#include <iostream>

int main()
{
  Wordle wordle("dict.txt");

  int tries{6};
  std::string word;

  while (tries--)
  {
      std::cout << "Please enter the guess word: ";
      std::cin >> word;

      // need a word validation here

      const auto& resp = wordle.guess(word);

      if (resp.first)
      {
          std::cout << "Congrats! You guessed the word :)\n";
      }
      else
      {
          std::cout << "Bad luck, please hit enter to try again\n";
      }

      std::cout << resp.second << std::endl;

      // wait until enter is pressed
      std::cin.get();
  }
  // ...
}
