#include <vector>
#include <algorithm>

int findOdd(const std::vector<int>& numbers) {
    int count = 1;
    int result = 0;

    std::vector<int> newarr = numbers;
    std::sort(newarr.begin(), newarr.end());

    for (int i = 0; i < newarr.size(); i++) { 
	if (newarr[i] == newarr[i + 1]) { 
	    count++;
	}
	else {
	    if (count % 2 != 0) {
		result = newarr[i];
	    }
	    else {
		count = 1;
	    }
	}
    }

    return result;
}
