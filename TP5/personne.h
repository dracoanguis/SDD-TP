#ifndef PERSONNE_H
#define PERSONNE_H
#include "liste.h"

//definition d'une personne avec un id, un prenom, un nom, un age, un (numero) siege.
typedef struct Personne Personne;
struct Personne
{
    int id;
    char prenom[10];
    char nom[10];
    int age;
    int siege;
};

//Initialise une personne.
Personne* initialiserPersonne(int id,char prenom[10],char nom[10],int age,int siege);
//Lis les informations des personnes d'un fichier du bon format.
Liste* listerPersonne(const char *fpersonne);
#endif // !PERSONNE_H