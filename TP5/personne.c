#ifndef PERSONNE_C
#define PERSONNE_C
#include "personne.h"
#include "liste.c"
#include "string.h"

Personne* initialiserPersonne(int id,char prenom[10],char nom[10],int age,int siege)
{
    Personne* nouveau = malloc(sizeof(Personne));
    memoryTest(nouveau);

    nouveau->age = age;
    nouveau->id = id;
    strcpy(nouveau->nom,nom);
    strcpy(nouveau->prenom,prenom);
    nouveau->siege = siege;

    return nouveau;
}

Liste* listerPersonne(const char *fpersonne)
{
    Liste *passagers = initialiserListe();
    char nom[10];
    char prenom[10];
    int numClient;
    int age;
    int place;
    FILE* fichier = NULL;
    fichier = fopen(fpersonne,"r+");
    if (fichier == NULL) {printf("Fichier Introuvable !!"); exit(EXIT_FAILURE);}
    while (fscanf(fichier,"%d %10s %10s %d %d",&numClient,nom,prenom,&age,&place) != EOF)
    {
        ajouterElementListe(passagers,initialiserPersonne(numClient,prenom,nom,age,place));
    }
    fclose(fichier);
    return passagers;
}

#endif // !PERSONNE_C