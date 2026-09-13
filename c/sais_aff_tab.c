#include <stdio.h>

void saisir_Tableau(int tab[], int taille) {
    printf("Saisie du tableau :\n");
    for (int i = 0; i < taille; i++) {
        printf("Élément %d : ", i + 1);
        scanf("%d", &tab[i]);
    }
}

void afficher_Tableau(int tab[], int taille) {
    printf("Contenu du tableau :\n");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
}

int main() {
    int TAILLE=0;
    printf("taille du tableau :");
    scanf("%d",&TAILLE);
    int monTableau[TAILLE];
    saisir_Tableau(monTableau, TAILLE);
    afficher_Tableau(monTableau, TAILLE);
    return 0;
}