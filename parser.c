/*
File : parsing.c
this file is a C programming for parsing
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "global_register.h"
#include "parser.h"

/*this function parse the syntax base on .txt files
if any syntax error occur, print error message and exit the program*/
int parse(char *text_line){

    

    int flag = 0;       //파싱에서 성공 여부를 체크할 flag

    char *registers[] = {"zero","v0","t0","t1","t2","t3","t4","t5","t6","t7","t8","t9","s0","s1","s2","s3",
    "s4","s5","s6","s7"};
    
    char *token; //store each token
    
    token = strtok(text_line," ");  //token divided from space

    //condition next token is a register if not, perror and return -1;
    //if instruction fullfills all condition, return success
    if (strcmp(token,"ADD") == 0)
    {
        token = strtok(NULL," ");

        while (token != NULL)
        {
            if (strcmp(token,"zero") == 0)
            {
                perror("systex error");
                exit(-1);
            }
            
            for (int i = 0; i < sizeof(registers)/sizeof(registers[0]); i++)
            {
                if (strcmp(token,registers[i]) == 0)
                {
                    flag = 1;
                    break;
                }else{
                    flag = 0;
                }
                
            }

            if (flag)
            {
                token = (strtok(NULL," \n"));
            }else{
                perror("systex error!");
                exit(-1);
            }
            
            
            
        }

        return 1; //return success!

    }else if (strcmp(token,"SUB") == 0){
                token = strtok(NULL," ");

        while (token != NULL)
        {
            for (int i = 0; i < sizeof(registers)/sizeof(registers[0]); i++)
            {
                if (strcmp(token,registers[i]) == 0)
                {
                    flag = 1;
                    break;
                }else{
                    flag = 0;
                }
                
            }

            if (flag)
            {
                token = (strtok(NULL," \n"));
            }else{
                perror("systex error!");
                exit(-1);
            }
            
            
            
        }

        return 1; //return success!
        
    }else if (strcmp(token,"MUL") == 0)
    {
                token = strtok(NULL," ");

        while (token != NULL)
        {
            for (int i = 0; i < sizeof(registers)/sizeof(registers[0]); i++)
            {
                if (strcmp(token,registers[i]) == 0)
                {
                    flag = 1;
                    break;
                }else{
                    flag = 0;
                }
                
            }

            if (flag)
            {
                token = (strtok(NULL," \n"));
            }else{
                perror("systex error!");
                exit(-1);
            }
                        
        }

        return 1; //return success!

    }else if (strcmp(token,"DIV") == 0)
    {
        token = strtok(NULL," ");

        while (token != NULL)
        {
            for (int i = 0; i < sizeof(registers)/sizeof(registers[0]); i++)
            {
                if (strcmp(token,registers[i]) == 0)
                {
                    flag = 1;
                    break;
                }else{
                    flag = 0;
                }
                
            }

            if (flag)
            {
                token = (strtok(NULL," \n"));
            }else{
                perror("systex error!");
                exit(-1);
            }
                        
        }

        return 1; //return success!

    }else if (strcmp(token,"LW") == 0){
        token = strtok(NULL," ");

        while (token != NULL)
        {
            if (flag == 1)
            {
                //16진수 형태일경우
                if (token[0] == '0' && token[1] == 'x')
                    return 1;
                    
            }
            
            for (int i = 0; i < sizeof(registers)/sizeof(registers[0]); i++)
            {
                if (strcmp(token,registers[i]) == 0)
                {
                    flag = 1;
                    break;
                }else{
                    flag = 0;
                }
                
            }

            if (flag)
            {
                token = (strtok(NULL," \n"));
            }else{
                perror("systex error!");
                exit(-1);
            }
                        
        }

        return 1; //return success!

    }else if (strcmp(token,"J") == 0){
        //jump
        return 1;
    }else if (strcmp(token,"beq") == 0){
        //branch equal go label
        return 1;
    }else if (strcmp(token,"bne") == 0){
        //bne
        return 1;
    }else if  (strcmp(token,"slt") == 0){
        return 1;
    }else{
        perror("syntax error!");
        exit(-1);
    }
    
    
    
}

/* 
test case

int main(int argc,char *argv[]){

    FILE *file = NULL;
    //txt에서 문자들을 읽어 문자를 담을 메시지 박스//
    char text_box[MAX_ROWS][MAX_COLS];
    //instrucion들의 수
    
    

    for (int i = 0; i < MAX_ROWS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            text_box[i][j] = 0;
        }
        
    }

    //count the line when the parsing end success
        int line_count = 0;

    

    file = fopen("input.txt","r");

    if (file == NULL)
    {
        perror("fail to read file");
        return -1;
    }

    //파일을 읽어냄
    for (int i = 0; fgets(text_box[i],MAX_COLS,file) != NULL; i++)
    {
        if(parse(text_box[i])){
            line_count++;
        }
            
    }

    //printf("총 라인 개수 : %d",line_count);   
    
    return 0;
}*/