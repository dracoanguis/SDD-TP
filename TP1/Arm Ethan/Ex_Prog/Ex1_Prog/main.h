#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED


typedef struct Personne Personne;
struct Personne
{
    char nom[20];
    char prenom[20];
    char addresse[100];
    char telephone[15];//Stocké comme text
};

typedef struct Voiture Voiture;
struct Voiture
{
    char immatriculation[30];
    char marque[20];
    char modele[20];
    /*Personne proprietaire; Plus besoin car le propriétaire est stocké dans une autre liste au même numéro que l'emplacement de la voiture*/
    int repare;//Bool 1 réparée, 0 pas réparée
    unsigned int emplacement; //Place numéroté a partir de 1, 0 est un emplacemant spécialpour opérer les déplacements
    /*L'emplacement sert a sélectionné les voitures.*/
    char etat[300];//Commentaire sur les réparation, pièce nécessaire,...
};

void initialisationRepertoire();//Liste des client, accès par modification des voitures (ne peut exister sans une voiture associé)
void initialisationParking();//Liste des voitures
Voiture* selecteurVoiture(int mode);
int verificateurDispEmplacement(unsigned int emplacement);

void ajoutDeVoiture(Voiture *voitureDonnee,char marqueDonnee[20],char modeleDonnee[20]);
void changerImmatriculation(Voiture *voitureDonnee);
void changerRepare(Voiture *voitureDonnee);
void changerEmplacement(Voiture *voitureDonnee);
void changerEtat(Voiture *voitureDonnee);
void changerMarque(Voiture *voitureDonnee);
void changerModele(Voiture *voitureDonnee);
void supprimerVoiture(Voiture *voitureDonnee);
void afficherVoiture(Voiture *voitureDonnee);
void afficherParking();//Affiche la liste des voiture présente

void ajoutDePersonne(Personne *personneDonnee,char nomDonnee[20],char prenomDonnee[20]);
void modifierPersonne(Personne *personneDonnee);
void supprimerPersonne(Personne *personneDonnee);
void afficherPersonne(Personne *personneDonnee);

int demandeChoix();
void menuPrincipal();
void menuModificationVoiture(Voiture *voitureDonnee);

#endif