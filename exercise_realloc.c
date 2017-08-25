#include <stdio.h>
#include <stdlib.h>

// This program takes input and outputs average

int main()
{
  // create pointers
  float *data, *temp;
  
  // initial allocation for data
  data = malloc(sizeof(float));

  float f;  // f is the current character
  int i;    // i is the counter
  i = 0;

  // this takes care of input
  // it will accept numbers and exit while loop when it encounter non number
  // or ctrl + D
  while ( scanf("%f" , &f ) == 1 ) {
    
    // put the character into the data array
    data[i] = f;                        
    
    // not sure but here goes:
    // give the pointer some memory
    // since data already has something stored,
    // we increase allocation to 2 for next input with the size of float
    // we point temp to the reallocated data
    temp = realloc(data,(i+2)*sizeof(float));

    if ( temp != NULL ) {
      // not sure but here goes:
      // we make data point to temp as well
      data = temp;
    } else {
      free(data);
      printf("Error allocating memory!\n");
      return 1;
    }  
    
    // increment
    i++;  
  }
  
  // output data
  int x;
  x = 0;
  for (x=0;x<i;x++) {
    printf("Data %d: %f\n", x+1, data[x]);
  }
  
  // compute total
  float total;
  total = 0.00;
  for (x=0;x<i;x++) {
    total += data[x];
  }
  printf("Total: %f.\n", total);
  
  // compute average
  float average;
  average = 0;
  average = total / i;
  printf("Average: %f.n", average);
  
  
  // free the pointer
  free(data);
  
  // return success
  return 0;
}