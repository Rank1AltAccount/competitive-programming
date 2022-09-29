#include <regex> 

int countSmileys(std::vector<std::string> arr) {
  int result = 0;
  std::regex expr("[:;](?:-|~)?[)D]");
  for (int i = 0; i < arr.size(); i++) { 
    if (std::regex_search(arr[i], expr)) {
      result++;
    }
 }
  
  return result;
}
