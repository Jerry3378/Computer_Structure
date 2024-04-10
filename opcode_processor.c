/*File Name: opcode_processor.c
Description: This file is responsible for processing each command. 
Depending on the opcode of each instruction, it performs the corresponding operation and
, if necessary, manipulates registers or memory.*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "parser.c"
#include "opcode_processor.h"

int register_num[20] = {0};

//this variables is for checking the text lines
const char *registers[] = {"zero","v0","t0","t1","t2","t3","t4","t5","t6","t7","t8","t9","s0","s1","s2","s3",
    "s4","s5","s6","s7"};

//this funcion helps to search register name to register index
int get_register_num(char *token){
    for (int i = 0; i < sizeof(registers)/sizeof(registers[0]); i++){
            if (strcmp(token,registers[i]) == 0)
                return i;
    }

    return -1;
}    


void ADD(char *text_line, char *file_name){
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

void SUB(char *text_line,char *file_name){
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

void MUL(char *text_line,char *file_name){
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

void DIV(char *text_line,char *file_name){
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

    *rd = *rs / *rt;
    printf("%s> Divided %s(%d) to %s(%d) and changed %s to %d\n",file_name,token_message[1],*rs,token_message[2],*rt,token_message[0],*rd);

}

void LW(char *text_line,char *file_name){
   int index_num = 0;
    char *token_message;

    char *token = strtok(NULL," \n");
    index_num = get_register_num(token);
    int *rd = register_num+index_num;
    token_message = token;
    
    token = strtok(NULL," ");
    int data = strtol(token,NULL,16);

    *rd = data;
    printf("%s> Loaded %d to %s\n",file_name,*rd,token_message);
}   

//test case
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

    

    file = fopen("test4.txt","r");

    if (file == NULL)
    {
        perror("fail to read file");
        return -1;
    }

    //파일을 읽어냄
    
    for (int i = 0; fgets(text_box[i],MAX_COLS,file) != NULL; i++)
    {
        command_line = (char *)malloc(sizeof(char) * strlen(text_box[i]));
        strcpy(command_line,text_box[i]);

        if(parse(command_line)){
            line_count++;
            free(command_line);
       }
            
    }

    
    
    for (int i = 0; i < line_count; i++)
    {
       
        command_line = (char *)malloc(sizeof(char) * strlen(text_box[i]));
        strcpy(command_line,text_box[i]);

        printf("%s",command_line);
        
        opcode = strtok(command_line," \n");

        if (strcmp(opcode,"ADD") == 0)
        {
            ADD(text_box[i],argv[1]);
        }
        else if (strcmp(opcode,"SUB") == 0)
        {
            SUB(text_box[i],argv[1]);
        }    
        else if (strcmp(opcode,"MUL") == 0)
        {
            MUL(text_box[i],argv[1]);
        }
        else if (strcmp(opcode,"DIV") == 0)
        {
            DIV(text_box[i],argv[1]);
        }
        else if (strcmp(opcode,"LW") == 0)
        {
            LW(command_line,argv[1]);
        }
        
        free(command_line);
    }

    printf("%d\n",register_num[1]);
    
    return 0;
}