#ifndef EX2_H_INCLUDED
#define EX2_H_INCLUDED
#include "Ex_1.h"

typedef struct Arbre Arbre;//Un arbre
struct Arbre
{
    //Pointeur sur la valeur
    Passager * valeur;
    //Parent du noeud actuel, NULL implique qu'il est le premier 
    Arbre* racine;
    //Fils gauche ou fils plus petit comprend aussi les égalité
    Arbre* gauche;
    //Fils droit ou fils plus grand
    Arbre* droit;
};

typedef struct Racine Racine;//Début d'un arbre
struct Racine
{
    //Pointeur vers le premier noeud, NULL indique un arbre vide
    Arbre * racine;
};
//Initialise un arbre vide a partir de la racine
Racine* initialiserArbre();
//Remplis un arbre a partir d'une liste de passager
void remplirArbre(Racine* racineOrigin,Liste * liste);
//lis un arbre et retourne une liste ordonner des passagers. il clone les passagers de la liste original, celle-ci peut donc être détruite
Liste* lectureArbre(Racine* racineOrigin);


#endif // !EX2_H_INCLUDED