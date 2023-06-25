#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <zip.h>

int add_file_zip(const char* fichierZip)
{    
     struct zip* archive;
     struct zip_source* source;
     const char* nomduFichier = "C:/Users/hi.ossombimbossa/Documents/ZIP_Project/sujet.txt";
     const char* chemindestination = "C:/Users/hi.ossombimbossa/Documents/ZIP_Project/recap2.zip/sujet.txt";
     int verdict;

    archive= zip_open(fichierZip, ZIP_CREATE, NULL);
    if (archive == NULL) {
        printf("Échec de l'ouverture de l'archive zip\n");
        return 404;
    }
    //printf("\nPourriez-vous indiquer le fichier que vous voulez ajoutez(+extension)\n\n");
    //scanf("%s", nomduFichier);
    //printf("\n");

   // printf("\nVeuillez entrer le chemin de destination du fichier dans le zip\n\n");
    //scanf("%s", chemindestination);
    //printf("\n");

   // printf("%s",chemindestination);
    //printf("%s", nomduFichier);

    source = zip_source_file(archive, nomduFichier, 0, -1);
    if (source == NULL) {
        printf("Échec de la création de la source zip à partir du fichier\n");
        zip_close(archive);
        return 404;
    }

    verdict = zip_file_add(archive, chemindestination, source, ZIP_FL_ENC_UTF_8);
    if (verdict == 0) {
        printf("Échec de l'ajout du fichier à l'archive zip\n");
        zip_source_free(source);
        zip_close(archive);
        return 404;
    }

    zip_source_free(source);
    zip_close(archive);

    printf("Fichier ajouté à l'archive zip avec succès\n");

    int count = zip_get_num_files(archive);
    if(count==-1)
    {
        printf("Erreur à la lecture du fichier %s\n", fichierZip);
        zip_close(archive);
        return 404;
    }
    printf("\nNombre de fichiers dans l'archive : %d\n\n", count);
    printf("\n");

    printf("\nLa liste des dossiers et ou fichiers contenu dans le zip:\n");
    printf("\n");
    int i = 0 ;
    for(i=0; i<count; i++)
    {
        //on utilise la position "i" pour récupérer le nom des fichiers
        printf("%s\n", zip_get_name(archive, i, ZIP_FL_UNCHANGED));
    }


    return 202;
}
