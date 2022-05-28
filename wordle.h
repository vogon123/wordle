#pragma once

#include <string>
#include <unordered_set>

using GuessResponse = std::pair<bool, std::string>;

class Wordle final
{
 public:
  explicit Wordle(const std::string& dictionary);

  GuessResponse guess(const std::string& word);

 private:
  static std::string get_word(const std::string& filename);
  static std::string exact_print(char c);
  static std::string contains_print(char c);

  const std::string secret_word;
  const std::unordered_set<char> secret_letters;
};
