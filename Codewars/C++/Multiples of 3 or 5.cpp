// Find the amount of multiples of 3 or 5 up to the given numbers
int solution(int number) {
    if (number < 0) {
	return 0;
    }

    int result = 0;

    for (int i = 3; i < number; i++) {
	if (i % 3 == 0 or i % 5 == 0) {
	    result += i;
	} 
    }

    return result;
}
