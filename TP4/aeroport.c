#ifndef AEROPORT_C
#define AEROPORT_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aeroport.h"

Aeroport* initialiserAeroport(char iata[5],char ville[50],char pays[50])
{
    Aeroport *nouveau = malloc(sizeof(Aeroport));

    if (nouveau == NULL)
    {
        printf("\nMemory allocation Failure!!!\n");
        exit(EXIT_FAILURE);
    }

    strcpy(nouveau->iata, iata);
    strcpy(nouveau->ville,ville);
    strcpy(nouveau->pays, pays);

    return nouveau;
}

void afficherAeroport(Aeroport* aeroport)
{
    if (aeroport == NULL)
    {
        printf("\nError: Trying to print an non-existant Aeroport!!!\n");
        exit(EXIT_FAILURE);
    }

    printf("\n");
    printf("Code Iata: %s\n",aeroport->iata);
    printf("Ville: %s\n",aeroport->ville);
    printf("Pays: %s\n",aeroport->pays);
}

Liste_Aeroport* initialiserListe_Aeroport()
{
    Liste_Aeroport* nouveau = malloc(sizeof(Liste_Aeroport));

    if (nouveau == NULL)
    {
        printf("\nMemory allocation Failure!!!\n");
        exit(EXIT_FAILURE);
    }

    nouveau->premier = NULL;

    return nouveau;
}

void ajouterElementListe_Aeroport(Liste_Aeroport* liste,Aeroport* nvAeroport)
{
    Element* nouveau = malloc(sizeof(Element));
    Element* courrant = liste->premier;
    if (nouveau == NULL)
    {
        printf("\nMemory allocation Failure!!!\n");
        exit(EXIT_FAILURE);
    }

    if (liste == NULL)
    {
        printf("\nError: Adding element to non-existing Liste_Aeroport!!!\n");
        exit(EXIT_FAILURE);
    }

    nouveau->aeroport = nvAeroport;
    nouveau->suivant = NULL;

    if (liste->premier == NULL)
    {
        liste->premier = nouveau;

    } else {
        while (courrant->suivant != NULL)
        {
            courrant = courrant->suivant;
        }
    
        courrant->suivant = nouveau;
    }
}

void supprimerElementListe_Aeroport(Liste_Aeroport* liste)
{
    Element* courrant = liste->premier;

    if (liste == NULL)
    {
        printf("\nError: Supressing element to non-existing Liste_Aeropot!!!\n");
        exit(EXIT_FAILURE);
    }

    if (courrant == NULL)
    {
        printf("\nSupressing element to empty list suppressing list instead!!!\n");
        free(liste);
    } else {
        liste->premier = courrant->suivant;
        free(courrant);
    }
}

void afficherListe_Aeroport(Liste_Aeroport* liste)
{
    if (liste == NULL || liste->premier == NULL)
    {
        printf("\nError: Trying to print an empty Liste_Aeroport!!!\n");
        exit(EXIT_FAILURE);
    }

    Element* courrant = liste->premier;

    while (courrant != NULL)
    {
        afficherAeroport(courrant->aeroport);
        courrant = courrant->suivant;
    }
}

Liste_Aeroport* lectureAeroports(const char *faeroport)
{
    Liste_Aeroport* aeroports = initialiserListe_Aeroport();
    char iata[5];
    char ville[50];
    char pays[50];
    FILE* file = NULL;
    file = fopen(faeroport,"r+");
    if (file == NULL)
    {
        printf("\nError: Invalid file!!!\n");
    }
    while (fscanf(file,"%5s %50s %50s",iata,ville,pays) != EOF)
    {
        ajouterElementListe_Aeroport(aeroports,initialiserAeroport(iata,ville,pays));
    }
    fclose(file);
    return aeroports;
}

#endif // !AEROPORT_C