# So Long — Sandro's adventures

> Un petit jeu d'aventure 2D sur grille, réalisé en C dans le cadre du cursus de 42.

Le joueur explore une carte, récupère tous les objets et rejoint la sortie. Le jeu utilise la **MiniLibX Linux** pour créer la fenêtre, afficher les tuiles et animer les sprites.

## Objectif et commandes

- Ramasser tous les collectibles (`C`) de la carte.
- Rejoindre la sortie (`E`) après les avoir récupérés.
- Éviter les ennemis (`N`) : les toucher met fin à la partie.
- Les déplacements valides sont comptabilisés et affichés dans la fenêtre ainsi que dans le terminal.

| Action | Touches |
| --- | --- |
| Se déplacer | Flèches directionnelles ou `W` `A` `S` `D` |
| Quitter | `Échap` ou fermeture de la fenêtre |

Les murs (`1`) bloquent le passage. Les sprites du joueur, des collectibles et des ennemis sont animés. Chaque tuile mesure **64 × 64 pixels**.

## Cartes

Une carte est un fichier texte dont le nom se termine par `.ber`. Elle doit être rectangulaire, entièrement entourée de murs et contenir uniquement les caractères suivants :

| Symbole | Signification |
| --- | --- |
| `1` | Mur |
| `0` | Sol |
| `P` | Départ du joueur — exactement un |
| `C` | Collectible — au moins un |
| `E` | Sortie — exactement une |
| `N` | Ennemi |

Le programme vérifie également que tous les collectibles et la sortie sont accessibles depuis le départ. Une carte trop grande pour l'écran est refusée.

Des cartes de jeu sont fournies dans `maps/gaming/` (`map1.ber`, `map2.ber`, `snail.ber`). Le dossier `maps/test_maps/` regroupe des cartes destinées à essayer différents cas.

## Compilation et lancement

Le projet cible **Linux** et nécessite un compilateur C (`cc`), `make`, Git ainsi qu'un environnement graphique X11 et les dépendances de développement requises par MiniLibX.

Depuis la racine du dépôt :

1. Récupérer MiniLibX si elle n'est pas déjà présente. La cible clone le dépôt 42Paris via SSH ; un accès SSH à GitHub doit donc être configuré.

	```sh
	make call_mlx
	```

2. Compiler le jeu et ses bibliothèques :

	```sh
	make
	```

3. Lancer le jeu avec une carte `.ber` :

	```sh
	./bin/so_long maps/gaming/map1.ber
	```

Lancez le jeu depuis la racine du projet : les chemins des images XPM sont relatifs au répertoire courant.

### Cibles Makefile

| Cible | Rôle |
| --- | --- |
| `make` ou `make all` | Compile l'exécutable `bin/so_long` |
| `make call_mlx` | Clone MiniLibX si son dossier n'existe pas |
| `make clean` | Supprime les fichiers objets du projet et des bibliothèques |
| `make fclean` | Nettoie puis supprime l'exécutable et les artefacts de `pedro_lib` |
| `make re` | Nettoie puis recompile |
| `make rm_mlx` | Supprime le dossier MiniLibX téléchargé |

`make clean` et `make fclean` appellent le Makefile de MiniLibX : récupérez-la d'abord avec `make call_mlx` pour que ces cibles de nettoyage puissent s'exécuter.

## Limites connues

Dans l'implémentation actuelle, entrer dans la sortie depuis le haut ne déclenche pas correctement la victoire. Pour terminer une partie, approchez la sortie depuis une autre direction.

## Organisation du projet

- `srcs_mandatory/` — démarrage du jeu, lecture et vérification des cartes, rendu, animations, déplacements et fermeture.
- `include/so_long.h` — structures, constantes, codes des touches et prototypes.
- `Libraries/pedro_lib/` — bibliothèque C du projet, compilée par son propre Makefile.
- `Textures/` — images XPM utilisées pour le décor et les animations.
- `maps/gaming/` — cartes jouables fournies.
- `maps/test_maps/` — cartes d'essai.

## Technologies

- C
- MiniLibX Linux
- X11
- Bibliothèque locale `pedro_lib`
