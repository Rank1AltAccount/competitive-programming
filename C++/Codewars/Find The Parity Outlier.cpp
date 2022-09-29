 int FindOutlier(std::vector<int> arr) {
  bool oddArray;
  bool a = arr[0] % 2, b = arr[1] % 2, c = arr[2] % 2;
  if (a and b and c) {
    oddArray = true;
  }
  else if (a == 0 and b == 0 and c == 0) {
    oddArray = false;
  }
  else {
    if ((a and b) or (a == 0 and b == 0)) {
      return arr[2];
    } 
    else if ((a and c) or (a == 0 and c == 0)) {
      return arr[1];
    }
    else {
      return arr[0];
    }
  }
   
  for (int i = 0; i < arr.size(); i++) {
    if (bool(arr[i] % 2) != oddArray) {
      return arr[i];
    }
  }
}
