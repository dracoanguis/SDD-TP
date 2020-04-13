#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Element Element;
struct Element
{
  int presence;//Bool 0 vide, 1 occupé
  Element* suivant;
};

typedef struct File File;
struct File
{
  Element* Premier;
};

File* initialiser()
{
  File* file = malloc(sizeof(File));
  file->Premier = NULL;
  if (file == NULL)
  {
    exit(EXIT_FAILURE);
  } else {return file;}
}

void fileConstruction(File* file, int nombre)
{
  Element *nouveau = malloc(sizeof(*nouveau));
  if (nouveau == NULL) {exit(EXIT_FAILURE);}

  nouveau->presence = nombre;
  nouveau->suivant = NULL;

  if (file->Premier != NULL)
  {
    Element *elementactuel = file->Premier;
    while(elementactuel->suivant != NULL)
    {
      elementactuel = elementactuel->suivant;
    }
    elementactuel->suivant = nouveau;
  } else {
    file->Premier = nouveau;
  }
}

int randomInt(int max)
{
   int nombre = 0;
   const int MIN = 1, MAX = max;
   srand(time(NULL)); // Initialisation de la donnée seed

   nombre = (rand() % (MAX + 1 - MIN)) + MIN; // MIN <= nombre <= MAX
   return nombre;
}

void afficherSalle(File *file)
{
  Element *courrant = file->Premier;
  printf("\n |");
  while(courrant != NULL)
  {
    if (courrant->presence)
    {
      printf("*");
    } else {
      printf("-");
    }
    courrant = courrant->suivant;
  }
  printf("|\n");
}

void destructionSalle(File* file)
{
  while (file->Premier != NULL)
  {
    Element *courrant = file->Premier;
    file->Premier = courrant->suivant;
    free(courrant);
  }
}

int main()
{
  File* salle = initialiser();
  int N = randomInt(25);
  int n = randomInt(N);
  int k = randomInt(50);//A cause de la génération aléatoire il semble que k est tendance a etre le meme chiffre que N.

  printf("\nN = %d \nn = %d\nk = %d\n",N,n,k);

  for (int i = 0; i<n; i++)
  {
    fileConstruction(salle,1);
  }
  for (int i = 0; i<(N - n); i++)
  {
    fileConstruction(salle,0);
  }
  printf("\nSalle au debut:");
  afficherSalle(salle);
  destructionSalle(salle);
  int finSalle = ((k + n)%N);
  if (finSalle == 0)
  {
    for (int i=0; i<N; i++)
    {
      fileConstruction(salle,1);
    }
  } else {
    for (int i=0; i<finSalle; i++)
    {
      fileConstruction(salle, 1);
    }
    for (int i=0; i<(N - finSalle); i++)
    {
      fileConstruction(salle, 0);
    }
  }
  printf("\nSalle a la fin:");
  afficherSalle(salle);
}