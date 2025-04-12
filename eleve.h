#ifndef ELEVE_H
#define ELEVE_H

#include <stdio.h>
#include <stdlib.h>
#include "stdprof.h"
/*Eleve header*/
typedef struct carto{
    int taillex;
    int tailley;
    char **memoire ;
    int x ;
    int y;	
}carte; 

/*Structures*/
typedef struct rahan_stats {
    int pdv;
    int sante;
    int force;
    int vitesse;
} stats;


typedef struct coordonee_rahan{
    signed int x;
    signed int y;
} coordone;


typedef struct equipement {
    char * description; /*bottes en peu de croco*/
    char * bonus; /*V+10*/
    char * classe; /*chaussure*/
} objet;

typedef struct bouffe {
    char * nom;
    int  vierecup;
    char * description;
} nouritures;

typedef struct monstre_stat {
    char * name;
    int  force;
    int  vie;
} monstre;


extern struct coordonee_rahan coord;
extern struct rahan_stats rahan;
extern struct carto* map;

struct carto* nouvelle_carte(int x,int y);

void switcho(char arg);
void liberer_macron();
void VISION();
void INVOCATION();
void HAUT();
void BAS();
void GAUCHE();
void DROITE();
char lire_commande();


#endif
