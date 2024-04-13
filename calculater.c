
//This file is only used for debugging the integrated file.

//#include "opcode_processor.c" // File that functions that process commands are implemented.
//#include "parser.c" // A file that implemented to analyze commands.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "global_register.h"
#include "opcode_processor.h"
#include "parser.h"


int main(int argc,char *argv[]){

    char *file_name;
    
    char *command_line = NULL;
    FILE *file = NULL;
    // Array to store the string for each line from the text file
    char text_box[MAX_ROWS][MAX_COLS];
    char *opcode;
    

    for (int i = 0; i < MAX_ROWS; i++)
    {
        for (int j = 0; j < MAX_COLS; j++)
        {
            text_box[i][j] = 0;
        }
        
    }

    //initialize the line_count for counting the line
        int line_count = 0;

    //file_name
    for (int i = 0; i < strlen(argv[0]); i++)
    {
        if (argv[0][i] == '/')
        {
            file_name = argv[0]+(i+1);
            break;
        }
        
    }


    //file open

    file = fopen(argv[1],"r");

    if (file == NULL)
    {
        perror("fail to read file");
        return -1;
    }

    
    // Read each line from the file, store it in a text box and perform parsing
    for (int i = 0; fgets(text_box[i],MAX_COLS,file) != NULL; i++)
    {
        command_line = (char *)malloc(sizeof(char) * strlen(text_box[i]));
        strcpy(command_line,text_box[i]);

        if(parse(command_line,line_count+1,text_box[i])){
            line_count++;
       }
            
    }

        //initialize the program counter
        program_counter = 0;

        //execute the program
        while(program_counter < line_count){

        if (text_box[program_counter][0] == '\n')
            {
                // Skip if line is blank or comment
                program_counter++;
                continue;
            }
            
    
        
        // Obtain and process the instruction pointed to by the current program counter
        command_line = (char *)malloc(sizeof(char) * strlen(text_box[program_counter]));
        strcpy(command_line,text_box[program_counter]);

        printf("%s",command_line);
        
        opcode = strtok(command_line," \n");

        if (strcmp(opcode,"ADD") == 0)
        {
            ADD(command_line,file_name);
        }
        else if (strcmp(opcode,"SUB") == 0)
        {
            SUB(command_line,file_name);
        }    
        else if (strcmp(opcode,"MUL") == 0)
        {
            MUL(command_line,file_name);
        }
        else if (strcmp(opcode,"DIV") == 0)
        {
            DIV(command_line,file_name);
        }
        else if (strcmp(opcode,"LW") == 0)
        {
            LW(command_line,file_name);
        } 
        else if(strcmp(opcode,"NOP") == 0){
            NOP(command_line,file_name);
        }
        else if(strcmp(opcode,"SLT") == 0){
            slt(command_line,file_name);
        }
        else if(strcmp(opcode,"JMP") == 0){
            JMP(command_line,file_name,line_count-1);
        }
        else if(strcmp(opcode,"BNE") == 0){
            bne(command_line,file_name,line_count-1);
        }
        else if(strcmp(opcode,"BEQ") == 0){
            beq(command_line,file_name,line_count-1);
        }
        free(command_line);
        }

    printf("%d\n",register_num[1]);
    
    return 0;
}
