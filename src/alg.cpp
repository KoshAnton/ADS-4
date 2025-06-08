// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  int pos = 0;
  while (pos < len - 1) {
    int next = pos + 1;
    while (next < len) {
      if (arr[pos] + arr[next] == value) {
        count += 1;
      }
      next++;
    }
    pos++;
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int right = len - 1;
  while (right >= 0) {
    if (arr[right] <= value) {
      break;
    }
    right--;
  }
  int left = 0;
  while (left < right) {
    int current = right;
    while (current > left) {
      if (arr[left] + arr[current] == value) {
        count += 1;
      }
      current--;
    }
    left++;
  }
  return count;
}
int countPairs3(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len - 1; i++) {
    if (i > 0 && arr[i] == arr[i - 1]) continue;
    int target = value - arr[i];
    const int* pos = std::lower_bound(arr + i + 1, arr + len, target);
    if (pos != arr + len && *pos == target) {
      if (pos == arr + i + 1 || *(pos - 1) != target) {
        count++;
      }
    }
  }
  return count;
}
