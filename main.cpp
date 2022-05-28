#include "wordle.h"

#include <iostream>

int main()
{
  Wordle wordle("dict.txt");

  int tries{6};
  std::string word;

  while (tries > 0)
  {
      std::cout << "Please enter the guess word (" << tries << " attempts left): ";
      --tries;

      std::cin >> word;

      // need a word validation here

      const auto& resp = wordle.guess(word);

      if (resp.first)
      {
          std::cout << "Congrats! You guessed the word :)\n";
          break;
      }

      if (tries)
      {
          std::cout << "Bad luck, please hit enter to try again\n";
          std::cout << resp.second << std::endl;
      }
      else
      {
          std::cout << "Unfortunately, the game is lost\n";
      }

      // wait until enter is pressed
      std::cin.get();
  }
}
