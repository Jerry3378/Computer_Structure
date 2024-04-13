/*
File : parser.c
this file is a C programming for parsing
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "global_register.h"
#include "parser.h"
#include <errno.h>      //error no header
#include <limits.h>     //LONG_MAX LONG_MIN

/*this function parses the syntax base on .txt files
if any syntax errors occur, print error message and exit the program*/
int parse(char *text_line,int line_number,char *text_box){

    

    int flag = 0;       //파싱에서 성공 여부를 체크할 flag

    const char *registers[] = {"zero","v0","t0","t1","t2","t3","t4","t5","t6","t7","t8","t9","s0","s1","s2","s3",
    "s4","s5","s6","s7"};
    
    char *token; //store each token
    
    token = strtok(text_line," \n");  //token divided from space

    if (token == 0)
    {
        free(text_line);
        return 1;
    }
    

    //condition next token is a register if not, printf and return -1;
    //if instruction fullfills all condition, return success
    if ((strcmp(token,"ADD") == 0) || (strcmp(token,"SUB") == 0) || (strcmp(token,"MUL") == 0) || (strcmp(token,"DIV") == 0)) 
    {
        token = strtok(NULL," \n");

           if (strcmp(token,"zero") == 0)
            {
                printf("line %d: %s\n",line_number,text_box);
                printf("systex error : zero can't be register destination\n");
                printf("%s\n",token);

                free(text_line);
                exit(-1);
            }

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

                printf("line %d: %s\n",line_number,text_box);
                printf("systex error : invalid register\n");
                printf("%s\n",token);
                
                free(text_line);
                exit(-1);
            }
            
            
            
        }

        free(text_line);
        return 1; //return success!

    }
    else if (strcmp(token,"LW") == 0){

        //error_code
        char *endptr =NULL;
        //hex_value
        int value;

        token = strtok(NULL," ");

        while (token != NULL)
        {
            if (flag == 1)
            {
                //16진수 형태일경우
                value = strtol(token, &endptr, 16);

                 // 변환 실패 및 오류 처리
                if ((errno == ERANGE && (value == LONG_MAX || value == LONG_MIN))
                    || (errno != 0 && value == 0)) {
                    printf("line %d: %s\n",line_number,text_box);
                    
                    printf("Conversion failed\n");
                    printf("%s\n",token);

                    free(text_line);
                    exit(-1);
                }

                // 변환 후에 남은 문자가 있는지 검사
                if (endptr == token || *endptr != '\0') {
                    printf("line %d: %s\n",line_number,text_box);
                    printf("Not a valid hexadecimal number\n");
                    printf("%s\n",token);

                    free(text_line);
                    exit(-1);
                    }

                    free(text_line);
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
                printf("line %d: %s\n",line_number,text_box);
                printf("systex error : invalid register\n");
                printf("%s\n",token);

                free(text_line);
                exit(-1);
            }
                        
        
    }
        free(text_line);
        return 1; //return success!
    

    }else if (strcmp(token,"JMP") == 0){

        token = strtok(NULL," \n");
        int value;
        char *endptr;

        value = strtol(token, &endptr, 16);

         // 변환 실패 및 오류 처리
        if ((errno == ERANGE && (value == LONG_MAX || value == LONG_MIN))
            || (errno != 0 && value == 0)) {

                printf("line %d: %s\n",line_number,text_box);                    
                printf("Conversion failed\n");
                printf("%s\n",token);
            
            free(text_line);
            exit(-1);
        }

        // 변환 후에 남은 문자가 있는지 검사
        if (endptr == token || *endptr != '\0') {
            printf("line %d: %s\n",line_number,text_box); 
            printf("Not a valid hexadecimal number\n");
            printf("%s\n",token);

            free(text_line);
            exit(-1);
            }
        free(text_line);
        return 1;

    }else if (strcmp(token,"BEQ") == 0){
        int value;

        //count the register encounter times
        int reg_count = 0;
        char *endptr;

        token = strtok(NULL," \n");

        while (token != NULL)
        {

            if(reg_count == 2){
                //16진수 형태일경우
                value = strtol(token, &endptr, 16);

                 // 변환 실패 및 오류 처리
                if ((errno == ERANGE && (value == LONG_MAX || value == LONG_MIN))
                    || (errno != 0 && value == 0)) {
                    printf("line %d: %s\n",line_number,text_box);
                    printf("Conversion failed\n");
                    printf("%s\n",token);
                    
                    free(text_line);
                    exit(-1);
                }

                // 변환 후에 남은 문자가 있는지 검사
                if (endptr == token || *endptr != '\0') {
                    printf("line %d: %s\n",line_number,text_box);
                    printf("Not a valid hexadecimal number\n");
                    printf("%s\n",token);
                    
                    free(text_line);
                    exit(-1);
                    }

                    free(text_line);
                    return 1;
            }

            for (int i = 0; i < sizeof(registers)/sizeof(registers[0]); i++)
            {
                if (strcmp(token,registers[i]) == 0)
                {
                    flag =1;
                    reg_count++;
                    break;
                }else{
                    flag = 0;
                }
                
            }

            if (flag)
            {
                token = (strtok(NULL," \n"));
            }else{
                printf("line %d: %s\n",line_number,text_box);
                printf("systex error : invalid register\n");
                printf("%s\n",token);
                
                free(text_line);
                exit(-1);
            }
                        
        }

        free(text_line);
        return 1; //return success!

    }else if (strcmp(token,"BNE") == 0){
        
        int value;
         //count the register encounter times
        int reg_count = 0;

        char *endptr;
        
        token = strtok(NULL," \n");

        while (token != NULL)
        {

            if(reg_count == 2){
                //16진수 형태일경우
                value = strtol(token, &endptr, 16);

                 // 변환 실패 및 오류 처리
                if ((errno == ERANGE && (value == LONG_MAX || value == LONG_MIN))
                    || (errno != 0 && value == 0)) {
                    
                    printf("line %d: %s\n",line_number,text_box);
                    printf("Conversion failed: ");
                    printf("%s\n",token);
                    
                    free(text_line);
                    exit(-1);
                }

                // 변환 후에 남은 문자가 있는지 검사
                if (endptr == token || *endptr != '\0') {
                    printf("line %d: %s\n",line_number,text_box);
                    printf("Not a valid hexadecimal number\n");
                    printf("%s\n",token);
                    
                    free(text_line);
                    exit(-1);
                    }

                    free(text_line);
                    return 1;
            }

            for (int i = 0; i < sizeof(registers)/sizeof(registers[0]); i++)
            {
                if (strcmp(token,registers[i]) == 0)
                {
                    flag = 1;
                    reg_count++;
                    break;
                }else{
                    flag = 0;
                }
                
            }

            if (flag)
            {
                token = (strtok(NULL," \n"));
            }else{
                printf("line %d: %s\n",line_number,text_box);
                printf("systex error : invalid register\n");
                printf("%s\n",token);

                free(text_line);
                exit(-1);
            }
                        
        }

        free(text_line);
        return 1; //return success!

    }else if  (strcmp(token,"SLT") == 0){
        
        token = strtok(NULL," \n");

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
                printf("line %d: %s\n",line_number,text_box);
                printf("systex error : invalid register\n");
                printf("%s\n",token);

                free(text_line);
                exit(-1);
            }
                        
        }

        //free text_line
        free(text_line);
        return 1; //return success!
        
    }else if  (strcmp(token,"NOP") == 0){
        return 1;
    }else{
        printf("line %d: %s\n",line_number,text_box);
        printf("systex error : invalid opcode\n");
        printf("%s\n",token);

        free(text_line);
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
        printf("fail to read file");
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
