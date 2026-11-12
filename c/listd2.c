#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nom[20];
    float moyy;
    etudient *suiv;
    etudient *prec;
}etudient ;

typedef struct{
    etudient *pr;
    etudient *fin;
} listDetudient;

listDetudient *creerListe(){
    listDetudient *start=malloc(sizeof(listDetudient));
    start->pr=NULL;
    start->fin=NULL;
    return start;
}
void insererDebut(listDetudient *l, char nom[], float m){
    etudient *new=(etudient *)malloc(sizeof(etudient));
    new->moyy=m;
    strcpy(new->nom, nom);
    new->prec=NULL;
    if (l->pr==NULL) {
    l->pr=new;
    l->fin=new;
    }else {
    new->suiv=l->pr;
    l->pr=new;
}}

void insrerFin(listDetudient *l, char n[], float m){
    etudient *new=(etudient *)malloc(sizeof(etudient));
    new->moyy=m;
    strcpy(new->nom, n);
    new->prec=l->fin;
    new->suiv=NULL;
    l->fin=new;
}

void afficherDebut(listDetudient *l){
    etudient *tmp=l->pr;
    while (tmp->suiv!=NULL) {
        printf("le nom : %s\n la maoyyene : %.2f",tmp->nom,tmp->moyy);
        tmp=tmp->suiv;
    }
    free(tmp);
}

void afficherFin(listDetudient *l){
    etudient *tmp=l->fin;
    while (tmp->prec!=NULL) {
        printf("le nom : %s\n la maoyyene : %.2f",tmp->nom,tmp->moyy);
        tmp=tmp->prec;
    }
    free(tmp);
}

void supprimerTete(listDetudient *l){
    etudient *tmp = l->pr;
    l->pr=l->pr->suiv;
    l->pr->prec=NULL;
    free(tmp);
}

void suuprimerQueue(listDetudient *l){
    etudient *tmp = l->fin;
    l->fin=l->fin->prec;
    l->fin->suiv=NULL;
    free(tmp);
}

float moyyeneEtud(listDetudient *l){
    int n=0;
    float s=0;
    etudient *tmp = l->pr;
    while (tmp->suiv!=NULL) {
    n++;
    s+=tmp->moyy;
    tmp=tmp->suiv;
    }
    return s/n;
}
