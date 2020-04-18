#ifndef LISTE_C
#define LISTE_C
#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#define memoryTest(pointeur) if (pointeur == NULL){printf("\nMemory allocation Failure !\n");exit(EXIT_FAILURE);}

Liste* initialiserListe()
{
    Liste* nouveau = malloc(sizeof(Liste));
    memoryTest(nouveau);

    nouveau->premier = NULL;

    return nouveau;
}

void ajouterElementListe(Liste* liste,void* element)
{
    Element* nouveau = malloc(sizeof(Element));
    Element* courrant = liste->premier;
    memoryTest(nouveau);

    if (liste == NULL)
    {
        printf("\nError: Adding element to non-existing Liste!!!\n");
        exit(EXIT_FAILURE);
    }

    nouveau->data = element;
    nouveau->prochain = NULL;

    if (liste->premier == NULL)
    {
        liste->premier = nouveau;

    } else {
        while (courrant->prochain != NULL)
        {
            courrant = courrant->prochain;
        }
    
        courrant->prochain = nouveau;
    }
}

void supprimerElementListe(Liste* liste)
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
        liste->premier = courrant->prochain;
        free(courrant);
    }
}

#endif // !LISTE_C