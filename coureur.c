#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef COUREUR
#include "coureur.h"
#endif

coureur* creer_coureur(char nom[], char prenom[], int num, char equipe[], int temps){
  coureur *c;
  c = malloc(sizeof(coureur));
  strcpy(c->nom, nom);
  strcpy(c->prenom, prenom);
  c->dossard = num;
  strcpy(c->equipe, equipe);
  c->temps = temps;
  return c;
}

void ajouter_temps(coureur * c, int tempssup){

  c->temps = c->temps + tempssup;
}

void afficher_coureur(coureur * c){

  int heure,min,sec, reste;
  heure = c->temps / 3600;
  reste = c->temps % 3600;
  min = reste / 60;
  reste = reste % 60;
  sec = reste;

  printf("Nom du coureur : ");
  printf("%s\n", c->nom);
  printf("Prenom du coureur : ");
  printf("%s\n", c->prenom);
  printf("N°du dossard : ");
  printf("%d\n", c->dossard);
  printf("Equipe du coureur : ");
  printf("%s\n", c->equipe);
  printf("Temps : %d h %d min %d s\n", heure,min,sec);
}

/*
int main(){
  coureur *c1, *c2, *c3;
  c1 = creer_coureur("Hinault", "Bernard", 51, "BON", 19815);
  c2 = creer_coureur("Armstrong", "Lance", 103, "GOOD", 20710);
  c3 = creer_coureur("Monteil", "Thierry", 12, "CUIT", 181202);
  afficher_coureur(c1);
  afficher_coureur(c2);
  afficher_coureur(c3);
  ajouter_temps(c1, 15);
  afficher_coureur(c1);
  return 0;
}
*/
