#include <stdio.h>
#include <stdlib.h>
#include <zip.h>


#define MAX_LIGNE_LONGUEUR 100




void bruteforce(const char *fichier_dico, const char *fichierZip, const char *password){    // 

    //char password[4] = "test";
    int verif = 1;

    FILE* file = fopen(fichier_dico, "r");
    if (file == NULL){
        printf("Le fichier n'est pas utilisable");
        return;
    }

    char line[MAX_LIGNE_LONGUEUR];
    while(fgets(line, sizeof(line), file) != NULL){
        printf("%s", line);
    }

    fclose(file);

    printf("\n");

}



int main() {
    const char *fichier_dico = "dico.txt";
    const char *fichierZip = "test.zip";
    const char *password = "test";

    //bruteforce(fichier_dico, fichierZip, password); //encryptedFile
    openEncryptedArchive(fichierZip, password);

    return 0;
}
