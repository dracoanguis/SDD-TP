#ifndef AEROPORT_C
#define AEROPORT_C
#include "aeroport.h"
#define VARIABLE_SOMMET_DEF char iata[4];char ville[50];char pays[50];
#define FORME_SOMMET "%4s %50s %50s"
#define VARIABLE_SOMMET_USE iata,ville,pays
#define INNITIALISER_DATA initialiserAeroport(VARIABLE_SOMMET_USE)
#define nomSom(Sommet) Sommet->data->iata
#define AFFICHER_DATA(aeroport) afficherAeroport(aeroport)
#define CODE_SOMMET iata
#include "graph.c"


//Aeroports:

Aeroport* initialiserAeroport(char iata[4],char ville[50],char pays[50])
{
    Aeroport *nouveau = malloc(sizeof(Aeroport));
    memoryTest(nouveau);

    strcpy(nouveau->iata, iata);
    strcpy(nouveau->ville,ville);
    strcpy(nouveau->pays, pays);

    return nouveau;
}

void afficherAeroport(Aeroport* aeroport)
{
    if (aeroport == NULL)
    {
        printf("\nError: Trying to print an non-existant Aeroport !\n");
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
        printf("\nError: Trying to print a non-existant or empty Liste_Aeroport !\n");
        exit(EXIT_FAILURE);
    }

    Element* courrant = liste->premier;

    while (courrant != NULL)
    {
        afficherAeroport(courrant->data);
        courrant = courrant->prochain;
    }
}

// Liste* lectureAeroports(const char* faeroport)
// {
//     Liste* aeroports = initialiserListe();
//     char iata[4];
//     char ville[50];
//     char pays[50];
//     FILE* file = NULL;
//     file = fopen(faeroport,"r+");
//     if (file == NULL)
//     {
//         printf("\nError: Invalid file!!!\n");
//         exit(EXIT_FAILURE);
//     }
//     while (fscanf(file,"%4s %50s %50s",iata,ville,pays) != EOF)
//     {
//         ajouterElementListe(aeroports,initialiserAeroport(iata,ville,pays));
//     }
//     fclose(file);
//     return aeroports;
// }

int main(int argc, char const *argv[])
{
    Liste* sommets = initialiserListe();
    sommets = lectureSommets("aeroport.txt");
    lectureSuccesseurs("liaisons-new.txt",sommets);
    afficherListe_Sommet(sommets);
    int taille = compterElementListe(sommets);
    int* matrix = calloc(taille*taille,sizeof(int));
    remplirMatrice(matrix,taille);
    afficherMatrice(matrix,taille);
    printf("\n-------------------------------------\n");
    remplirMatriceGraph(sommets,matrix,taille);
    return 0;
}



#endif // !AEROPORT_C