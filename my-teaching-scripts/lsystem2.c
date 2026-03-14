#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE* f = fopen("test.lsys", "r");
    char* axiom = malloc(sizeof(char));
    char** p = malloc(256 * sizeof(char*));
    int poz=0, nrrules;

    *axiom = fgetc(f);
    while(*(axiom+poz) != '\n')
    {
        poz++;
        axiom = realloc(axiom, poz+1);
        *(axiom+poz) = fgetc(f);
    }
    *(axiom+poz) = '\0';
    // Caracterul *(axiom+poz) va fi '\n', deci ignoram
    // poz reprezinta NUMARUL de caractere valide (care nu sunt '\n')
    printf("Axioma este:\t%s\n", axiom);

    fscanf(f, "%d", &nrrules);
    // printf("%d\n", nrrules);
    fgetc(f);   // Escape the trailing '\n'
    while(nrrules--)
    {
        int c = fgetc(f);
        fgetc(f);   // Get rid of the space

        char *rule = malloc(sizeof(char));
        // Scaneaza tu Costine acuma toata regula DINAMIC...
        *rule = fgetc(f);
        int templen=0;
        while( (*(rule+templen) != '\n') && (*(rule+templen) != EOF) )
        {
            templen++;
            rule = realloc(rule, templen+1);
            *(rule+templen) = fgetc(f);
            // puts("");
        }
        *(rule+templen) = '\0';
        *(p+c) = malloc(templen+1);
        strcpy(*(p+c), rule);
        // nrrules--;
        printf("\n%c -> %s\n", c, *(p+c));
    }

    int n;
    printf("De cate ori sa derivam axioma: ");
    scanf("%d", &n);
    while(n--)
    {
        puts("---");
        // printf("%d\n", n);
        char *temp = malloc(sizeof(char));
        *temp = '\0';
        for(int i=0; i<strlen(axiom); i++)
        {
            int len = strlen(*(p+(int)axiom[i]));
            // printf("Caractere regula: %d\n", len);
            temp = realloc(temp, strlen(temp) + 1 + len*sizeof(char));
            strcpy( temp+strlen(temp), *(p+(int)(axiom[i])) );
            printf("%c -> %s\n", axiom[i], *(p+(int)(axiom[i])));
        }
        strcpy(axiom, temp);
    }
    puts("---");
    printf("Rezultatul final: %s\n", axiom);
    return 0;
}