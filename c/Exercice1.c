#include <stdio.h>
#include <stdlib.h>

typedef struct List List;

struct List {
    int val;
    struct List *suivant;
};

int estvide(List *L) {
    if (L == NULL) return 1;
    else return 0;
}

List *Ajouterenfin(List *L, int val) {
    List *New = (List *)malloc(sizeof(List));
    if (New == NULL) return L;
    New->val = val;
    New->suivant = NULL;

    if (estvide(L)) return New;

    List *tmp = L;
    while (tmp->suivant != NULL) tmp = tmp->suivant;
    tmp->suivant = New;
    return L;
}

List *SuprimerEnFin(List *L) {
    if (estvide(L)) return NULL;
    if (L->suivant == NULL) {
        free(L);
        return NULL;
    }
    List *tmp = L;
    while (tmp->suivant->suivant != NULL) tmp = tmp->suivant;
    free(tmp->suivant);
    tmp->suivant = NULL;
    return L;
}

void afficherList(List *L) {
    if (estvide(L)) printf("la liste est vide\n");
    else {
        while (L != NULL) {
            printf("%d\t", L->val);
            L = L->suivant;
        }
        printf("\n");
    }
}

/* Insere "val" apres l'element "courant".
   Si "courant" est NULL, l'insertion se fait en tete. */
List *AjouterAuMilieu(List *L, List *courant, int val) {
    List *New = (List *)malloc(sizeof(List));
    if (New == NULL) return L;
    New->val = val;

    if (courant == NULL) {
        New->suivant = L;
        return New;
    }

    New->suivant = courant->suivant;
    courant->suivant = New;
    return L;
}

void libererList(List *L) {
    while (L != NULL) {
        List *tmp = L->suivant;
        free(L);
        L = tmp;
    }
}

int main(void) {
    List *T = NULL;

    T = Ajouterenfin(T, 4);
    T = Ajouterenfin(T, -8);
    T = Ajouterenfin(T, -13);
    T = Ajouterenfin(T, 9);

    printf("Liste initiale : ");
    afficherList(T);

    /* Insertion de 25 apres le deuxieme element (-8) */
    T = AjouterAuMilieu(T, T->suivant, 25);
    printf("Apres ajout au milieu : ");
    afficherList(T);

    /* Insertion en tete */
    T = AjouterAuMilieu(T, NULL, 100);
    printf("Apres ajout en tete : ");
    afficherList(T);

    T = SuprimerEnFin(T);
    printf("Apres suppression en fin : ");
    afficherList(T);

    libererList(T);
    return 0;
}
