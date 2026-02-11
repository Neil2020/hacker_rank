#include<stdio.h>

int simpleArraySum(int ar_count, int* ar){
  //result 
  int result = 0;
  //for loop
  int i;
  for (i = 0; i < ar_count;i++){
    printf(" \nvalue %d of arr val %d", i, ar[i]);
    result = ar[i] + result;
  }
  return result;
}

int main (){
  int numbers[5] = {1,2,3,4,5};
  int sumOfArr  = simpleArraySum(sizeof(numbers)/sizeof(numbers[0]), numbers);
  printf("\n The Value is: %d \n", sumOfArr);
  int numbersOne[1] = {1};
  int sumOfArrOne  = simpleArraySum(sizeof(numbersOne)/sizeof(numbersOne[0]), numbersOne);
  printf("\n The Value is: %d \n", sumOfArrOne);
  return 0;
}
