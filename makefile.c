#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *randomWord();

int main(void) {
    char *mot = randomWord();
    if (mot) {
        printf("Mot choisi : ");
        for (int i = 0; mot[i]; i++) {
            printf("_ ");
        }
        printf("\n");
        free(mot);
    }
};

void menu(){
    printf("Bienvenue dans le PENDU");
    printf("1 : Jouer");
    printf("2 : Voir votre Score");
    printf("3 : Quiter le jeu");
};