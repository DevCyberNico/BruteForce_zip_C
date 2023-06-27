# BruteForce_zip_C
 
By : Secu_omih@
     Boleyno
     DevCyberNico

Ce programme est conçu pour manipuler des fichiers dans une archive ZIP. Voici une description des différentes options disponibles :

### Options disponibles

- `-h, --help` : Affiche l'aide et les options disponibles du programme.
- `-o, --open` : Ouvre un fichier ZIP pour la navigation.
- `-b, --bruteforce` : Tente de forcer le mot de passe par bruteforce.
- `-d, --dictionary=DICTIONNAIRE` : Tente de forcer le mot de passe à l'aide d'un dictionnaire.
- `-p, --password=MOT_DE_PASSE` : Utilise ce mot de passe pour accéder au fichier ZIP.

#### Cas d'utilisation 1 : Ouvrir un fichier ZIP

```sh
./programme -o fichier.zip
```

Cette commande permet d'ouvrir le fichier ZIP spécifié pour la navigation.

#### Cas d'utilisation 2 : Ouvrir un Fichier ZIP protégée par un mot de passe.
```sh
./programme -o fichier.zip -p motdepasse
```
### Menu Principal

Le programme propose les options suivantes dans le menu principal :

1. Nombre total des fichiers dans l'archive ZIP.
2. Liste des fichiers contenus dans l'archive ZIP.
3. Ouvrir un fichier de l'archive.
4. Ajouter un fichier à l'archive.
5. Fermer le programme.

Pour sélectionner une option, entrez le numéro correspondant et appuyez sur Entrée.

#### Exemple d'utilisation


## Prérequis

- Ce programme nécessite d'avoir une installation de la bibliothèque LIBZIP Assurez-vous de l'installer avant d'exécuter le programme.

## Notes supplémentaires

- Assurez-vous d'avoir les permissions nécessaires pour accéder aux fichiers et répertoires spécifiés.

- En cas de problème ou de question, veuillez contacter l'équipe de développement à l'adresse esgi@gmail.com

- Ce programme est distribué sous la licence ESGI.

Nous espérons que ce guide vous aide à comprendre les différentes options et à utiliser le programme efficacement. N'hésitez pas à apporter vos propres modifications et améliorations en fonction de vos besoins spécifiques.
