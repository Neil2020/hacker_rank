#include<stdio.h>

int* compareTriplets(int a_count, int* a, int b_count, int* b, int* result_count){
  //loop through the required arrs
  int i;
  for(i = 0; i < a_count; i++){
    if(a[i] == b[i]){
      continue;
    }
    if(a[i] > b[i]){
      result_count[0] = result_count[0] + 1;
    }
    if(a[i] < b[i]){
      result_count[1] = result_count[1] + 1;
    }
  }
  return result_count;
}

int main () {
  //create result arr
  int result_arr[2] = {0,0};
  //alice array 
  int a[3] = {17,28,30};
  //bob array
  int b[3] = {99,16,8};
  //compare the triplits
  compareTriplets((sizeof(a)/sizeof(a[0])), a, (sizeof(b)/sizeof(b[0])), b, result_arr );
  printf("Alice: %d, Bob: %d ",result_arr[0],result_arr[1]);
  return 0;
}
