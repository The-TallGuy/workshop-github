#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c;
    printf("%s", "Input: ");
    while(c = fgetc(stdin) != EOF)
    {
        fgetc(stdin);
        printf("You tyed: %c\n", c);
        printf("ASCII Code: %d\n\n", c);
        if (c == '\n')
        {
            return 0;
        }
        printf("Input: ");
    }
    // Idk at this point, but I think it has something to do with the way fgetc and/or stdin hadle \n. 
    // Maybe it's something to do with flushing. 
    // Needs further testing.
    // Try typing a normal character, then, on the second "Input: " prompt, press just enter
    return 0;
}