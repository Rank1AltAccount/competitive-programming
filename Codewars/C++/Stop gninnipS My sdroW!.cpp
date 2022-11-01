#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <algorithm>

// Reverse words longer than 4 characters in a string
std::string spinWords(const std::string& str) {
    // Do nothing if string is shorter than 5 characters
    if (str.size() < 5) { 
	return str;
    }

    std::string result;

    std::istringstream iss(str);

    // Split all words separated by space into a vector
    std::vector<std::string> tokens{ std::istream_iterator<std::string>{ iss }, std::istream_iterator<std::string>{} };

    for (std::string token : tokens) {
	if (token.size() > 4) {
	    std::reverse(token.begin(), token.end());
	}

	result += token + " ";
    }

    // Remove the trailing space at the end
    return result.substr(0, result.size() - 1);
}
