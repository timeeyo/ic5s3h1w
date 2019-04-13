// Timothy Lee
// leetg1

#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "hw1.h"
#include <ctype.h>

// You may define any helper functions you want. Place them in helpers.c/.h


// main program
int main (int argc, char *argv[])
{
    int symbol_count = 0;
    int number_count;
    char input;
    int count = 0;
    int start = 0;
    printf("%d\n", argc);
    if(argc >= 2)
    {
        //Symbol Check -S
        if((strcmp(argv[1], "-S")) == 0)
        {
            if(argc > 2)
            {
                if((strcmp(argv[2], "-O")) == 0)
                {
                    while((input = fgetc(stdin)) != EOF)
                    {
                        int result =char_check(input);
                        if(result == 1)
                        {
                            count ++;
                        }
                        else
                        {
                            fprintf(stderr,"%c", input);
                        }
                    }
                    printf("%d\n",count);
                    return(0);
                }
                else
                {
                    return(1);
                }
            }
            else
            {
                while((input = fgetc(stdin)) != EOF)
                {
                    count += char_check(input);
                }
                printf("%d\n",count);
                return(0);
            }
        }
        //num_check -N
        else if((strcmp(argv[1], "-N")) == 0)
        {
            if(argc > 2)
            {
                if((strcmp(argv[2], "-O")) == 0)
                {
                    while((input = fgetc(stdin)) != EOF)
                    {
                        int result = num_check(input);
                        if(result == 1 && start == 0)
                        {
                            start = 1;
                        }
                        else if(result == 0 && start == 1)
                        {
                            fprintf(stderr,"%c",input);
                            count ++;
                            start = 0;
                        }
                        else if(!(result == 1 && start == 1))
                        {
                            fprintf(stderr,"%c",input);
                        }
                    }
                    printf("%d\n",count);
                    return(0);
                }
                else
                {
                    return(1);
                }
            }
            else
            {
                while((input = fgetc(stdin)) != EOF)
                {
                    int result = num_check(input);
                    if(result == 1 && start == 0)
                    {
                        start = 1;
                    }
                    else if(result == 0 && start == 1)
                    {
                        count ++;
                        start = 0;
                    }
                }
                printf("%d\n",count);
                return(0);
            }
        }
        //leading space check -L
        else if(strcmp(argv[1], "-L") == 0)
        {
            if(argc > 2)
            {
                if((strcmp(argv[2], "-O")) == 0)
                {
                    while((input = fgetc(stdin)) != EOF)
                    {
                        int result = space_check(input);
                        if(start == 0 && result == 1)
                        {
                            count ++;
                        }
                        else if(start == 0 && result == 0)
                        {
                            fprintf(stderr,"%c",input);
                            start = 1;
                        }
                        else if(start == 1)
                        {
                            fprintf(stderr,"%c",input);
                        }
                        if(input == '\n')
                        {
                            start =0;
                        }
                    }
                    printf("%d\n",count);
                    return(0);
                }
                else
                {
                    return(1);
                }
            }
            else
            {
                while((input = fgetc(stdin)) != EOF)
                {
                    int result = space_check(input);
                    if(start == 0 && result == 1)
                    {
                        count ++;
                        start = 1;
                    }
                    if(input == '\n')
                    {
                        start =0;
                    }
                }
                printf("%d\n",count);
                return(0);
            }
        }
        else if(strcmp(argv[1], "-E") == 0)
        {
            if(!num_check(argv[2][0]))
            {
                return(1);
            }
            else
            {
                int num = atoi(argv[2]);
                int i;
                while((input = fgetc(stdin)) != EOF)
                {
                    if(input == '\t')
                    {
                        count ++;
                        for(i = 0; i < num; i++)
                        {
                            fprintf(stderr,"%c",' ');
                        }
                    }
                    else
                    {
                        fprintf(stderr,"%c",input);
                    }
                }
                printf("%d\n",count);
                return(0);
            }
        }
        else if(strcmp(argv[1], "-C") == 0)
        {
            if(!num_check(argv[2][0]))
            {
                return(1);
            }
            else
            {
                int num = atoi(argv[2]);
                int space_count = 0;
                
                while((input = fgetc(stdin)) != EOF)
                {
                    
                    if(start == 0 && input == ' ')
                    {
                        start = 1;
                        space_count ++;
                        if(num == 1)
                        {
                            fprintf(stderr,"%s","\t");
                            space_count = 0;
                            start = 0;
                        }
                    }
                    else if(start == 1 && input != ' ')
                    {
                        start = 0;
                        int i;
                        for(i = 0; i < space_count; i++)
                        {
                            fprintf(stderr,"%s"," ");
                        }
                        fprintf(stderr,"%c",input);
                        space_count = 0;
                        
                    }
                    else if(start == 1 && input == ' ')
                    {
                        space_count ++;
                        if(space_count == num)
                        {
                            count ++;
                            fprintf(stderr,"%s","\t");
                            space_count = 0;
                            start = 0;
                        }
                    }
                    else if(start == 0 && input != ' ')
                    {
                        fprintf(stderr,"%c",input);
                    }
                    
                }
                printf("%d\n",count);
                return(0);
            }
        }
        else
        {
            return(1);
        }
    }
    else
    {
        return(1);
    }
}

int char_check(char c)
{
    if((c >= 33 && c <= 126) && !(c >= 97 && c <= 122)
       && !(c >= 65 && c <=90) && !(c >= 48 && c <= 57))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int num_check(char c)
{
    if(c >= 48 && c <= 57)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int space_check(char c)
{
    
    if(c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f')
    {
        return 1;
    }
    else
    {
    return 0;
    }
}
