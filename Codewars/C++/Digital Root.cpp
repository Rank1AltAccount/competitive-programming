 int digitsum(int n) {
  int sum;
  for (sum = 0; n > 0; sum += n % 10, n /= 10);
  return sum;
}

int digital_root(int n) {
  for (n; n > 9; n = digitsum(n));
  return n;
}
