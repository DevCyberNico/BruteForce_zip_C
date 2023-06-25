//
// Created by nicof on 17/06/2023.
//

//

// Update by secu_omih on 23/06/23

//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <zip.h>
#include "count_open_zip.h"


//void cas_d_usage();


int open_zip(const char* fichierZip)
{
    struct zip *archive; // cette structure represente une archive ouverte.
    //const char *password = "recap"; // mot de passe du fichier.zip
    // Ouvrir l'archive ZIP chiffrée
    // important "archive" est le pointeur vers le fichier zip ouvert, obligé que ça soit une structure. 
    archive = zip_open(fichierZip, 0, NULL);
    if (archive == NULL) {

        printf("Erreur à l'ouverture de l'archive %s\n", fichierZip);
        return 404;
    }
     //on récupère le nombre de fichiers dans l'archive zip
    int count = zip_get_num_files(archive);
    if(count==-1)
    {
        printf("Erreur à la lecture du fichier %s\n", fichierZip);
        zip_close(archive);
        return 404;
    }
    int i = 0;
    printf("\nNombre de fichiers dans l'archive : %d\n\n", count);
    printf("\n");
    printf("N'hesitez pas à explorer une autre option du menu");
    
    zip_close(archive);

    return 0;

}

int open_zip_password(const char* fichierZip, const char* password)
{
    struct zip *archive; // cette structure represente une archive ouverte.
    struct zip_file *file;// cette strucutre represente un fichier dans l'archive ouvert
    //const char *password = "recap"; // mot de passe du fichier.zip
    // Ouvrir l'archive ZIP chiffrée
    // important "archive" est le pointeur vers le fichier zip ouvert, obligé que ça soit une structure. 
    archive = zip_open(fichierZip, 0, NULL);
    if (archive == NULL) {

        printf("Erreur à l'ouverture de l'archive-toi %s\n", fichierZip);
        return 404;
    }
    // je suis la ..
    
     //on récupère le nombre de fichiers dans l'archive zip
    int count = zip_get_num_entries(archive,0);
    if(count==-1)
    {
        printf("Erreur à la lecture du fichier %s\n", fichierZip);
        zip_close(archive);
        return 404;
    }

    printf("\nNombre de fichiers dans l'archive protegé : %d\n\n", count);
    printf("\n");
    printf("N'hesitez pas à explorer une autre option du menu");
    zip_close(archive);

    return 0;

}