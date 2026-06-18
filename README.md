# Jeu du Pendu

Implémentation en C du jeu classique du Pendu, jouable dans le terminal.

## Fonctionnement

Le jeu tire un mot aléatoire depuis `mots.txt` et demande au joueur de le deviner lettre par lettre. Le joueur dispose de **7 tentatives** par partie. Chaque lettre correctement trouvée est révélée dans le mot ; une lettre absente coûte une tentative.

**Système de score :** à chaque victoire, le joueur gagne `tentatives_restantes × 10` points. Le score est cumulé sur toute la session.

## Structure du projet

```
.
├── main.c               # Logique du jeu et menu principal
├── randomWordPicker.c   # Sélection aléatoire d'un mot depuis mots.txt
├── mots.txt             # Liste des 26 mots possibles (un par ligne)
└── Makefile             # Règles de compilation
```

## Compilation et lancement

**Prérequis :** `gcc` et `make`

```bash
# Compiler
make

# Lancer
make run

# Ou directement
./pendu

# Nettoyer les fichiers compilés
make clean
```

## Utilisation

Le menu propose trois options :

```
1 : Jouer
2 : Voir votre score
3 : Quitter le jeu
```

Pendant une partie :
- Entrez une lettre à chaque tour
- Les chiffres sont refusés
- Les lettres déjà proposées sont signalées sans pénalité
- Le mot est affiché avec `_` pour les lettres non encore trouvées

## Ajouter des mots

Éditez `mots.txt` en ajoutant un mot par ligne. Le fichier doit se trouver dans le répertoire depuis lequel le binaire est exécuté.


# Credits

- **developppeurs** : [Vovodymyr Karaush, Cyril Mazauric]
- **Lien du repo** : https://github.com/CyrilMaz/Langage_compliles_projet.git 