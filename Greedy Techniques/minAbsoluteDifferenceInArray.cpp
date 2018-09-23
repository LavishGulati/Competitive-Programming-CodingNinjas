#include <bits/stdc++.h>

int minAbsoluteDiff(int *arr, int n) {
 std::sort(arr, arr+n);

  int min = INT_MAX;

  for(int i = 0; i < n; i++){
    int element = arr[i+1] > arr[i] ? arr[i+1]-arr[i] : arr[i]-arr[i+1];

    if(min > element) min = element;
  }

  return min;
}
