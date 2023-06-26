#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <zip.h>

#include "../contenuFichier/content_open_zip.c"
#include "../voirFichier/see_file_zip.c"
#include "../../casUsages/usage_case.c"
#include "../../Ajout_fichier/add_file.c"

#include "InteractiveopenZip.h"

void cas_d_usage();

#define argument __argv
#define argumentTT __argc

void accueil()
{

    char approbation;
    int choix_menu;
    char *archive = NULL;

    do{
        printf("****************************************\n"
               "*                                      *\n"
               "*                                      *\n"
               "*                                      *\n"
               "*       INTERACTIVE BROWSING FILE      *\n"
               "*                                      *\n"
               "*                 BY                   *\n"
               "*           Nicolas FOESSEL            *\n"
               "*              Daniel B.               *\n"
               "*         HERMANN ISMAEL OSSOMBI M.    *\n"
               "*                                      *\n"
               "*                                      *\n"
               "*                                      *\n"
               "****************************************\n\n\n"

               "1 - Nombre total des fichiers dans l'archive zip \n\n"

               "2 - La liste de fichiers contenu dans l'archive zip\n\n"

               "3 - Ouvrir un fichier  \n\n"

               "4 - Inclure un fichier  \n\n"

               "5 - Fermer le programme\n\n"

        );

        /**
        */
        // argc nombre total des arguments 
        // argv[optind] recupere l'index et donc notre fichier zip
        do{
            printf("\nEntrer votre Choix : \n\n");
            scanf("%d", &choix_menu);
        }while(choix_menu < 1 || choix_menu > 5);

        switch(choix_menu){
            case 1:
                if (optind < argumentTT) {
                archive = argument[optind];
                open_zip(archive);
                }   
                else {
                printf("Erreur : Aucun fichier zip spécifié\n");
                cas_d_usage();
                }
                break;
            case 2:
                if (optind < argumentTT) {
                archive = argument[optind];
                content_open_zip(archive);
                }   
                else {
                printf("Erreur : Aucun fichier zip spécifié\n");
                cas_d_usage();
                }
                break;
              
            case 3:
                if (optind < argumentTT) {
                archive = argument[optind];
                see_open_file(archive);
                }   
                else {
                printf("Erreur : Aucun fichier zip spécifié\n");
                cas_d_usage();
                }
                break;

            case 4:
                if (optind < argumentTT) {
                archive = argument[optind];
                add_file_zip(archive);
                }   
                else {
                printf("Erreur : Aucun fichier zip spécifié\n");
                cas_d_usage();
                }
                break;

            case 5 :

                break;
 
            default:
                accueil();
                break;

        }

        printf("\nVoulez vous continuez: N/Y \n\n");
        scanf("%s", &approbation);

    }
    while(approbation == 'y' || approbation == 'Y');
}

void accueil_password()
{

    char approbation;
    int choix_menu;
    char *archive = NULL;
    char *password = NULL;

    do{
        printf("****************************************\n"
               "*                                      *\n"
               "*                                      *\n"
               "*                                      *\n"
               "*       INTERACTIVE BROWSING FILE      *\n"
               "*                                      *\n"
               "*                 BY                   *\n"
               "*           Nicolas FOESSEL            *\n"
               "*              Daniel B.               *\n"
               "*         HERMANN ISMAEL OSSOMBI M.    *\n"
               "*                                      *\n"
               "*                                      *\n"
               "*                                      *\n"
               "****************************************\n\n\n"

               "1 - Nombre total des fichiers dans l'archive zip_avec_mot_de_passe \n\n"

               "2 - La liste de fichiers contenu dans l'archive zip\n\n"

               "3 - Ouvrir un fichier  \n\n"

               "4 - inclure un fichier  \n\n"

               "5 - Fermer le programme\n\n"

        );

        
        do{
            printf("\nEntrer votre Choix : \n\n");
            scanf("%d", &choix_menu);
        }

        while(choix_menu < 1 || choix_menu > 5);

        switch(choix_menu){
            case 1:
                if (optind < argumentTT) {
                archive = argument[optind];
                password = argument[optind + 2];
                open_zip_password(archive,password);
                }   
                else {
                printf("Erreur : Aucun fichier zip spécifié\n");
                cas_d_usage();
                }
                break;
            case 2:
                if (optind < argumentTT) {
                archive = argument[optind];
                content_open_zip(archive);
                }   
                else {
                printf("Erreur : Aucun fichier zip spécifié\n");
                cas_d_usage();
                }
                break;
              
            case 3:
                if (optind < argumentTT) {
                archive = argument[optind];
                password = argument[optind + 2];
                see_open_file_password(archive,password);
                }   
                else {
                printf("Erreur : Aucun fichier zip spécifié\n");
                cas_d_usage();
                }
                break;

            case 4:
                if (optind < argumentTT) {
                archive = argument[optind];
                add_file_zip(archive);
                }   
                else {
                printf("Erreur : Aucun fichier zip spécifié\n");
                cas_d_usage();
                }
                break;

            case 5 :

                break;
 
            default:
                accueil();
                break;

        }

        printf("\nVoulez vous continuez: N/Y \n\n");
        scanf("%s", &approbation);

    }
    while(approbation == 'y' || approbation == 'Y');
}