#include <stdio.h>
#include <stdlib.h>

// Funcție care citește dinamic până la un delimitator (spațiu sau \n)
char* citeste_dinamic(FILE* stream) 
{
    int capacitate = 10; // Pornim cu puțin
    int lungime = 0;
    char* str = malloc(capacitate * sizeof(char)); // Alocare inițială
    
    if (!str) return NULL; // Verificare alocare

    int c;
    // Citim caracter cu caracter
    while ((c = fgetc(stream)) != EOF) {
        // Cazul 1: Am găsit separatorul de comandă (spațiu) sau final de linie
        if (c == ' ' || c == '\n') {
            // Dacă am citit ceva, ne oprim. Dacă e primul caracter (ex: spații multiple), continuăm sau ne oprim?
            // Pentru simplitate, ne oprim aici.
            // Putem pune caracterul înapoi în stream dacă e \n și vrem să-l procesăm altundeva, 
            // dar aici presupunem că vrem doar să extragem cuvântul.
            if (c == '\n') ungetc(c, stream); // Lăsăm \n pentru următoarea citire dacă e cazul
            break;
        }

        // Cazul 2: Mai avem loc?
        if (lungime + 1 >= capacitate) {
            capacitate *= 2; // Dublăm capacitatea (Geometric Growth)
            char* temp = realloc(str, capacitate);
            if (!temp) {
                free(str);
                return NULL; // Eșec la realocare
            }
            str = temp;
        }

        // Cazul 3: Adăugăm caracterul
        str[lungime++] = (char)c;
    }

    str[lungime] = '\0'; // Null-terminator obligatoriu
    return str;
}

int main() {
    printf("Scrie o comanda (ex: LOAD imagine.ppm): ");
    
    // 1. Citim Comanda (se oprește la spațiu)
    char* comanda = citeste_dinamic(stdin);
    
    // Consumăm spațiul rămas, dacă există
    int c = fgetc(stdin);
    if (c != ' ' && c != '\n') ungetc(c, stdin); 

    // 2. Citim Argumentul (restul liniei)
    // Aici logica ar fi ușor diferită: citim până la \n, nu până la spațiu
    // Dar pentru exemplu refolosim funcția sau scriem una dedicată "citeste_linie"
    char* argument = citeste_dinamic(stdin); 

    printf("Comanda: '%s'\n", comanda);
    printf("Argument: '%s'\n", argument);

    // ELIBERARE MEMORIE (OBLIGATORIU)
    free(comanda);
    free(argument);

    return 0;
}