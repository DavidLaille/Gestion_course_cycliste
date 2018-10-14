#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef LISTE
#include "liste.h"
#endif

#ifndef COUREUR
#include "coureur.h"
#endif

int main()
{
  FILE * fich_coureurs;
  fich_coureurs = fopen("fichier_coureurs.txt","r");

  liste Equipes;
  liste * equipes = &Equipes;
  creer_liste(equipes);

  int nb_etapes, nb_equipes, nb_coureurs;
  int i; int j;
  char * nom_equipe; char * nom; char * prenom;
  char * str_dossard; int dossard;
  coureur * cycliste;

  char * ligne=NULL;
  size_t len=0;
  ssize_t lire;

  if (fich_coureurs==NULL) {
    exit(EXIT_FAILURE);
  }
  else{
    lire = getline(&ligne, &len, fich_coureurs);
    ligne = strtok(ligne,"\n");
    int nb_etapes = atoi(ligne);
    printf("Le nombre d'etapes est: %d",nb_etapes);

    lire = getline(&ligne, &len, fich_coureurs);
    ligne = strtok(ligne,"\n");
    int nb_equipes = atoi(ligne);

    for(i=0; i<nb_equipes; i++){
      lire = getline(&ligne, &len, fich_coureurs);
      nom_equipe = strtok(ligne,"\n");
      for(j=0; j<5; j++){
        lire = getline(&ligne, &len, fich_coureurs);
        str_dossard = strtok(ligne,",");
        int dossard = atoi(str_dossard);
        nom = strtok(NULL,",");
        prenom = strtok(NULL,"\n");
        cycliste = creer_coureur(nom, prenom, dossard, nom_equipe, 0);
      }
    }
  afficher_liste(equipes);

  fclose(fich_coureurs);

  }

  return 0;
}

/*int main() {
  struct liste_coureurs* LISTE;
  char fichier_lecture[]="Les equipes";
  char *ligne=NULL;
  size_t len=0;
  ssize_t lire;
  FILE *p_fichier_lecture;
  int i;
  int j;
  char *AUX_DOSSARD;
  char *NOM;
  char *PRENOM;
  char *EQUIPE;
  int temps_ajouter;
  struct coureur* UN_COUREUR;
  LISTE=InitialiserListe();
  p_fichier_lecture=fopen(fichier_lecture,"r");

  if (p_fichier_lecture==NULL) {
    exit(EXIT_FAILURE);
  }

    lire=getline(&ligne, &len, p_fichier_lecture);
    ligne=strtok(ligne,"\n");
    int nombre_etapes = atoi(ligne);
    printf("Le nombre d'etapes est: %d",nombre_etapes);

    lire=getline(&ligne, &len, p_fichier_lecture);
    ligne=strtok(ligne,"\n");
    int nombre_equipes = atoi(ligne);

    for(i=0;i<nombre_equipes;i++){
      lire=getline(&ligne, &len, p_fichier_lecture);
      EQUIPE=strtok(ligne,"\n");
      for(j=0;j<5;j++){
	lire=getline(&ligne, &len, p_fichier_lecture);
        AUX_DOSSARD=strtok(ligne,",");
	int DOSSARD = atoi(AUX_DOSSARD);
	NOM=strtok(NULL,",");
	PRENOM=strtok(NULL,"\n");
	UN_COUREUR=Creer_Coureur(NOM, PRENOM, DOSSARD, EQUIPE, 0);
*/
//////////////////////////////////////////////////////////////////
/* fscanf(fich_coureurs, "%d%d", &nb_etapes, &nb_equipes);
  printf("%d\n", nb_equipes);
  nb_coureurs = 5 * nb_equipes;
  printf("%d\n", nb_coureurs);
  if(nb_equipes == 0){
    printf("Fichier vide ou corrompu");
  }
  while (ligne <= 2){
    while (car_lu != '\n'  && ligne <= 2){
      fseek(fich_coureurs, 1, 1);
	}
    fseek(fich_coureurs, 1, 1);
    ligne ++;
    }
 while(compteur < nb_equipes){
  fgets(nom_equipe, TAILLE, fich_coureurs);
  for(i=1; i<=5; i++){
    while (car_lu != '\n'){
      fseek(fich_coureurs, 1, 1);
	}
    fseek(fich_coureurs, 1, 1);

    fscanf(fich_coureurs, "%d", &dossard);

    courant = nom;
    while((car_lu = getc(fich_coureurs)) != ','){
      if ((car_lu >= 'a' && car_lu <= 'z') || (car_lu >= 'A' && car_lu <= 'Z')){
	*courant++ = car_lu;
      }
    }
    courant = prenom;
    while((car_lu = getc(fich_coureurs)) != '\n'){
      if ((car_lu >= 'a' && car_lu <= 'z') || (car_lu >= 'A' && car_lu <= 'Z')){
	*courant++ = car_lu;
      }
    }
    cycliste = creer_coureur(nom, prenom, dossard,nom_equipe, 0);
    ajouter_coureur_fin(classement, cycliste);
  }
  compteur++;
 }
  */

/*  while(fgets(ligne, TAILLE_MAX, fich_coureurs) != NULL){
    compteur++;
    if (compteur == 1){
        int nb_etapes = atoi(ligne);
    }
    else if (compteur == 2){
        int nb_equipes = atoi(ligne);
    }
    else{
        if ((compteur - 2) % 5 == 0){
            nom_equipe = ligne;
        }
        else{
            str_dossard = strtok(ligne,",");
            int dossard = atoi(str_dossard);
            nom = strtok(NULL,",");
            prenom = strtok(NULL,"\n");
            cycliste = creer_coureur(nom, prenom, dossard, nom_equipe, 0);
        }

    }
  }
*/


























