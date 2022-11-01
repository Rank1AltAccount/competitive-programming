// Determine an integer whose parity is different from other integers
int FindOutlier(std::vector<int> arr) {
    bool isOddVector;

    // Find the parity of the first three elements
    bool a = arr[0] % 2; 
    bool b = arr[1] % 2;
    bool c = arr[2] % 2;

    // Determine the usual pattern of the array

    // If all elements are odd
    if (a and b and c) {
	isOddVector = true;
    }
    // If they're not
    else if (a == 0 and b == 0 and c == 0) {
	isOddVector = false;
    }
    // If the above checks are false, the parity outlier is among the first three elements
    else {
	// Check the 3rd element (c)
	if ((a and b) or (a == 0 and b == 0)) {
	    return arr[2];
	} 
	// Check the 2nd element (b)
	else if ((a and c) or (a == 0 and c == 0)) {
	    return arr[1];
	}
	// If all of the above is false, it's the 1st element (a)
	else {
	    return arr[0];
	}
    }

    for (int i = 0; i < arr.size(); i++) {
	// If the element doesn't match the parity of the other elements
	if (bool(arr[i] % 2) != isOddVector) {
	    return arr[i];
	}
    }
}
