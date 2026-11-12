#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct etudiant {
    char Nom[30];
    char cne[10];
    float moyen;
    struct etudiant *suivant;
} etudiant;

etudiant *ajoutEnFin(etudiant *E, char *cne, char *nom, float moyene) {
    etudiant *new = (etudiant *)malloc(sizeof(etudiant));
    if (new == NULL) return E;

    strncpy(new->Nom, nom, sizeof(new->Nom) - 1);
    new->Nom[sizeof(new->Nom) - 1] = '\0';
    strncpy(new->cne, cne, sizeof(new->cne) - 1);
    new->cne[sizeof(new->cne) - 1] = '\0';
    new->moyen = moyene;
    new->suivant = NULL;

    if (E == NULL) return new;

    etudiant *tmp = E;
    while (tmp->suivant != NULL) tmp = tmp->suivant;
    tmp->suivant = new;
    return E;
}
void afficher(etudiant *E) {
    if (E == NULL) {
        printf("la liste est vide\n");
        return;
    }
    while (E != NULL) {
        printf("le nom est %s\t le CNE est %s\t la moyenne est %.2f\n",
               E->Nom, E->cne, E->moyen);
        E = E->suivant;
    }
}

void afficherReussi(etudiant *E) {
    printf("les etudiants reussis :\n");
    while (E != NULL) {
        if (E->moyen > 10)
            printf("le nom est %s\t le CNE est %s\t la moyenne est %.2f\n",
                   E->Nom, E->cne, E->moyen);
        E = E->suivant;
    }
}

etudiant *supprimerTete(etudiant *E) {
    if (E == NULL) return NULL;
    etudiant *tmp = E->suivant;
    free(E);
    return tmp;
}

int nombreEtudiantReussi(etudiant *E) {
    int a = 0;
    while (E != NULL) {
        if (E->moyen > 10) a += 1;
        E = E->suivant;
    }
    return a;
}

int main(void) {
    etudiant *E = NULL;

    E = ajoutEnFin(E, "A123", "Ali", 15.5);
    E = ajoutEnFin(E, "B456", "Sara", 9.0);
    E = ajoutEnFin(E, "C789", "Youssef", 12.0);
    E = ajoutEnFin(E, "D012", "Nadia", 7.5);
    E = ajoutEnFin(E, "BS123", "sara", 14);

    printf("--- Tous les etudiants ---\n");
    afficher(E);

    afficherReussi(E);

    printf("Nombre d'etudiants reussis : %d\n", nombreEtudiantReussi(E));

    E = supprimerTete(E);
    printf("--- Apres suppression de la tete ---\n");
    afficher(E);

    while (E != NULL) E = supprimerTete(E);
    return 0;
}
