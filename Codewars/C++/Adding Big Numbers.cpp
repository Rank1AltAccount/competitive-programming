#include <string>

constexpr int max(int a, int b) {
    return a > b ? a : b;
}

// Add two positive base 10 integers
std::string add(const std::string& a, const std::string& b) {
    std::string result = "";

    const int maxIterations = max(a.size(), b.size());
  
    int remainder = 0; 
 
    // Add individual digits starting from the right
    for (int i = 0; i < maxIterations or remainder; i++) {
        int digitA = 0;
        int digitB = 0;

        const int indexA = a.size() - i - 1;
        const int indexB = b.size() - i - 1;

        // Convert string characters to integers
        // if they are not out of bounds
        if (indexA >= 0) {
            digitA = a[indexA] - '0';
        }

        if (indexB >= 0) {
            digitB = b[indexB] - '0';
        }

        const int digitSum = digitA + digitB + remainder;

        // Add the last digit of the sum to the left of result
        result.insert(0, std::to_string(digitSum % 10)); 

        // Calculate the remainder (0 or 1)
        remainder = digitSum / 10;
    }
    
    return result;
}
