/*File Name: opcode_processor.c
Description: This file is responsible for processing each command. 
Depending on the opcode of each instruction, it performs the corresponding operation and
, if necessary, manipulates registers or memory.*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "opcode_processor.h"
#include "global_register.h"

int register_num[20] = {0};

// Array of register names
const char *registers[] = {"zero","v0","t0","t1","t2","t3","t4","t5","t6","t7","t8","t9","s0","s1","s2","s3",
    "s4","s5","s6","s7"};

int program_counter = 0;    

//this funcion helps to search register name to register index
int get_register_num(char *token){
    for (int i = 0; i < sizeof(registers)/sizeof(registers[0]); i++){
            if (strcmp(token,registers[i]) == 0)
                return i;
    }

    return -1;
}    

// Function to handle ADD operation
void ADD(char *text_line, char *file_name){
    //함수 실행할때마다 program_counter은 1씩 증가
    program_counter++;

    int index_num = 0;
    char *token_message[3];
    
    char *token;
    //op,rd,rs,rt레지스터//
    int *rd = NULL;
    int *rs = NULL;
    int *rt = NULL;


    
    token = strtok(NULL," \n");
    index_num = get_register_num(token);
    rd = register_num+index_num;
    token_message[0] = token;
    
    token = strtok(NULL," \n");
    index_num = get_register_num(token);
    rs = register_num+index_num;
    token_message[1] = token;

    token = strtok(NULL," \n");
    index_num = get_register_num(token);
    rt = register_num+index_num;
    token_message[2] = token;

    *rd = *rs + *rt;
    printf("%s> Added %s(%d) to %s(%d) and changed %s to %d\n",file_name,token_message[1],*rs,token_message[2],*rt,token_message[0],*rd);

}

// Function to handle SUB operation
void SUB(char *text_line,char *file_name){
    program_counter++;

    int index_num = 0;
    char *token_message[3];
    
    char *token;
    //op,rd,rs,rt레지스터//
    int *rd = NULL;
    int *rs = NULL;
    int *rt = NULL;


    
    token = strtok(NULL," \n");
    index_num = get_register_num(token);
    rd = register_num+index_num;
    token_message[0] = token;
    
    token = strtok(NULL," \n");
    index_num = get_register_num(token);
    rs = register_num+index_num;
    token_message[1] = token;

    token = strtok(NULL," \n");
    index_num = get_register_num(token);
    rt = register_num+index_num;
    token_message[2] = token;

    *rd = *rs - *rt;
    printf("%s> Subtracked %s(%d) to %s(%d) and changed %s to %d\n",file_name,token_message[1],*rs,token_message[2],*rt,token_message[0],*rd);

}

// Function to handle MUL operation
void MUL(char *text_line,char *file_name){
    program_counter++;

    int index_num = 0;
    char *token_message[3];
    
    char *token;
    //op,rd,rs,rt레지스터//
    int *rd = NULL;
    int *rs = NULL;
    int *rt = NULL;


    
    token = strtok(NULL," \n");
    index_num = get_register_num(token);
    rd = register_num+index_num;
    token_message[0] = token;
    
    token = strtok(NULL," \n");
    index_num = get_register_num(token);
    rs = register_num+index_num;
    token_message[1] = token;

    token = strtok(NULL," \n");
    index_num = get_register_num(token);
    rt = register_num+index_num;
    token_message[2] = token;

    *rd = *rs * *rt;
    printf("%s> Multiplied %s(%d) to %s(%d) and changed %s to %d\n",file_name,token_message[1],*rs,token_message[2],*rt,token_message[0],*rd);

}

// Function to handle DIV operation
void DIV(char *text_line,char *file_name){
    program_counter++;

    int index_num = 0;
    char *token_message[3];
    
    char *token;
    //op,rd,rs,rt레지스터//
    int *rd = NULL;
    int *rs = NULL;
    int *rt = NULL;


    
    token = strtok(NULL," \n");
    index_num = get_register_num(token);
    rd = register_num+index_num;
    token_message[0] = token;
    
    token = strtok(NULL," \n");
    index_num = get_register_num(token);
    rs = register_num+index_num;
    token_message[1] = token;

    token = strtok(NULL," \n");
    index_num = get_register_num(token);
    rt = register_num+index_num;
    token_message[2] = token;

    //run_time error : when divided by zero
    if (*rt == 0)
    {
        printf("division by Zero\n");
        free(text_line);
        exit(-1);
    }
    
    *rd = *rs / *rt;
    printf("%s> Divided %s(%d) to %s(%d) and changed %s to %d\n",file_name,token_message[1],*rs,token_message[2],*rt,token_message[0],*rd);

}

// Function to handle SLT operation
void slt(char *text_line,char *file_name){
    program_counter++;

    int index_num = 0;
    char *token_message[3];
    
    char *token;
    //op,rd,rs,rt레지스터//
    int *rd = NULL;
    int *rs = NULL;
    int *rt = NULL;


    
    token = strtok(NULL," \n");
    index_num = get_register_num(token);
    rd = register_num+index_num;
    token_message[0] = token;
    
    token = strtok(NULL," \n");
    index_num = get_register_num(token);
    rs = register_num+index_num;
    token_message[1] = token;

    token = strtok(NULL," \n");
    index_num = get_register_num(token);
    rt = register_num+index_num;
    token_message[2] = token;
    
    //compare rs < rt and return 1 when rs is smaller then rt, return 0 when rs is bigger than rt
    *rd = *rs < *rt ? 1: 0;

    printf("%s> Checked if %s(%d) is less than %s(%d) and set %d to %s\n",file_name,token_message[1],*rs,token_message[2],*rt,*rd,token_message[0]);

}

// Function to handle LW operation
void LW(char *text_line,char *file_name){
    program_counter++;

    int index_num = 0;
    char *token_message;

    char *token = strtok(NULL," \n");
    index_num = get_register_num(token);
    int *rt = register_num+index_num;
    token_message = token;
    
    token = strtok(NULL," ");
    int data = strtol(token,NULL,16);

    *rt = data;
    printf("%s> Loaded %d to %s\n",file_name,*rt,token_message);
}   

// Function to handle NOP operation
void NOP(char *text_line,char *file_name){

    program_counter++;
    printf("%s> No operation\n",file_name);
}

// Function to handle JMP operation
void JMP(char *text_line, char *file_name,int line_count){

    program_counter++;
    int line_no;

    char *token = strtok(NULL," \n");
    line_no = strtol(token,NULL,16);

    printf("%s> jump to line %d\n",file_name,line_no);
    program_counter = line_no-1;

    // Error handling if program counter is out of range
    if (program_counter >= line_count || program_counter < 0)
        {
            printf("out of line\n");
            exit(-1);
        }
    
}

// Function to handle BEQ operation
void beq(char *text_line, char *file_name,int line_count){

    program_counter++;

    int index_num = 0;
    char *token_message[2];

    char *token = strtok(NULL," \n");
    index_num = get_register_num(token);
    int *rs = register_num+index_num;
    token_message[0] = token;
    
    token = strtok(NULL," \n");
    index_num = get_register_num(token);
    int *rt = register_num+index_num;
    token_message[1] = token;

    token = strtok(NULL," \n");
    int line_no = strtol(token,NULL,16);

    if (*rs == *rt)
    {
        printf("%s> Checked if %s(%d) is equal to %s(%d) and jumped to line %d\n",file_name,token_message[0],*rs,token_message[1],*rt,line_no);
        program_counter = line_no-1;
        // Error handling if program counter is out of range
        if (program_counter >= line_count || program_counter < 0)
            {
                printf("out of line\n");
                exit(-1);
            }
    }else{
        printf("%s> Checked if %s(%d) is equal to %s(%d) and don't jumped to line %d\n",file_name,token_message[0],*rs,token_message[1],*rt,line_no);
    }

}

// Function to handle BNE operation
void bne(char *text_line, char *file_name,int line_count){

    program_counter++;

    int index_num = 0;
    char *token_message[2];

    char *token = strtok(NULL," \n");
    index_num = get_register_num(token);
    int *rs = register_num+index_num;
    token_message[0] = token;
    
    token = strtok(NULL," \n");
    index_num = get_register_num(token);
    int *rt = register_num+index_num;
    token_message[1] = token;

    token = strtok(NULL," \n");
    int line_no = strtol(token,NULL,16);

    if (*rs != *rt)
    {
        printf("%s> Checked if %s(%d) is not equal to %s(%d) and jumped to line %d\n",file_name,token_message[0],*rs,token_message[1],*rt,line_no);
        program_counter = line_no-1;
        // Error handling if program counter is out of range
        if (program_counter >= line_count || program_counter < 0)
            {
                printf("out of line\n");
                exit(-1);
            }
    }else{
        printf("%s> Checked if %s(%d) is not equal to %s(%d) and don't jumped to line %d\n",file_name,token_message[0],*rs,token_message[1],*rt,line_no);
    }

}

/*
test code for opcode_processor

int main(int argc,char *argv[]){
    
    char *command_line = NULL;
    FILE *file = NULL;
    //txt에서 문자들을 읽어 문자를 담을 메시지 박스//
    char text_box[MAX_ROWS][MAX_COLS];
    char *opcode;
    

    for (int i = 0; i < MAX_ROWS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            text_box[i][j] = 0;
        }
        
    }

    //count the line when the parsing end success
        int line_count = 0;

    

    //파일을 읽어냄

    file = fopen("test5.txt","r");

    if (file == NULL)
    {
        perror("fail to read file");
        return -1;
    }

    
    
    for (int i = 0; fgets(text_box[i],MAX_COLS,file) != NULL; i++)
    {
        command_line = (char *)malloc(sizeof(char) * strlen(text_box[i]));
        strcpy(command_line,text_box[i]);

                 if(parse(command_line)){
            line_count++;
            free(command_line);
       }
            
    }

    //program counter을 0으로 초기화
    program_counter = 0;
    
        while(program_counter < line_count){

        //program_counter가 범위 외에 위치해 있으면
        if (program_counter >= line_count || program_counter < 0)
            {
                printf("out of line\n");
                exit(-1);
            }
        
       
        command_line = (char *)malloc(sizeof(char) * strlen(text_box[program_counter]));
        strcpy(command_line,text_box[program_counter]);

        printf("%s",command_line);
        
        opcode = strtok(command_line," \n");

        if (strcmp(opcode,"ADD") == 0)
        {
            ADD(command_line,argv[1]);
        }
        else if (strcmp(opcode,"SUB") == 0)
        {
            SUB(command_line,argv[1]);
        }    
        else if (strcmp(opcode,"MUL") == 0)
        {
            MUL(command_line,argv[1]);
        }
        else if (strcmp(opcode,"DIV") == 0)
        {
            DIV(command_line,argv[1]);
        }
        else if (strcmp(opcode,"LW") == 0)
        {
            LW(command_line,argv[1]);
        } 
        else if(strcmp(opcode,"NOP") == 0){
            NOP(command_line,argv[1]);
        }
        else if(strcmp(opcode,"slt") == 0){
            slt(command_line,argv[1]);
        }
        else if(strcmp(opcode,"JMP") == 0){
            JMP(command_line,argv[1]);
        }
        else if(strcmp(opcode,"BNE") == 0){
            beq(command_line,argv[1]);
        }
        else if(strcmp(opcode,"BEQ") == 0){
            beq(command_line,argv[1]);
        }
        free(command_line);
        }

    printf("%d\n",register_num[1]);
    
    return 0;
}*/
