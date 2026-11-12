#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int val;
    struct element *nxt;
} element;

/* Ajoute l'element "suivant" a la fin de la liste "premier" */
element *inserenFin(element *premier, element *suivant) {
    suivant->nxt = NULL;
    if (premier == NULL) return suivant;

    element *tmp = premier;
    while (tmp->nxt != NULL) tmp = tmp->nxt;
    tmp->nxt = suivant;
    return premier;
}

/* Cree une liste croissante de n elements : 0, 1, ..., n-1 */
element *creerListeCroissante(element *pr, int n) {
    for (int i = 0; i < n; i++) {
        element *tmp = malloc(sizeof(element));
        if (tmp == NULL) return pr;
        tmp->val = i;
        tmp->nxt = NULL;
        pr = inserenFin(pr, tmp);
    }
    return pr;
}

void afficherListe(element *pr) {
    if (pr == NULL) {
        printf("la liste est vide\n");
        return;
    }
    while (pr != NULL) {
        printf("%d\t", pr->val);
        pr = pr->nxt;
    }
    printf("\n");
}

/* Supprime le premier element de la liste */
element *suprimer(element *pr) {
    if (pr == NULL) return NULL;
    element *new = pr->nxt;
    free(pr);
    return new;
}

/* Libere toute la liste */
void libererListe(element *pr) {
    while (pr != NULL) {
        element *tmp = pr->nxt;
        free(pr);
        pr = tmp;
    }
}

int main(void) {
    element *pr = NULL;

    pr = creerListeCroissante(pr, 10);
    printf("Liste : ");
    afficherListe(pr);

    pr = suprimer(pr);
    printf("Apres suppression de la tete : ");
    afficherListe(pr);

    libererListe(pr);
    return 0;
}
