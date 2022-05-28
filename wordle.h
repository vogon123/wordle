#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using GuessResponse = std::pair<bool, std::string>;

class Wordle
{
 public:
  explicit Wordle(const std::string& dictionary)
  : secret_word(get_word(dictionary)) {}

  GuessResponse guess(const std::string& word);

 private:
  static std::string get_word(const std::string& filename);
  static std::string exact_print(char c);
  static std::string contains_print(char c);

  std::string secret_word;
};
