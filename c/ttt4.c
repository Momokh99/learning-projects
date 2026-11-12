

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct individue{
    int matricule;
    char Nom[20];
    float taille;
}individue;

typedef struct List{
    individue individue;
    struct List *nxt;
}List;

int existe(List *Tete, int matricule){
    while (Tete!=NULL) {
        if (Tete->individue.matricule == matricule) return 1;
        Tete=Tete->nxt;
    }
    return 0;
}

List* AjoutEnTete(List *Tete, individue ind) {
    if (existe(Tete, ind.matricule)) return Tete;
    List *NE = malloc(sizeof(List));
    if (NE == NULL) return Tete;
    NE->individue = ind;
    NE->nxt = Tete;
    return NE;
}

void afficher(List *E){
    while (E != NULL) {
        printf("la matricule %d\t le Nom \t%s la taille \t %f\n", E->individue.matricule,E->individue.Nom,E->individue.taille);
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
        somme+=tete->individue.taille;
        tete=tete->nxt;
    }return somme/n;
}

int main(void) {
    List *tete = NULL;
    int n, m;
    individue I;

    printf("entrer le nombre d'individus : ");
    if (scanf("%d", &n) != 1) return 1;

    for (int i = 0; i < n; i++) {
        printf("entrer la matricule : ");
        scanf("%d", &I.matricule);
        printf("entrer le nom : ");
        scanf("%19s", I.Nom);
        printf("entrer la taille : ");
        scanf("%f", &I.taille);
        tete = AjoutEnTete(tete, I);
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
