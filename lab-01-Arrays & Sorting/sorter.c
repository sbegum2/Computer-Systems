/*
 * Swarthmore College, CS 31
 * Copyright (c) 2023 Swarthmore College Computer Science Department,
 * Swarthmore PA
 */

/*
 * TODO: add your top-level comment here

 * This program reads and sorts floating-point numbers
   using a selection sort algorithm.
 * 
 */

#include <stdio.h>      // the C standard I/O library
#include <stdlib.h>     // the C standard library
#include <string.h>     // the C string library
#include "readfile.h"   // my file reading routines

/* #define constant values here: */
#define MAXFILENAME  128
#define ARRAYSIZE    1000

/* function prototypes: */
void get_filename_from_cmdline(char filename[], int argc, char *argv[]);
//void swap(float values[], int i, int j);
void swap(float array[], int i , int j){
  float temp;
  temp = array[i];
  array[i] = array[j];
  array[j] = temp;
// return array;
}
  
// TODO: add your function prototypes here:

/********************************************************************/
int main (int argc, char *argv[]) {

  int ret;                    /* for storing function return values */
  char filename[MAXFILENAME]; /* the input filename  */
  float values[ARRAYSIZE];    /* stores values read in from file */
  int x;
  float s;
  float e;
  //float n; //numbers in file
  int continued; 
  float array[ARRAYSIZE];
  int check;

  /* TODO: declare all additional variables here: */

  get_filename_from_cmdline(filename, argc, argv);

  /* try to open file */
   
    ret = open_file(filename);
    if(ret == -1) {
    printf("ERROR: can't open %s\n", filename);
    /* exit quits the program immediately. Some errors are not 
     * recoverable. Exit with an error message to handle these cases. */
    exit(1);
  }

  // TODO: read in file header to get number of floats needed
    ret = read_int(&x);
    ret = read_float(&s);
    ret = read_float(&e);

  // TODO:
  // tell the user:
  // (1) the name of the file being read
  printf("Reading file named %s\n", filename);


  // (2) how many float values there are
  // (3) the min and max values
  printf("The file has %d floats ranging from %0.2f to %0.2f \n", x, s, e);
  printf("The unsorted values are: ");
  // TODO: read in floats from file
  for (int i =0; i<x; i++){
    array[i]=e;
    ret = read_float(&e);
    printf("%0.2f ", e);
    if (i==x-1){
      printf("\n");
    }
  }

  // TODO: sort the array in place using a function
  continued = 1;
  while (continued) {
    continued = 0;
    for (int i = 0; i<x; i++){
      if(array[i]>array[i+1]){
        swap(array, i, i+1);
        continued = 1; 
      }
    }
  }

  // TODO: check that the array is now sorted  
  check = 1;
  for (int i = 0; i<x; i++) {
    if(array[i] > array[i+1]){
      check = 0;
    }
  }
  if(check != 0) {
    printf("The array is now sorted\n");
  } else {
        printf("The array is not sorted\n");
  }

  // TODO: print out sorted values in the array

  printf("The sorted values are: ");
  for (int i =0; i<x; i++){
    printf("%0.2f ", array[i]);
    if (i==x-1){
      printf("\n");
    }
  } 

  close_file();  /* close file */
  return 0;

 
}
/***********************************************************/
// TODO: ADD YOUR FUNCTION DEFINITONS HERE:


/***********************************************************/
/* THE FOLLOWING FUNCTION IS PROVIDED FOR YOU
 * DO NOT MODIFY, OR DO SO AT YOUR OWN RISK!
 *
 * This function gets the filename passed in as a command line option
 * and copies it into the filename parameter. It exits with an error
 * message if the command line is badly formed.
 *
 *   filename: the string to fill with the passed filename
 *   argc, argv: the command line parameters from main
 *               (number and strings array)
 kncowcjndj
 */
void get_filename_from_cmdline(char filename[], int argc, char *argv[]) {

  if(argc != 2) {
    printf("Usage: ./exp integer_file\n");
    exit(1);
  }
  if(strlen(argv[1]) >= MAXFILENAME) {
    printf("Filename, %s, is too long, cp to shorter name and try again\n",
        filename);
    exit(1);
  }
  strcpy(filename, argv[1]);
}

