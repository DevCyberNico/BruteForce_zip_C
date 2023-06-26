//
// Created by nicof on 17/06/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <zip.h>
#include "manage_options.h"
#include "../casUsages/usage_case.h"
#include "../ouvertureZip/interactif/InteractiveopenZip.c"




void manage_options(int argc, char *argv[])
{
     
      int  option;
      int  open_state = 0;
      char *dictionnaire = NULL;
      char *password = NULL;
      int verification = 0;

    option = getopt(argc,argv,"hopd:e:i:");
  
    while(!verification)
    {
        if (option == -1)
        {
            break; 
        }
        switch (option)
        {
        case 'h': 
                cas_d_usage();
                exit(1); // fonction d'affichage.
                break;

        case 'o':
                open_state = 1; // si la fonction open est utlisé il prend cette valeur
                break;
        case 'p':
                 password = optarg; // 
                break;
        case 'd':
                
                dictionnaire = optarg; 
                break;

         case ':':
                 printf("\n Erreur -%c Manque d'argument\n", optopt);
                 cas_d_usage(); 
                 exit(2);
                break;
         case '?': 
                  printf( "\n Argument inconnu %c\n\n", optopt);
                  cas_d_usage();
                  exit(3);  
                  break;
         case '0':
               printf("\n Necessite au moins un argument\n\n", optopt);
               cas_d_usage();
               exit(4);
               break;
                

        default: 
            cas_d_usage();
            exit(5);
            break;
        }
   
   
        // Appel de la fonction pour ouvrir et parcourir le fichier zip
        //optind est une variable global qui suit l'argument actuelement traiter
        // argc nombre total des arguments 
        // argv[optind] recupere l'index et donc notre fichier zip
         if ((argc == 3) ){
            accueil();
            verification = 1;
         } 
        else {
            //printf("Erreur : Aucun fichier zip spécifié\n");
            //cas_d_usage();

             printf("Erreur : Aucun fichier zip spécifié\n");
            cas_d_usage();
            verification = 1;
        }

    if (dictionnaire) { 
        // Appel de la fonction pour effectuer la force brute du mot de passe avec un dictionnaire
        // brute_force_with_dictionary(archive, dictionnaire);
    }

   // if ((open_state && password)) {
         if (argc == 5)
         {
            accueil_password();
            verification = 1;
            
      }   else {
            //printf("Erreur : Aucun fichier zip spécifié\n");
            //cas_d_usage();
            printf("Erreur : Aucun fichier zip spécifié\n");
            cas_d_usage();
            verification = 1;
        }
        
    //}
    }

}