#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int game(char mot){
    
}

void menu(int score){
    int choix;
    printf("Bienvenue dans le PENDU\n");
    printf("1 : Jouer\n");
    printf("2 : Voir votre Score\n");
    printf("3 : Quiter le jeu\n");
    printf("Entrez votre choix : ");
    scanf("%d", &choix);
    switch(choix){
        case 1:
            //gameCaller
            break;
        case 2:
            printf("Votre score est de %d", score);
            break;
        case 3: 
            printf("Votre score de cette partie était de : %d points!", score);
            return 1;
        default:
            printf("Veuillez rentrer un nombre en guise de choix");
            menu(score);
            break;
    }
};

int main(void) {
    int score = 0;
    menu(score);

};