int solution(int number) {
  if (number < 0) {
    return 0;
  }

  int ret = 0;
  
  for (int i = 3; i < number; i++) {
    if (i % 3 == 0 or i % 5 == 0) {
      ret += i;
    } 
  }
  
  return ret;
}
