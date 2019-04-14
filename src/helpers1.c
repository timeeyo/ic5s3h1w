// Define all helper functions for hw1 in this file
int char_check(char c)
{
    
    if((c >= 33 && c <= 126) && !(c >= 97 && c <= 122)
       && !(c >= 65 && c <=90) && !(c >= 48 && c <= 57))
    {
        return 1;
    }
    else if(c < 0 || c > 127)
    {
        return 2;
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
