#include <cctype>

// Count the amount of duplicate characters in a string
size_t duplicateCount(const std::string& in);
size_t duplicateCount(const char* in) {
    std::string used;
    std::string duplicates;

    size_t result = 0;

    for (int i = 0; i < in.size(); i++) {
	// Convert the character to lowercase for convenience
	const char c = std::tolower(in[i]);

	// If the character has not been used
	if (used.find(c) == std::string::npos) {
	    used += c;
	}
	else if (duplicates.find(c) == std::string::npos) {
	    duplicates += c;
	    result++;
	}
    }

    return result;
}
