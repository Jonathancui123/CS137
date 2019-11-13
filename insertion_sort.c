#include <stdio.h>

void insertion_sort (int *a, int n){
  int i, j, x;
  for (i = 1; i < n; i++) {
    x = a[i];
    for (j = i; j > 0 && x < a[j - 1]; j--){
      //
    }
  }
}