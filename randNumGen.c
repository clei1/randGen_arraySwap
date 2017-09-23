#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

  //will return the current EPOCH time, it is commonly used with srand() to get new random sequences
  printf("current epoch time: %ld\n\n", time(NULL));

  //srand(<SEED>) seeds the random number generator with the provided argument.
  //If you use the same argument to srand() multiple times, you will get the exact same sequence of random numbers.
  srand(time(NULL));
  printf("trying number gen: %d\n\n", rand());

  int arr1[10];
  int i;
  for(i = 0; i < 10; i ++){
    arr1[i] = rand();
    printf("arr1[%d]: %d\n", i, arr1[i]);
  }

  printf("\nchanging arr1[9] to 0\n");
  arr1[9] = 0;
  for(i = 0; i < 10; i ++){
    printf("arr1[%d]: %d\n", i, arr1[i]);
  }

  int arr2[10];

  printf("\nworking with pointers\n");
  //* creates a pointer
  int *p;
  int *p1;
  for(i = 0; i < 10; i ++){
    //& address of variable arr1[i]
    p = &arr1[i];
    if(i == 0){
      p1 = &arr1[i];
    }
    printf("Address of arr1[%d]: %d", i, p);
    printf("       Value at address: %d\n", *p);
    arr2[9 - i] = *p;
    printf("Address of arr1[%d]: %d", i, p);
    printf("       Value at address: %d\n", *p);
  }

  printf("\nchecking arr2\n");
  for(i = 0; i < 10; i ++){
    printf("arr2[%d]: %d\n", i, arr2[i]);
  }
  
  p = &arr1[0];
  printf("\nsetting p to &arr1[0]\n");
  printf("expected: %d\n", p1);
  printf("outcome: %d\n", p);

  printf("\nusing using p++\n");
  for(i = 0; i < 10; i ++){
    printf("address: %d", p);
    printf("        value at address: %d\n", *p);
    p++;
  }

  int arr3[10];
  int *p3 = &arr3[9];
  printf("\narr3[9] address: %d\n", p3);
  printf("value at address: %d\n", *p3);
  printf("value at arr3[9]: %d\n\n", arr3[9]);

  for(i = 0; i < 10; i ++){
    *p3 = *p1;
    p3 --;
    p1 ++;
  }

  printf("should be matching\n");
  for(i = 0; i < 10; i ++){
    printf("arr3[%d]: %d", i, arr3[i]);
    printf("  arr2[%d]: %d", i, arr2[i]);
    printf("  arr1[%d]: %d\n", 9-i, arr1[9-i]);
  }
  
  return 0;
}
