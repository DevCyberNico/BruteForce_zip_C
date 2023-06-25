#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <zip.h>
//#include "count_open_zip.c"
#include "content_open_zip.h"
#include "see_file_zip.h"

//void cas_d_usage();

int see_open_file(const char* fichierZip)
{

    struct zip *archive; // cette structure represente une archive ouverte.
    struct zip_file *file; // un fichier du zip ouvert 
    int count ;
    int i ;
    char filename[100];
    //const char *password = "recap"; // mot de passe du fichier.zip

    // Ouvrir l'archive ZIP chiffrée
    // important "archive" est le pointeur vers le fichier zip ouvert, obligé que ça soit une structure. 
    archive = zip_open(fichierZip, 0, NULL);
    if (archive == NULL) {

        printf("Erreur à l'ouverture de l'archive %s\n", fichierZip);
        return 404;
    }
    
     //on récupère le nombre de fichiers dans l'archive zip
    count = zip_get_num_files(archive);
    if(count==-1)
    {
        printf("Erreur à la lecture du fichier %s\n", fichierZip);
        zip_close(archive);
        return 404;
    }
    printf("\nLa liste des dossiers et ou fichiers contenu dans le zip:\n");
    printf("\n");
    for(i=0; i<count; i++)
    {
        //on utilise la position "i" pour récupérer le nom des fichiers
        printf("%s\n", zip_get_name(archive, i, ZIP_FL_UNCHANGED));
    }

    printf("\nPourriez-vous indiquer le fichier que vous voulez lire(+extension)\n\n");
    scanf("%s", filename);
    printf("\n");

    file = zip_fopen(archive,filename,0);
    if (file == NULL) 
    {
        // Gérer l'erreur d'ouverture du fichier
        printf("Erreur à l'ouverture du fichier %s\n", fichierZip);
        zip_close(archive);
        return -1;
    }


    char buffer[256];// un pointeur générique
    int linereadable = zip_fread(file, buffer, sizeof(buffer));
    while (linereadable > 0) {
        // Lire le fichier 
        printf("%.*s", linereadable, buffer);

        linereadable = zip_fread(file, buffer, sizeof(buffer));
    }
     printf("\n");
    // Fermer le fichier 
    zip_fclose(file);

    printf("\n\n");
    printf("N'hesitez pas à explorer une autre option du menu.\n");

    //Fermer l'archive
    zip_close(archive);

    return 0;
   

}

int see_open_file_password(const char* fichierZip, const char* password)
{

    struct zip *archive; // cette structure represente une archive ouverte.
    struct zip_file *file; // un fichier du zip ouvert 
    int count ;
    int i ;
    char filename[100];
    //const char *password = "recap"; // mot de passe du fichier.zip

    // Ouvrir l'archive ZIP chiffrée
    // important "archive" est le pointeur vers le fichier zip ouvert, obligé que ça soit une structure. 
    archive = zip_open(fichierZip, 0, NULL);
    if (archive == NULL) {

        printf("Erreur à l'ouverture de l'archive %s\n", fichierZip);
        return 404;
    }
    
     //on récupère le nombre de fichiers dans l'archive zip
    count = zip_get_num_files(archive);
    if(count==-1)
    {
        printf("Erreur à la lecture du fichier %s\n", fichierZip);
        zip_close(archive);
        return 404;
    }
    printf("\nLa liste des dossiers et ou fichiers contenu dans le zip:\n");
    printf("\n");
    for(i=0; i<count; i++)
    {
        //on utilise la position "i" pour récupérer le nom des fichiers
        printf("%s\n", zip_get_name(archive, i, ZIP_FL_UNCHANGED));
    }

    printf("\nPourriez-vous indiquer le fichier que vous voulez lire(+extension)\n\n");
    scanf("%s", filename);
    printf("\n");

    file = zip_fopen_encrypted(archive, filename, 0, password);
    if (file == NULL) 
    {
        // Gérer l'erreur d'ouverture du fichier
        printf("Erreur à l'ouverture du fichier test %s\n", fichierZip);
        zip_close(archive);
        return -1;
    }

    char buffer[256];// un pointeur générique
    int linereadable = zip_fread(file, buffer, sizeof(buffer));
    while (linereadable > 0) {
        // Lire le fichier 
        printf("%.*s", linereadable, buffer);

        linereadable = zip_fread(file, buffer, sizeof(buffer));
    }
     printf("\n");
    // Fermer le fichier 
    zip_fclose(file);

    printf("\n\n");
    printf("N'hesitez pas à explorer une autre option du menu.\n");

    //Fermer l'archive
    zip_close(archive);

    return 0;
   

}
