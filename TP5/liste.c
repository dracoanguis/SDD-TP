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

Pile* initialiserPile()
{
    Pile* nouveau = malloc(sizeof(Pile));
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

void ajouterElementPile(Pile* pile,void* element)
{
    if (pile == NULL)
    {
        printf("\nError: Adding Element to a non-existing Pile!\n");
        exit(EXIT_FAILURE);
    }

    Element* nouveau = malloc(sizeof(Element));
    memoryTest(nouveau);

    nouveau->data = element;
    nouveau->prochain = pile->premier;
    pile->premier = nouveau;
}

void supprimerElementPile(Pile* pile)
{
    Element* courrant = pile->premier;

    if (pile == NULL)
    {
        printf("\nError: Supressing element to non-existing Pile!!!\n");
        exit(EXIT_FAILURE);
    }

    if (courrant == NULL)
    {
        printf("\nSupressing element to empty Pile suppressing Pile instead!!!\n");
        free(pile);
    } else {
        pile->premier = courrant->prochain;
        free(courrant);
    }
}

void supprimerElementFile(Liste* pile)
{
    Element* courrant = pile->premier;

    if (pile == NULL)
    {
        printf("\nError: Supressing element to non-existing Liste!!!\n");
        exit(EXIT_FAILURE);
    }

    if (courrant == NULL)
    {
        printf("\nSupressing element to empty Liste suppressing Liste instead!!!\n");
        free(pile);
    } else {
        pile->premier = courrant->prochain;
        free(courrant);
    }
}

int compterElementListe(Liste* liste)
{
    if (liste == NULL)
    {
        printf("\nError: Counting a non-existing List !\n");
        exit(EXIT_FAILURE);
    }

    Element* courrant = liste->premier;
    int nombre = 0;

    while (courrant != NULL)
    {
        nombre++;
        courrant = courrant->prochain;
    }
    
    return nombre;
}

#endif // !LISTE_C