#include <stdio.h>
#include <stdlib.h>
#include "stdprof.h"
#include "eleve.h"  


void print_file(FILE *fichier){
    char c;
    while ( (c=getc(fichier)) != EOF){
        GIGA_NIGGA_SWITCH(c);
    }
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
    map = nouvelle_carte(10, 10);
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
   return 0;
} 
