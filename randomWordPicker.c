// Sélecteur de mot aléatoire pour le jeu du pendu
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *randomWord() {
    srand(time(NULL));

    FILE *file = fopen("mots.txt", "r");
    if (!file) {
        perror("Erreur ouverture mots.txt");
        return NULL;
    }

    char **words = NULL;
    int numWords = 0;
    char line[256];

    while (fgets(line, sizeof(line), file)) {
        // Supprimer le '\n' en fin de ligne
        int len = 0;
        while (line[len] && line[len] != '\n') len++;
        line[len] = '\0';

        words = realloc(words, (numWords + 1) * sizeof(char *));
        words[numWords] = malloc(len + 1);
        for (int i = 0; i <= len; i++) words[numWords][i] = line[i];
        numWords++;
    }
    fclose(file);

    if (numWords == 0) return NULL;

    char *chosen = words[rand() % numWords];

    // Libérer les autres entrées
    for (int i = 0; i < numWords; i++) {
        if (words[i] != chosen) free(words[i]);
    }
    free(words);

    return chosen;
}