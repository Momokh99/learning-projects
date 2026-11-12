#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct List{
    int matricule;
    char Nom[20];
    float taille;
    struct List *nxt;
}List;

int existe(List *Tete, int matricule){
    while (Tete!=NULL) {
        if (Tete->matricule == matricule) return 1;
        Tete=Tete->nxt;
    }
    return 0;
}

List* AjoutEnTete(List *Tete, int m, char nm[], float t){
    if (existe(Tete, m)) return Tete;
    List *NE=malloc(sizeof(List));
    if (NE == NULL) return Tete;
    NE->matricule=m;
    strncpy(NE->Nom, nm, sizeof(NE->Nom) - 1);
    NE->Nom[sizeof(NE->Nom) - 1] = '\0';
    NE->taille=t;
    NE->nxt=Tete;
    return NE;
}

void afficher(List *E){
    while (E != NULL) {
        printf("la matricule %d\t le Nom \t%s la taille \t %f\n", E->matricule,E->Nom,E->taille);
            E=E->nxt;
    }
}

int nombreIndividue(List *tete){
    int nombre=0;
    while (tete!=NULL) {
        nombre++;
        tete=tete->nxt;
    }return nombre;
}

float MoyenneTaille(List *tete){
    float somme=0;
    int n=nombreIndividue(tete);
    if (n == 0) return 0;
    while (tete!=NULL) {
        somme+=tete->taille;
        tete=tete->nxt;
    }return somme/n;
}

int main(void) {
    List *tete = NULL;
    int n, m;
    char nom[20];
    float taille;

    printf("entrer le nombre d'individus : ");
    if (scanf("%d", &n) != 1) return 1;

    for (int i = 0; i < n; i++) {
        printf("entrer la matricule : ");
        scanf("%d", &m);
        printf("entrer le nom : ");
        scanf("%19s", nom);
        printf("entrer la taille : ");
        scanf("%f", &taille);
        tete = AjoutEnTete(tete, m, nom, taille);
    }

    printf("--- liste ---\n");
    afficher(tete);

    printf("entrer la matricule a rechercher : ");
    scanf("%d", &m);
    if (existe(tete, m)) printf("existe\n");
    else printf("n'existe pas\n");

    printf("le nombre d'individus est %d\n", nombreIndividue(tete));
    printf("la moyenne des tailles est %.2f\n", MoyenneTaille(tete));

    while (tete != NULL) {
        List *tmp = tete->nxt;
        free(tete);
        tete = tmp;
    }
    return 0;
}
