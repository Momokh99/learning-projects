#include <stdio.h>
#include <stdlib.h>

typedef struct ls ls;
struct ls{
    int data;
    ls *suivant;
};

ls *ajoutAuDebut(ls *list,int val){
    ls *Ne =(ls*) malloc(sizeof(ls));
    Ne->data=val;
    Ne->suivant=list;
    return Ne;
}

ls *suprimmerFin(ls *l){
    if (l == NULL) return NULL;
    ls *tmp=l;
    while (tmp->suivant->suivant!=NULL) {tmp=tmp->suivant;}
    free(tmp->suivant);
    tmp->suivant=NULL;
    return l;
}

ls* insererAuFin(ls *tete,int data){
    ls *fin = (ls*)malloc(sizeof(ls));
    fin->data=data;
    fin->suivant=NULL;
    if (tete==NULL) {
        return fin;
    }
    ls* point=tete;
    while (point->suivant!=NULL) {
        point=point->suivant;
    }
    point->suivant=fin;
    return tete;
}

int nbrElement(ls *l){
    int i=0;
    ls *tmp=l;
    while (tmp!=NULL) {
        tmp=tmp->suivant;
        i+=1;
    }return i;
}

int someElement(ls *l){
    int s=0;
    ls *tmp=l;
    while (tmp!=NULL) {
        s+=tmp->data;
        tmp=tmp->suivant;
    }return s;
}

void afficher(ls* tete){
    printf("Liste :\n");
    while (tete!=NULL) {
        printf("%d",tete->data);
        tete=tete->suivant;
    }
}


void librerTout(ls* tete){
    ls* tmp;
    while (tete!=NULL) {
        tmp=tete;
        tete=tete->suivant;
        free(tmp);
    }
}


void affichage(ls *l){
    ls *tmp=l;
    while (tmp!=NULL) {
printf("annee%d\t",tmp->data);
    tmp=tmp->suivant;}
}
