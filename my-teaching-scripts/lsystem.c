#include <stdio.h>
#include <stdlib.h>

char* freadstd(FILE* stream)
{
    int ok = 1, len = 0, read;
    char *str = malloc(sizeof(char));
    // while((read = fgetc(stream)) != EOF)
    {
        if(read == ' ' || read == '\n')
        {
            len++;
            str = realloc(str, len);
            *(str+len-1) = '\0'; 
            return str; 
            // break;
        }
        len++;
        str = realloc(str, len*sizeof(char));
        *(str+len-1) = read; 
    }
}

int main()
{
    printf("COMMANDS:\n");
    char *command = freadstd(stdin);
    printf("Your command is: %s\n", command);
    char *argument = freadstd(stdin);
    printf("With the argument: %s\n", argument);
    return 0;
}