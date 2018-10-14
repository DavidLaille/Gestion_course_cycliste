#define TAILLE 20
#define COUREUR

struct Coureur{
  char * nom;
  char * prenom;
  int dossard;
  char * equipe;
  int temps;
};

typedef struct Coureur coureur;

coureur* creer_coureur(char nom[], char prenom[], int num, char equipe[], int temps);
void ajouter_temps(coureur * c, int tempssup);
void afficher_coureur(coureur * c);
