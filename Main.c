#include <stdio.h>
#include <stdlib.h>
#include "stdprof.h"
#include "eleve.h"
#include "Lecture.c"

void print_file(FILE *fichier){
    char c;
    while ( (c=getc(fichier)) != EOF) fputc(c,stdout);
    GIGA_NIGGA_SWITCH(c);
}

int main(int argc, char* argv[]){
    int i_l;
    FILE * fichiers;
    char * nom_fichier;
    int i,j;
    char init_values[10][10] = {
        {'R', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' '},
        {' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', 'Y', ' ', ' ', '#', ' ', ' '},
        {' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
    spawn_rahan();
    map= nouvelle_carte(10,10);
    for ( i = 0; i < map->tailley; i++) {
        for ( j = 0; j < map->taillex; j++) {
            map->memoire[i][j] = init_values[i][j];
        }
    }
    

    if (argc==1) { /* argv[0] : nom du programme */
    print_file(stdin); /* stdin : entrée standard */
   
    }
    else {
    for (i_l=1; i_l<argc; i_l++) {
    nom_fichier = argv[i_l];
    if ((fichiers=fopen(nom_fichier,"r")) == NULL) {
        fprintf(stderr,"Erreur lecture %s\n",nom_fichier);
        exit(1);
    }
        print_file(fichiers);
        fclose(fichiers);
    }
    }
    /*afficher_carte();
    BAS();
    BAS();
    INVOCATION();
    afficher_carte();
    DROITE();
    HAUT();
    afficher_carte(); 
    HAUT();
    afficher_carte();
    liberer_macron();
    printf("%d , %d",coord.x,coord.y);
    stdprof_afficher();*/
    /*printf("%d",lire_commande());*/
    
 /*   printf("Entrez une chaîne de caractères (Ctrl+D pour terminer la saisie) :\n");


    printf("Vous avez saisi : ");
    
    while ((character = getchar()) != EOF && character != '\n') {
        printf("%c",character);
        
    }
    afficher_carte();
    test[1]=character;   
    printf("%s",test);

    printf("\n");
    

    */
   return 0;
} 
