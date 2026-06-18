#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *randomWord();

int game(int score){
    char *mot = randomWord();
    if (!mot) return 0;
    
    int len = strlen(mot);
    char *revealed = malloc(len + 1);
    char guessed[26] = {0};  // Track guessed letters
    int attempts = 7;
    int correctGuesses = 0;
    
    // Initialize revealed with underscores
    for (int i = 0; i < len; i++) {
        revealed[i] = '_';
    }
    revealed[len] = '\0';
    
    printf("\n=== BIENVENUE AU PENDU ===\n");
    printf("Mot à deviner : %s\n", mot);
    printf("Vous avez %d tentatives\n\n", attempts);
    
    while (attempts > 0 && correctGuesses < len) {
        // Display current state
        printf("Mot : ");
        for (int i = 0; i < len; i++) {
            printf("%c ", revealed[i]);
        }
        printf("\nTentatives restantes : %d\n", attempts);
        printf("Lettres essayées : %s\n", guessed);
        printf("Devinez une lettre : ");
        
        char guess;
        scanf(" %c", &guess);  // space before %c to skip whitespace
        
        // Check if digit
        if (isdigit(guess)) {
            printf("Les chiffres ne sont pas autorisés! Entrez une lettre.\n\n");
            continue;
        }
        
        // Check if already guessed
        int alreadyGuessed = 0;
        for (int i = 0; i < 26; i++) {
            if (guessed[i] == guess) {
                alreadyGuessed = 1;
                break;
            }
        }
        
        if (alreadyGuessed) {
            printf("Vous avez déjà essayé cette lettre!\n\n");
            continue;
        }
        
        // Add to guessed letters
        for (int i = 0; i < 26; i++) {
            if (guessed[i] == 0) {
                guessed[i] = guess;
                break;
            }
        }
        
        // Check if letter is in word
        int found = 0;
        for (int i = 0; i < len; i++) {
            if (mot[i] == guess) {
                revealed[i] = guess;
                found = 1;
                correctGuesses++;
            }
        }
        
        if (!found) {
            attempts--;
            printf("Lettre non trouvée!\n\n");
        } else {
            printf("Bonne lettre!\n\n");
        }
    }
    
    // End game
    printf("\n=== FIN DE LA PARTIE ===\n");
    if (correctGuesses == len) {
        printf("Vous avez gagné! Le mot était : %s\n", mot);
        score += (attempts * 10);
        printf("Points gagnés : %d\n", attempts * 10);
    } else {
        printf("Vous avez perdu! Le mot était : %s\n", mot);
    }
    
    free(mot);
    free(revealed);
    
    printf("\nVotre score actuel : %d\n\n", score);
    return score;
}

int exitGame(int score){
    printf("Votre score de cette partie était de : %d points! \n ", score);
    return 1;
}

void menu(int score){
    int choix;
    int continuer = 1;
    
    while (continuer) {
        printf("Bienvenue dans le PENDU\n");
        printf("1 : Jouer\n");
        printf("2 : Voir votre Score\n");
        printf("3 : Quiter le jeu\n");
        printf("Entrez votre choix : ");
        
        if (scanf("%d", &choix) != 1) {
            // Clear input buffzer if scanf fails
            while (getchar() != '\n');
            printf("Veuillez rentrer un nombre valide (1, 2 ou 3)\n\n");
            continue;
        }
        
        switch(choix){
            case 1:
                score = game(score);
                break;
            case 2:
                printf("Votre score est de %d\n\n", score);
                break;
            case 3: 
                exitGame(score);
                continuer = 0;
                break;
            default:
                printf("Veuillez rentrer un nombre en guise de choix (1, 2 ou 3)\n\n");
                break;
        }
    }
};

int main(void) {
    int score = 0;
    menu(score);
};