// Count the amount of 1's in the binary representation of a number
unsigned int countBits(unsigned long long n) {
    int result = 0;

    for (n; n > 0; n /= 2) {
	if (n % 2) {
	    result++;
	}
    }

    return result;
}
