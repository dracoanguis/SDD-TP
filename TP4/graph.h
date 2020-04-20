#ifndef GRAPH_H
#define GRAPH_H
#include "liste.h"
#include <stdio.h>

//def pour appelle double:

//Un Sommet du graph avec un nom(lien vers le nom de la donnée) ,une data, une liste de successeur, et une marque.
typedef struct Sommet Sommet;
//Un Successeur avec un sommet representer, un cout.
typedef struct Successeur Successeur;


//Succeseur possible a un sommet:
struct Successeur
{
    Sommet* sommet_representer;//L'element qu'il représente.
    int cout;//Le cout du déplacement.
};

//Elements du graph:
struct Sommet
{
    char* nom;//Nom/code raccourcie au possible.
    void* data;//Les valeurs du graph.
    Liste* liaisons;//Les arcs du graph.
    int marque;//S'il a été visité ou pas, 0 non, 1 oui.
};

//Fonctions d'initialisation de structure:

//Initilaise un sommet avec les données fournies (accepte une liste NULL et marque initialiser a 0) et retoune sont pointeur.
Sommet* initialiserSommet(void* data,Liste* successeurs,char* nom);
//Initialise un successeur a partir d'un Sommet et d'un cout.
Successeur* initialiserSuccesseur(Sommet* sommet,int cout);


//Fonctions d'affichage d'element:

//Affiche les informations d'un sommet.
void afficherSommet(Sommet* sommet);
//Affiche les informations d'un successeur.
void afficherSuccesseur(Successeur* successeur);


//Fonctions d'affichage de liste:

//Affiche la liste des successeurs avec leur informations.
void afficherListe_Successeur(Liste* liste);
//Affiche la liste des sommets avec leur informations.
void afficherListe_Sommet(Liste* liste);


//Fonctions de lecture de document:

//Liste les aeroports a partir des informations du fichier.
Liste* lectureAeroports(const char *faeroports);
//Liste les sommets a partir des insformations du fichier.
Liste* lectureSommets(const char* fsommet);
//Inscrit les successeurs dans les liaisons de la liste de Sommet.
void lectureSuccesseurs(const char* fsuccesseur,Liste* liste_sommet);


//Groupe de fonction pour fonction de création de liste successeur:

//Cherche le Sommet representer par un successeur a partir du nom de celui-ci (code iata).
Sommet* chercherSommet_Successeur(Liste* liste_sommet,char* nom);
//Donne le Successeur a partir d'un bloc successeur (ex: "LHR.45").
Successeur* lectureBlocSuccesseur(char* bloc, Liste* liste_sommet);
//Donne une liste de successeur a partir d'une ligne d'information en Bloc.
Liste* lectureLigneSuccesseur(char ligne[], Liste* liste_sommet);
//Lis une ligne dans un fichier.
char* readline(FILE* file);
#endif // !GRAPH_H