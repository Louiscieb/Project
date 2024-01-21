#include <stdio.h>
#include <stdlib.h>
#include "stdprof.h"



typedef struct element_t {
    void * contenu;
    int  ligne;
    char * fichier;
    struct element_t * suivant;
} element;

struct table_pointeurs_t {
    element * valeur;
    int nb_malloc;
    int nb_free;
} ;

static struct table_pointeurs_t table_allocation = {NULL, 0 , 0};


void ajout_element(void * pointeur, int ligne, char * fichier) {
    element * e = malloc(sizeof(element));
    e->contenu = pointeur;
    e->ligne = ligne;
    e->fichier = fichier;
    e->suivant = table_allocation.valeur;
    table_allocation.valeur = e;
    table_allocation.nb_malloc ++;
}

void afficher() {
    element * e = table_allocation.valeur;
    char * jaune = "\x1b[1;33m";
    char * normal ="\x1b[0m";
    int nbm = table_allocation.nb_malloc;
    int nbf = table_allocation.nb_free;
    printf("\n%s %d free/%d malloc", jaune, nbf, nbm);
    printf("\n%s== Début table allocation ==\n\x1b[0;33m", jaune);
    while (e != NULL) {
        printf("%p ligne %d « %s »\n", e->contenu, e->ligne, e->fichier);
        e = e->suivant;
    }
    printf("\x1b[1;33m== Fin table allocation ==\n\n%s", normal);
}

int supprimer(void * pointeur) {
    char * rouge = "\x1b[1;31m";
    char * normal ="\x1b[0m";
    element * e = table_allocation.valeur;
    element * suivant;

    if (e != NULL) {
        if (e->contenu == pointeur) {
            table_allocation.valeur = e->suivant;
            table_allocation.nb_free ++;
            return 0;
        }
    }

    while (e != NULL) {
        suivant = e->suivant;
        if (suivant != NULL) {
            if (suivant->contenu == pointeur) {
                e->suivant = suivant->suivant;
                table_allocation.nb_free ++;
                return 0;
            }
        }
        e = suivant;
    }
    fprintf(stderr, "%s/*\\ ATTENTION /*\\ pointeur « %p » invalide !\n%s",rouge,pointeur, normal);
    return 1;
}


void *stdprof_malloc_fonction(size_t taille, int ligne, char * fichier) {
    void * p = malloc(taille);
    ajout_element(p, ligne, fichier);
    return p;
}

void stdprof_free(void * p) {
    supprimer(p);
    free(p);
}

void stdprof_afficher() {
    afficher();
}
