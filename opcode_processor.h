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
//perform Load Word operation
void LW(char *text_line, char *file_name);
//perform End operation 
void NOP(char *text_line,char *file_name);  
//perform JMP operation
void JMP(char *text_line,char *file_name,int line_count);
//perform SLT operation
void slt(char *text_line,char *file_name);
//perform BEQ operation
void beq(char *text_line,char *file_name,int line_count);
//perform BNE operation
void bne(char *text_line,char *file_name,int line_count);

#endif