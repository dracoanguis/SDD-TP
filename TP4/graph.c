#include <string.h>
#include "graph.h"
#include "liste.c"
#define memoryTest(pointeur) if (pointeur == NULL){printf("\nMemory allocation Failure !\n");exit(EXIT_FAILURE);}
#define nomSom(Sommet) Sommet->aeroport->iata
#define nomSuc(Successeur) Successeur->nomSom(sommet_representer)
#define coutSuc(Successeur) Successeur->cout
#define True 1
#define False 0

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

//Sommet:

Sommet* initialiserSommet(Aeroport* aeroport,Liste* successeurs)
{
    if (aeroport == NULL)
    {
        printf("\nError: Assigning a NULL Aeroport to Sommet !\n");
        exit(EXIT_FAILURE);
    }

    Sommet* nouveau = malloc(sizeof(Sommet));
    memoryTest(nouveau);

    nouveau->aeroport = aeroport;
    nouveau->liaisons = successeurs;
    nouveau->marque = 0;

    return nouveau;
}

void afficherSommet(Sommet* sommet)//Il faut definir une fonction d'affichage de liste de successeur d'abord.
{
    if (sommet == NULL)
    {
        printf("\nError: Trying to print an non-existant Sommet !\n");
        exit(EXIT_FAILURE);
    }


}

Sommet* chercherSommet_Successeur(Liste* liste_sommet,char* nom)
{
    if (liste_sommet == NULL || liste_sommet->premier == NULL)
    {
        printf("\nError: non-existing or empty search list !\n");
        exit(EXIT_FAILURE);
    }

    Element* courrant = liste_sommet->premier;
    Sommet* som_courrant = courrant->data;

    while (courrant != NULL && strstr(nom,nomSom(som_courrant)) == NULL)
    {
        courrant = courrant->prochain;
        som_courrant = courrant->data;
    }

    if (courrant == NULL)
    {
        printf("\nError: Can't find Sommet in list !\n");
        exit(EXIT_FAILURE);
    }
    
    return courrant->data;
}

//Successeur:
Successeur* initialiserSuccesseur(Sommet* sommet, int cout)
{
    if (sommet == NULL)
    {
        printf("\nError: Assigning a NULL Sommet to Successeur !\n");
        exit(EXIT_FAILURE);
    }

    Successeur* nouveau = malloc(sizeof(Successeur));
    memoryTest(nouveau);

    nouveau->sommet_representer = sommet;
    nouveau->cout = cout;

    return nouveau;
}    

void afficherSuccesseur(Successeur* successeur)
{
    if (successeur == NULL)
    {
        printf("\nError: Trying to print a non-existing Successeur !\n");
        exit(EXIT_FAILURE);
    }

    printf("\n");
    printf("Sommet representer: %s\n",nomSuc(successeur));
    printf("Cout du deplacement: %d\n",coutSuc(successeur));
}

Successeur* lectureBlocSuccesseur(char* bloc, Liste* liste_sommet)
{
    char* nom = NULL;
    char* cout = NULL;
    Successeur* retour = NULL;
    int icout = 0;

    // nom = strtok(bloc,"."); Fonctionne pas: Segmentation Fault 
    // cout = strtok(NULL,".");
    cout = (strchr(bloc,'.'));
    nom = bloc;

    if (cout != NULL)
    {
        icout = ((int)strtol((cout + sizeof(char)),NULL,10));
    }

    retour = initialiserSuccesseur(chercherSommet_Successeur(liste_sommet,nom),icout);

    if (retour == NULL)
    {
        printf("\nError: Can't initiate Successeur from bloc !\n");
        exit(EXIT_FAILURE);
    }
    
    return retour;
}

//Autre:

Liste* lectureAeroports(const char *faeroport)
{
    Liste* aeroports = initialiserListe();
    char iata[4];
    char ville[50];
    char pays[50];
    FILE* file = NULL;
    file = fopen(faeroport,"r+");
    if (file == NULL)
    {
        printf("\nError: Invalid file!!!\n");
    }
    while (fscanf(file,"%4s %50s %50s",iata,ville,pays) != EOF)
    {
        ajouterElementListe(aeroports,initialiserAeroport(iata,ville,pays));
    }
    fclose(file);
    return aeroports;
}

int main() {
    //Liste* aeroports = initialiserListe();
    //aeroports = lectureAeroports("aeroport.txt");
    Sommet* lhr = initialiserSommet(initialiserAeroport("LHR", "Londres", "Royaume-Uni"),NULL);
    Liste* liste_Sommet = initialiserListe();
    ajouterElementListe(liste_Sommet,lhr);
    Successeur* succ = lectureBlocSuccesseur("LHR",liste_Sommet);
    afficherSuccesseur(succ);
    return 0;
}