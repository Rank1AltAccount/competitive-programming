#include <regex> 

// Count strings resembling a smiley (':-)', ';~D', ...)
int countSmileys(std::vector<std::string> arr) {
    int result = 0;

    // Only specific characters can be used in a smiley face
    const std::regex expr("[:;](?:-|~)?[)D]");

    for (int i = 0; i < arr.size(); i++) { 
	if (std::regex_search(arr[i], expr)) {
	    result++;
	}
    }

    return result;
}
