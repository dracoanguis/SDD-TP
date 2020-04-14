#include <string.h>
#include "graph.h"
#include "liste.c"

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

void afficherListe_Aeroport(Liste* liste)
{
    if (liste == NULL || liste->premier == NULL)
    {
        printf("\nError: Trying to print an empty Liste_Aeroport!!!\n");
        exit(EXIT_FAILURE);
    }

    Element* courrant = liste->premier;

    while (courrant != NULL)
    {
        afficherAeroport(courrant->data);
        courrant = courrant->prochain;
    }
}

Liste* lectureAeroports(const char *faeroport)
{
    Liste* aeroports = initialiserListe();
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
        ajouterElementListe(aeroports,initialiserAeroport(iata,ville,pays));
    }
    fclose(file);
    return aeroports;
}

int main() {
    Liste* aeroports = initialiserListe();
    aeroports = lectureAeroports("aeroport.txt");
    afficherListe_Aeroport(aeroports);
    return 0;
}