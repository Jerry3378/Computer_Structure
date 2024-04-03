#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int MAX_ROWS = 1000;
int MAX_COLS = 100;

//instruction(명령어)을 구조를 구현할 구조체
typedef struct instruction{
    char *OPcode;
    char *rd;
    char *rs;
    char *rt;
}instruction; 

int main(int argc,char *argv[]){

    FILE *file = NULL;
    //txt에서 문자들을 읽어 문자를 담을 메시지 박스//
    char text_box[MAX_ROWS][MAX_COLS];
    //txt_box로 부터 받아들인 instruction들을 token별로 모을 line
    char *line;
    //instrucion들의 수
    instruction order[MAX_ROWS];
    

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
        int count = 0;
        printf("분리하기 전 : %s\n",text_box[i]);
        line = strtok(text_box[i], " ");

        while (line != NULL)
        {
            if (count == 0)
            {
                order[i].OPcode = line;
            }
            else if (count == 1)
            {
                order[i].rd = line;
            }
            else if (count == 2)
            {
                order[i].rs = line;
            }
            else if (count == 3)
            {
                order[i].rt = line;
            }

            line = strtok(NULL, " ");
            count++;

        }
        if (order[i].OPcode != NULL)
        {
            printf("분리 한 후\nOpcde : %s, rd : %s, rs : %s, rt : %s\n",order[i].OPcode,order[i].rd,order[i].rs,order[i].rt);
        }
    }

    printf("%d",order[1].rs + 1);
    
    
    
    
    return 0;
}