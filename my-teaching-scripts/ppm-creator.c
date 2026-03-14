#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int h, w;
    FILE *fp;
    fp = fopen("test-ppm.ppm", "wb");
    if(fp == NULL)
    {
        puts("Fisierul nu poate fi deschis!\n");
        exit(1);
    }

    puts("\nInsereaza dimensiunile iamaginii (linii coloane): ");
    scanf("%d", &w); scanf("%d", &h);

    // Acum trepuie sa scriu latimea, APOI lungimea in ppm
    // IMPORTANT: Trebuie sa fie vazute ca numere in ASCII!
    
    fprintf(fp, "P6\n%d %d\n255\n", w, h);

    srand(time(NULL));
    for(int i=h-1; i>=0; i--)
    {
        for(int j=0; j<w; j++)
        {
            unsigned char pixel[3];
            for(int k=0; k<3; k++) 
                pixel[k] = rand() % 256;
            fwrite(pixel, sizeof(unsigned char), 3, fp);
        }
    }
    printf("PPM Noise Image succesfully generated! ✅\n\n");
    fclose(fp);
    return 0;
}