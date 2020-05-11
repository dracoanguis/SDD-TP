#ifndef HACHAGE_H
#define HACHAGE_H

typedef struct Hache Hache;
struct Hache
{
    int essaie;
    int hache;
    void* element;
};

//Innitialise un Hache
Hache innitialiserHache(void* element);
//Retourne le code d'un mot.
int coderMotNombreSimple(char mot[], int taille);
//Remplis la table de emptyHache.
void remplissageTableHacheVide(Hache table[],int taille);
//Remplis la table avec des Hache simple.
void remplissageTableHacheSimple(Hache table[],int tailletable,Liste* liste);
//Retourne le hache d'un mot en Linear.
int coderMotNombreLinear(char mot[], int taille, int essaie);
//Remplis la table avec des Hache en Linear.
void remplissageTableHacheLinear(Hache table[],int tailletable,Liste* liste);
//Retourne le hache d'un mot en Quadratique.
int coderMotNombreQuadratique(char mot[], int taille, int essaie);
//Remplis la table avec des Hache Quratique.
void remplissageTableHacheQuadratique(Hache table[],int tailletable,Liste* liste);
//Retourne le hache d'un mot en Double.
int coderMotNombreDouble(char mot[],char motb[], int taille, int essaie);
//Remplis la table avec des Hache Double.
void remplissageTableHacheDouble(Hache table[],int tailletable,Liste* liste);
//Remplis le fichier statistique.log avec les informations données.
void statistiques(Hache table[],int taille,Liste* objet,char typeobjet[],char clef[],char fileobjet[],char typehache[]);
#endif // !HACHAGE_H
