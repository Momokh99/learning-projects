#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wchar.h>
typedef struct List List;


struct List{
    int val;
    struct List *suivant;
};


int estvide(List *L){
    if (L == NULL) return 1;
    else return 0;
}

List *Ajouterenfin(List *L, int val){
    List *New=(List*)malloc(sizeof(List));
    New ->val=val;
    New->suivant=NULL;
    if (estvide(L)) return New;
    else{
        List *tmp=L;
        while (tmp->suivant!=NULL) tmp=tmp->suivant;
         tmp=New->suivant;
        }
    return L;
}


List *SuprimerEnFin(List *L){
    if (estvide(L)&&L->suivant==NULL)return NULL;
    List *tmp=L;
    while (tmp->suivant->suivant!=NULL) tmp=tmp->suivant;
    free(tmp->suivant);
    tmp->suivant=NULL;
    return L;
}


void afficherList(List *L){
    if (estvide(L)) printf("la liste est vide");
    else{
        while (L!=NULL) {
        printf("%d\t",L->val);
        L=L->suivant;}}}

List *AjouterAuMilieu(List *L, List *courant, int val){
    List *New=(List*)malloc(sizeof(List));
    New->val=val;
    if (estvide(L)) {
        New->suivant=courant->suivant;
        courant->suivant=New;}
    else {
        New->suivant=NULL;
        return New;}
    return L;
}



int main(){
    List *T=NULL;
    T=Ajouterenfin(T , 4);
    T=Ajouterenfin(T ,-8);
    T=Ajouterenfin(T, -13);
    T=Ajouterenfin(T, 9);
    afficherList(T);
    return 0;
}
