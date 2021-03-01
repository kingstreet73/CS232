// Example: bubble sort strings in array 

#include <stdio.h>  // Need for standard I/O functions //
#include <string.h> //Need for strlen() //
#include <stdlib.h> // Need for malloc() //

#define NUM 30   // number of strings //
#define LEN 1200  // max length of each string //

int main()
{
  int length;
  char * Strings[NUM];
  //Strings = (char*)malloc(LEN);
 // temp = (char*)malloc(LEN);


  printf("Please enter %d strings, one per line:\n", NUM);

  // Write a for loop here to read NUM strings.
  for(int i=0; i<NUM; i++){
    Strings[i] = (char*)malloc(LEN);
    fgets(Strings[i], LEN, stdin); //not sure if should be strings[num] or just strings
  }
  /*   Use fgets(), with LEN as an argument to ensure that an input line that is too
     long does not exceed the bounds imposed by the string's length. However, each 
     string stored in array Strings must not waste space. That is, only the buffer
     used by fgets() to temporary store the string read from input stream needs to 
     be LEN bytes long.
     Note that the newline and NULL characters will be included in LEN.
  */

  puts("\nHere are the strings in the order you entered:");

  /* Write a for loop here to print all the strings.*/
  for(int i=0; i<NUM; i++){
    printf("%s", Strings[i]);
  }

  // Bubble sort //
  // Write code here to bubble sort the strings in ascending alphabetical order */

    /* Your code must meet the following requirements:
        (i) The comparison of two strings must be done by checking them one
            character at a time, without using any C string library functions.
            That is, write your own while/for loop to do this.
       (ii) Implement a swap function to swap two strings by swapping pointers
        without copying any chars.You are not allowed to use any C library 
        functions in swap.*/
        
        
 void swap(char *str1, char *str2){
  char *temp = str1;
  str1 = str2;
  str2 = temp;
  }

  for(int i=1; i<=NUM;i++){
    for(int j=0; j<=NUM; j++){
      if(strcmp(Strings[j],Strings[j+1])>0){
        swap(Strings[j],Strings[j+1]);
      }
    }

  }
     /* void swap(char *str1, char *str2){
        char *temp = str1;
        str1 = str2;
        str2 = temp;
        }*/
        
     //(iii) You are allowed to use strlen() to calculate string lengths.
     // length = strlen(Strings[i])-2;
  // Output sorted list // 

  puts("\nIn alphabetical order, the strings are:");
  for(int i=1; i<=NUM; i++){
    printf("%s", Strings[i]);
    free(Strings[i]);
  }
  return 0;
  /* Write a for loop here to print all the strings. Feel free to use puts/printf
     etc. for printing each string.
  */

}