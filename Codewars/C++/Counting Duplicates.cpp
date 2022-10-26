#include <cctype>

size_t duplicateCount(const std::string& in);
size_t duplicateCount(const char* in) {
  std::string used;
  std::string duplicates;
  size_t result = 0;
  
  for (int i = 0; in[i]; i++) {
    char c = std::tolower(in[i]);
    if (used.find(c) == std::string::npos) {
      used += c;
    }
    else if (duplicates.find(c) == std::string::npos) {
      result++;
      duplicates += c;
    }
  }
  
  return result;
}
