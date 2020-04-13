
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Ex_1.h"

Liste* initialiserListe()
{
    Liste* listeInit = malloc(sizeof(Liste));
    if (listeInit == NULL)
    {
        exit(EXIT_FAILURE);
    }

    listeInit->premier = NULL;

    return listeInit;
}

void insererDebutListe(Liste *liste, Passager* nvPassager)
{
    Element *nouveau = malloc(sizeof(Element));
    if (nouveau == NULL || liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->passager = *nvPassager;
    nouveau->prochain = liste->premier;
    liste->premier = nouveau;
}

void insererFinListe(Liste *liste, Passager* nvPassager)
{
    Element *nouveau = malloc(sizeof(Element));
    Element* courrant = liste->premier;
    if (nouveau == NULL || liste == NULL)
    {
        exit(EXIT_FAILURE);
    }

    while (courrant->prochain != NULL)
    {
        courrant = courrant->prochain;
    }
    
    courrant->prochain = nouveau;
    nouveau->passager = *nvPassager;
    nouveau->prochain = NULL;
}

void supprimerElementListe(Liste *liste)
{
    Element *courrant = liste->premier;
    
    liste->premier = courrant->prochain;
    
    free(courrant);
}

Passager *initialiserPassager(int numClient,char *nom, char*prenom,int age,int place)
{
    Passager *nouveau = malloc(sizeof(Passager));
    if (nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }

    nouveau->age = age;
    nouveau->numClient = numClient;
    nouveau->place = place;
    strcpy(nouveau->nom,nom);
    strcpy(nouveau->prenom,prenom);
    return nouveau;
}

void afficherListe(Liste * liste)
{
    Element *courrant = liste->premier;
    while (courrant != NULL)
    {
        printf("\nPassager numero %d :",courrant->passager.numClient);
        printf("\n    -Nom: %s",courrant->passager.nom);
        printf("\n    -Prenom: %s",courrant->passager.prenom);
        printf("\n    -Age:%d",courrant->passager.age);
        printf("\n    -Numero de place : %d\n",courrant->passager.place);
        courrant = courrant->prochain;
    }
    printf("\n------------------FIN------------------");
}

Liste *listerPassager(const char *fpassager)
{
    Liste *passagers = initialiserListe();
    char nom[50];
    char prenom[50];
    int numClient;
    int age;
    int place;
    FILE* fichier = NULL;
    fichier = fopen(fpassager,"r+");
    if (fichier == NULL) {printf("Fichier Introuvable !!"); exit(EXIT_FAILURE);}
    while (fscanf(fichier,"%d %9s %9s %d %d",&numClient,nom,prenom,&age,&place) != EOF)
    {
        insererDebutListe(passagers,initialiserPassager(numClient,nom,prenom,age,place));
    }
    fclose(fichier);
    return passagers;
}

#ifndef EXIST_MAIN //Pour la reutilisation dans les exercice suivant
int main() {
    Liste* liste = listerPassager("passagers.txt");
    afficherListe(liste);
    return 0;
}
#endif