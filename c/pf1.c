#include <stdio.h>
#include <stdlib.h>
typedef struct element element ;
struct element{
    int num;
    element *sui;
};
typedef struct{element *tete;}pile;

pile *initialiser(){
    pile *first=malloc(sizeof(pile));
    if (first == NULL) return NULL;
    first->tete=NULL;
    return first;
}

int estValide(pile *p){
    if (p->tete==NULL)return 1;
    else return 0;
}

int sommet(pile *p){
    if (!estValide(p)) return p->tete->num;
    else return -1;
}

int taille(pile *p){
    int n=0;
    element *tmp=p->tete;
    while (tmp!=NULL) {
n++;
tmp=tmp->sui;
    }return n;
}

pile *empiler(pile *p, int n){
    element *first=malloc(sizeof(element));
    if (first == NULL) return p;
    first->num=n;
    first->sui=p->tete;
    p->tete=first;
    return p;
}

int depiler(pile *p){
    if (p == NULL || p->tete == NULL) return -1;
    int n;
    element *tmp=p->tete;
    p->tete=tmp->sui;
    n=tmp->num;
    free(tmp);
    return n;
}

int main(void){
    pile *p=initialiser();
    if (p == NULL) return 1;

    printf("pile vide ? %s\n", estValide(p) ? "oui" : "non");

    for (int i = 1; i <= 5; i++) {
        p=empiler(p, i * 10);
        printf("empiler %d -> taille=%d sommet=%d\n", i * 10, taille(p), sommet(p));
    }

    while (!estValide(p)) {
        printf("depiler %d\n", depiler(p));
    }

    printf("pile vide ? %s\n", estValide(p) ? "oui" : "non");
    free(p);
    return 0;
}
