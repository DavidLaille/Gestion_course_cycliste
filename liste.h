#define LISTE

#ifndef COUREUR
#include "coureur.h"
#endif

struct cellule{
  coureur * coureur;
  struct cellule * suiv;
};

typedef struct cellule cellule;

struct liste{
  cellule * premier;
  cellule * courant;
  cellule * dernier;
};

typedef struct liste liste;

void creer_liste(liste * liste);
void ajouter_coureur_fin(liste * liste, coureur * coureur);
void aller_debut(liste * liste);
void avancer(liste * liste);
void fin(liste * liste);
coureur* retourner_courant(liste * liste);
void effacer_coureur(liste * liste);
void trier_liste(liste * liste);
void afficher_liste(liste * liste);
