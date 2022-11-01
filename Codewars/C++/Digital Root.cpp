int digitsum(int n) {
    int sum;

    for (sum = 0; n > 0; sum += n % 10, n /= 10);

    return sum;
}

// Calculate the sum of individual digits of a number
// until the result is a single digit number (it's digital root)
int digital_root(int n) {
    for (n; n > 9; n = digitsum(n));

    return n;
}
