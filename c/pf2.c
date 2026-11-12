#include <stdio.h>
#include <stdlib.h>
typedef struct element element ;
struct element{
    int num;
    element *sui;
};
typedef struct{element *tete;}file;

file *initialiser(){
    file *first=malloc(sizeof(file));
    if (first == NULL) return NULL;
    first->tete=NULL;
    return first;
}

int estVid(file *f){
    if (f->tete==NULL) return 1;
    else return 0;
}

file *enfiler(file *f, int n){
    element *ne=malloc(sizeof(element));
    if (ne == NULL) return f;
    ne->num=n;
    ne->sui=NULL;
    if (!estVid(f)) {
        element *tmp=f->tete;
        while (tmp->sui !=NULL){tmp=tmp->sui;}
        tmp->sui=ne;
    }else {
        f->tete=ne;
    }return f;
}

int defiler(file *f){
    if (f->tete!=NULL) {
int n;
element *tmp =f->tete;
f->tete=tmp->sui;
n=tmp->num;
free(tmp);
return n;
    }
    return -1;
}

int main(void){
    file *f=initialiser();
    if (f == NULL) return 1;

    printf("file vide ? %s\n", estVid(f) ? "oui" : "non");

    for (int i = 1; i <= 5; i++) {
        f=enfiler(f, i * 10);
        printf("enfiler %d -> tete=%d\n", i * 10, f->tete->num);
    }

    while (!estVid(f)) {
        printf("defiler %d\n", defiler(f));
    }

    printf("file vide ? %s\n", estVid(f) ? "oui" : "non");
    free(f);
    return 0;
}
