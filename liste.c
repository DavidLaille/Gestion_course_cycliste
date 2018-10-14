#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef LISTE
#include "liste.h"
#endif

#ifndef COUREUR
#include "coureur.h"
#endif

void creer_liste(liste * liste){
  liste->premier = malloc(sizeof(cellule));
  liste->courant = liste->premier;
  liste->dernier = liste->premier;
}

void ajouter_coureur_fin(liste * liste, coureur * coureur){
  if (liste->dernier == liste->premier){
    liste->dernier->coureur = malloc(sizeof(coureur));
    strcpy(liste->dernier->coureur->nom, coureur->nom);
    strcpy(liste->dernier->coureur->prenom, coureur->prenom);
    liste->dernier->coureur->dossard = coureur->dossard;
    strcpy(liste->dernier->coureur->equipe, coureur->equipe);
    liste->dernier->coureur->temps = coureur->temps;
    liste->dernier = liste->dernier->suiv;

  }
  else{
    liste->dernier->suiv = malloc(sizeof(cellule));
    liste->dernier->suiv->coureur = malloc(sizeof(coureur));
    strcpy(liste->dernier->suiv->coureur->nom, coureur->nom);
    strcpy(liste->dernier->suiv->coureur->prenom, coureur->prenom);
    liste->dernier->suiv->coureur->dossard = coureur->dossard;
    strcpy(liste->dernier->suiv->coureur->equipe, coureur->equipe);
    liste->dernier->suiv->coureur->temps = coureur->temps;
    liste->dernier = liste->dernier->suiv;
  }
}


void aller_debut(liste * liste){
  liste->courant = liste->premier;
}

void avancer(liste * liste){
  liste->courant = liste->courant->suiv;
}

void fin(liste * liste){
  liste->courant = liste->dernier;
}

coureur* retourner_courant(liste * liste){
  return (liste->courant->coureur);
}

void effacer_coureur(liste * liste ){
  cellule * aux = liste->premier;
  if(liste->premier == liste->courant){
    liste->premier = liste->premier->suiv;
    free(liste->courant);
  }
  else{
    while(aux->suiv != liste->courant){
      aux = aux->suiv;
    }
    aux->suiv = liste->courant->suiv;
    free(liste->courant);
  }

    liste->courant = liste->premier;
}

void trier_liste(liste * liste){
  int pasOrdonne = 1;
  cellule * aux = liste->premier;
  coureur * aux2;

  if (liste->premier == NULL){
    printf("La liste à trier est vide\n");
  }
  else{
    while(pasOrdonne){
      pasOrdonne = 0;
      while(aux != liste->dernier){
	if(aux->coureur->temps > aux->suiv->coureur->temps){
	  pasOrdonne = 1;
	  aux2 = aux->coureur;
	  aux->coureur = aux->suiv->coureur;
	  aux->suiv->coureur = aux2;
	}
	aux = aux->suiv;
      }
      aux = liste->premier;
    }
  }
}

void afficher_liste(liste * liste){
  cellule * aux = liste->premier;
  if(liste->premier == NULL){
    printf("La liste est vide.");
  }
  else{
    while(aux != NULL){
      printf("Nom : %s ", aux->coureur->nom);
      printf("Prenom : %s", aux->coureur->prenom);
      printf("N° : %d ", aux->coureur->dossard);
      printf("Equipe : %s", aux->coureur->equipe);
      printf("Temps : %d \n", aux->coureur->temps);
      aux = aux->suiv;
    }
  }
}

/*
int main(){

  liste Liste;
  liste * liste = &Liste;
  creer_liste(liste);
  coureur *c1, *c2, *c3;
  c1 = creer_coureur("Hinault", "Bernard", 51, "BON", 19815);
  c2 = creer_coureur("Armstrong", "Lance", 103, "GOOD", 20710);
  c3 = creer_coureur("Monteil", "Thierry", 12, "CUIT", 181202);
  ajouter_coureur_fin(liste,c1);
  afficher_liste(liste);
  return 0;
}

*/
