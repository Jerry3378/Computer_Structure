#ifndef OPCODE_PROCESSOR_H
#define OPCODE_PROCESSOR_H

/* Function declarations for opcode processing.
   These functions perform various arithmetic operations based on the provided instruction. */

//Perform addition operation
void ADD(char *text_line,char *file_name);  
//Perform subtraction operation
void SUB(char *text_line,char *file_name);
//performs multiplication operations
void MUL(char *text_line,char *file_name);
//perform division operation
void DIV(char *text_line,char *file_name);

#endif