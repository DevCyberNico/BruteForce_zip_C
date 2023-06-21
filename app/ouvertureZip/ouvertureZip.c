//
// Created by nicof on 17/06/2023.
//

//

// Update by secu_omih on 21/06/23

//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <zip.h>
#include "ouvertureZip.h"


//void cas_d_usage();

int open_zip(const char* fichierZip)
{

    struct zip *archive; // cette structure represente une archive ouverte.
    struct zip_file *file; // cette structure represente un fichier dans l'archive.
    //const char *password = "recap"; // mot de passe du fichier.zip

    // Ouvrir l'archive ZIP chiffrée
    // important "archive" est le pointeur vers le fichier zip ouvert, obligé que ça soit une structure. 
    archive = zip_open(fichierZip, 0, NULL);
    if (archive == NULL) {

        printf("Erreur à l'ouverture de l'archive %s\n", fichierZip);
        return 404;
    }

    file = zip_fopen(archive, "recap2.txt", 0);
    
    if (file == NULL) {
        // Gérer l'erreur d'ouverture du fichier
        printf("Erreur à l'ouverture du fichier %s\n", fichierZip);
        zip_close(archive);
        return -1;
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
    printf("Nombre de fichiers dans l'archive : %d\n",count);

    for(i=0; i<count; i++)
    {
        /* on utilise la position "i" pour récupérer le nom des fichiers */
        printf("%s\n", zip_get_name(archive, i, ZIP_FL_UNCHANGED));
    }
     
    // Lire le contenu du fichier
    char buffer[256];
    int bytesRead = zip_fread(file, buffer, sizeof(buffer));
    while (bytesRead > 0) {
        // Faire quelque chose avec les données lues
        printf("%.*s", bytesRead, buffer);
        //bytesRead = zip_fread(file, buffer, sizeof(buffer));
    }
    
    // Fermer le fichier et l'archive
    zip_fclose(file);
    zip_close(archive);

    return 0;
   

}
