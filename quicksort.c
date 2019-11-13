#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b){
  int temp = *a;
  *a = *b;
  *b = temp; 
}

void quick_sort(int a[], int n){
  if (n <= 1) return;
  int m = 0;
  int p = a[0];
  for (int i = 1; i < n; i++){
    if(a[i] < p){
      m++;
      swap(&a[i], &a[m]);
    }
  }
  swap(&a[0], &a[m]);
  quick_sort(a, m); // DOES NOT INCLUDE PIVOT
  quick_sort(a + m + 1, n - m - 1);
}

int main (void){
  int a[] = {6,2,5,8,3,6,8,10};
  int n = 8;
  quick_sort(a, n);
  for (int i = 0; i < n; i++){
    printf("%d, ",a[i]);
  }
}