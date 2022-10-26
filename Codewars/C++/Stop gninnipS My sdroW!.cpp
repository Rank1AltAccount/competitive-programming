#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>

std::string spinWords(const std::string& str) {
    if (str.size() < 5) { 
        return str;
    }

    std::string result;
    std::istringstream iss(str);
    std::vector <std::string> tokens{std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};
  
    for (std::string token : tokens) {
        if (token.size() > 4) {
            std::reverse(token.begin(), token.end());
        }
        result += token + " ";
    }

    return result.substr(0, result.size() - 1);
}
