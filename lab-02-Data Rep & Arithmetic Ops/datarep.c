/*
 * Swarthmore College, CS 31
 * Copyright (c) 2023 Swarthmore College Computer Science Department,
 * Swarthmore PA
 */

/* CS31 Data Representation and Arithmetic Operations lab: Part 2
 *
 * !! Do not include your name !! 
 * We will be grading labs anonymously
 *
*/
#include <stdio.h>

/*
 * See the lab description for a full description of what each
 * question is asking you to do.
 */

/****************************************************/
/*
 * This functions answers Q1: how many different representations
 * can printf display the value 97?
 */
void question1() {
  int val;
  val = 97;

  printf("\n**** Question 1 ****\n");
  printf("printf can display the value 97 as 3 different representations:\n");
  printf("  as a decimal  = %d \n", val);
  printf("  as a hexadecimal = %X\n", val);
  printf("  as a character = %c\n", val);
  printf("  as a float = %.2f\n", (float)val);

}
/****************************************************/
/*
 * Answers Q2: What is the max value that can be stored
 * in an unsigned int variable?
 */
void question2() {
  unsigned s, i;
  printf("\n**** Question 2 ****\n");
  printf("The max value that an unsigned int can store...\n");
  printf("An unsigned int is 4 bytes, N=32 bits.\n");
  s=1;
  for (i=1; i<33; i++) {
    s = 2*s;
  }
  s-=1;
  printf("The max value for N bits is 2^N - 1 = %u.\n", s);
  printf("If we add 1 to this value, we get overflow: %u.\n", s+1);

}
/****************************************************/
/*
 * Answers Q3: What is the maximum positive value 
 * that can be stored in a C int variable (signed)?
 */
 void question3() {
  signed s=1, i;
  printf("\n**** Question 3 ****\n");
  printf("The max positive value that a signed int can store...\n");
  printf("A signed int is 4 bytes, N=32 bits.\n");
  for (i=1; i<32; i++) {
    s = 2*s;
  }
  s -= 1;
  printf("The max value for N bits is 2^(N-1) - 1 = %d.\n", s);
  printf("If we add 1 to this value, we get overflow: %d.\n", s+1);
 }
/****************************************************/
/*
 * Answers Q4: What arithmetic operation is equivalent 
 * to left shifting an unsigned int value by 1?
 */
 void question4() {
  unsigned i;
  printf("\n**** Question 4 ****\n");
  printf("Left shifting an unsigned int val by 1:\n");
  for (i=1; i<10; i++) {
    printf("%u, %u\n", i, i << 1);
  }
  printf("Left shifting by 1 is equivalent to doubling the value.\n");
  
 }
/****************************************************/
/*
 * Answers Q5: What arithmetic operation is equivalent 
 * to left shifting an unsigned int value by 2?
 */
 void question5() {
  unsigned i;
  printf("\n**** Question 5 ****\n");  
  printf("Left shifting an unsigned int value by 2:\n");
  for (i=1; i<10; i++) {
    printf("%u, %u\n", i, i << 2);
  }
  printf("Left shifting by 2 is equivalent to quadrupling the value.\n");
 }
/****************************************************/
/*
 * Answers Q6: What arithmetic operation is equivalent 
 * to right shifting an unsigned int value by 1?
 */
 void question6() {
  unsigned i;
  printf("\n**** Question 6 ****\n");
  printf("Right shifting an unsigned int value by 1:\n");
  for (i=1; i<10; i++) {
    printf("%u, %u\n", i, i >> 1);
  }
  printf("Right shifting by 1 is equivalent to integer division by 2.\n");
 }
/****************************************************/
int main() {

  question1();
  question2();
  question3();
  question4();
  question5();
  question6();

  return 0;
}
