// Timothy Lee
// leetg1

#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include "hw1.h"
#include <ctype.h>

// You may define any helper functions you want. Place them in helpers.c/.h
int char_check(char c);
int num_check(char c);
int space_check(char c);


// main program
int main (int argc, char *argv[])
{
    int symbol_count = 0;
    int number_count;
    char input;
    int count = 0;
    int start = 0;
    int lead = 0;
    if((input = fgetc(stdin)) == EOF)
    {
        return 1;
    }
    if(argc >= 2)
    {
        //Symbol Check -S
        if((strcmp(argv[1], "-S")) == 0)
        {
            if(argc == 3)
            {
                if((strcmp(argv[2], "-O")) == 0)
                {
                    do
                    {
                        int result =char_check(input);
                        if(result == 1)
                        {
                            count ++;
                        }
                        else if (result == 2)
                        {
                            printf("%d\n",count);
                            return(1);
                        }
                        else
                        {
                            fprintf(stderr,"%c", input);
                        }
                        
                    }while((input = fgetc(stdin)) != EOF);
                    printf("%d\n",count);
                    return(0);
                }
                else
                {
                    return(1);
                }
            }
            else if(argc == 2)
            {
                do
                {
                    int result =char_check(input);
                    if(result == 1)
                    {
                        count ++;
                    }
                    else if (result == 2)
                    {
                        return(1);
                    }
                    
                }while((input = fgetc(stdin)) != EOF);
                printf("%d\n",count);
                return(0);
            }
            else
            {
                return(1);
            }
        }
        //num_check -N
        else if((strcmp(argv[1], "-N")) == 0)
        {
            if(argc == 3)
            {
                if((strcmp(argv[2], "-O")) == 0)
                {
                    do
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
                    }while((input = fgetc(stdin)) != EOF);
                    printf("%d\n",count);
                    return(0);
                }
                else
                {
                    return(1);
                }
            }
            else if(argc == 2)
            {
                do
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
                }while((input = fgetc(stdin)) != EOF);
                printf("%d\n",count);
                return(0);
            }
            else
            {
                return (1);
            }
        }
        //leading space check -L
        else if(strcmp(argv[1], "-L") == 0)
        {
            if(argc == 3)
            {
                if((strcmp(argv[2], "-O")) == 0)
                {
                    do
                    {
                        int result = space_check(input);
                        if(result == 1)
                        {
                            if (start == 0)
                            {
                                lead ++;
                            }
                            else
                            {
                                fprintf(stderr,"%c",input);
                            }
                        }
                        else
                        {
                            start ++;
                            if(input == '\n')
                            {
                                if(lead > 0)
                                {
                                    count ++;
                                }
                                lead = 0;
                                start = 0;
                            }
                            fprintf(stderr,"%c",input);
                        }
                    }while((input = fgetc(stdin)) != EOF);
                    printf("%d\n",count);
                    return(0);
                }
                else
                {
                    return(1);
                }
            }
            else if(argc == 2)
            {
                do
                {
                    int result = space_check(input);
                    start ++;
                    if(result == 1)
                    {
                        if (start == 1)
                        {
                            lead ++;
                        }
                    }
                    else
                    {
                        if(input == '\n')
                        {
                            if(lead == 1)
                            {
                                count ++;
                            }
                            lead = 0;
                            start = 0;
                        }
                    }
                }while((input = fgetc(stdin)) != EOF);
                printf("%d\n",count);
                return(0);
            }
            else
            {
                return(1);
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
                if(argc <= 4)
                {
                    if(argc == 4 && (strcmp(argv[3], "-O")) != 0)
                    {
                        return(1);
                    }
                    else
                    {
                        int num = atoi(argv[2]);
                        int i;
                        do
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
                        }while((input = fgetc(stdin)) != EOF);
                        printf("%d\n",count);
                        return(0);
                    }
                }
                else
                {
                    return(1);
                }
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
                if(argc <= 4)
                {
                    if(argc == 4 && (strcmp(argv[3], "-O")) != 0)
                    {
                        return(1);
                    }
                    else
                    {
                        int num = atoi(argv[2]);
                        int space_count = 0;
                        
                        do
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
                            
                        }while((input = fgetc(stdin)) != EOF);
                        printf("%d\n",count);
                        return(0);
                    }
                }
                else
                {
                    return(1);
                }
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

