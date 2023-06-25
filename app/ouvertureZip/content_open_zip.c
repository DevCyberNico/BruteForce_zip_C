#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <zip.h>
#include "count_open_zip.c"
#include "content_open_zip.h"

//void cas_d_usage();

int content_open_zip(const char* fichierZip)
{

    struct zip *archive; // cette structure represente une archive ouverte.
    int count ;
    int i ;
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

    printf("\n");
    printf("N'hesitez pas à explorer une autre option du menu.\n");

    zip_close(archive);

    return 0;
   

}

