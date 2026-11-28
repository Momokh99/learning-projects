#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct etudiant etudaint   ;
struct etudiant{
    char nom [20];
    float moyenne;
    etudaint *suivant;
    etudaint *precedent;
};

typedef struct cld cld ;
struct cld{
    etudaint *pre;
    etudaint *der;
};

cld *creerListe(){
    cld *start=malloc(sizeof(cld));
    start->pre=NULL;
    start->der=NULL;
    return start;
};

void insererDebut(cld *l,char nom[],float m){
    etudaint *pr=malloc(sizeof(etudaint));
    pr->moyenne=m;
    strcpy(pr->nom, nom);
    pr->precedent=NULL;
    pr->suivant=NULL;
    if (l->pre==NULL) {
        l->pre=pr;
        l->der=pr;
    }
    pr->suivant=l->pre;
    l->pre->precedent=pr;
    l->pre=pr;
}


void insererEnFin(cld *l,char n[],float m){
    etudaint *pr=malloc(sizeof(etudaint));
    pr->moyenne=m;
    strcpy(pr->nom, nom);
    pr->precedent=NULL;
    pr->suivant=NULL;
    if (l->pre==NULL) {
        l->pre=pr;
        l->der=pr;
    }
    pr->suivant=l->der;
    l->der->suivant=pr;
    l->der=pr;
}
