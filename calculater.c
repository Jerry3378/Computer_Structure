#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int MAX_ROWS = 1000;
int MAX_COLS = 100;

//global variable for registers
int v0; //return result register
int t0,t1,t2,t3,t4,t5,t6,t7,t8,t9;  //register for temporary
int s0,s1,s2,s3,s4,s5,s6,s7;    //register for using save



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
    

    file = fopen(argv[1],"r");

    if (file == NULL)
    {
        perror("fail to read file");
        return -1;
    }

    //파일을 읽어냄
    for (int i = 0; fgets(text_box[i],MAX_COLS,file) != NULL; i++)
    {
        interpret(text_box[i]);
        
    }

    //printf("%d",order[1].rs + 1);
    
    
    
    
    return 0;
}