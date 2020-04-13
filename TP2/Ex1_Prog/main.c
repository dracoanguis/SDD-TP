#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nom
{
  char nom[50];
} Nom;

typedef struct Element
{
  Nom nom;
  struct Element * next;
} Element;

typedef struct Pile
{
  Element *first;
}Pile;

void Push(Pile *pile, char nvNom[50])
{
  Element *nouveau = malloc(sizeof(*nouveau));
  if (pile == NULL || nouveau == NULL)
  {
    exit(EXIT_FAILURE);
  }
  strcpy(nouveau->nom.nom,nvNom);
  nouveau->next = pile->first;
  pile->first = nouveau;
}

Nom Pop(Pile *pile)
{
  if (pile == NULL)
  {
    exit(EXIT_FAILURE);
  }
  Nom nom = {""};
  Element *supprimer = pile->first;

  if(pile != NULL && pile->first != NULL)
  {
    strcpy(nom.nom,supprimer->nom.nom);
    pile->first = supprimer->next;
    free(supprimer);
  }
  return  nom;
}

char * suppressEnter(char text[])
{
  char * position = NULL;
  position = strchr(text, '\n');
  if (position != NULL)
  {
    *position = '\0';
  }
  return text;
}

int pileVide(Pile * pile)//return 0 si vide, 1 sinon
{
  if (pile->first == NULL)
  {
    return 0;
  }
  return 1;
}

int demandeChoix(Nom nom)//return 1 si oui, 0 si non (bool)
{
    char choix[10];
    do
    {
        printf("\nAvez vous valider la tache: %s ? oui/non\n",nom.nom);
        fgets(choix,10,stdin);
        choix[strlen(choix)-1] ='\0';
        if (!(strcmp(choix,"oui"))) {return strcmp(choix,"non");};
    } while (strcmp(choix,"non"));
    return strcmp(choix,"non"); 
}

void testTache(Pile *pile)
{
  while (pileVide(pile))
  {
    Nom tacheActu = Pop(pile);
    while (!(demandeChoix(tacheActu)));
  }
}

int main(void)
{
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    Pile listeTacheCour = {NULL};

    fp = fopen("checklist.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
      char *categorie = NULL;
      char *nom = NULL;
      categorie = strtok(line, ",");//Le reste passe dans le buffer
      nom = strtok(NULL, ",");//Reste de la ligne
      nom = suppressEnter(nom);
      
      if (!(strcmp(categorie, "tache")))
      {
        Push(&listeTacheCour,nom);
      }

      if ((strcmp(categorie, "tache")))
      {
        testTache(&listeTacheCour);
      }

      if (!(strcmp(categorie, "sous-categorie")))
      {
        printf("  - sous-categorie : %s\n",nom);
      }

      if (!(strcmp(categorie,"categorie")))
      {
        printf("La %s est: %s \n",categorie,nom);
      }

    }
    testTache(&listeTacheCour);
    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}