
#include <stdlib.h>
typedef struct {
    int num;
    struct Element *suiv;
    struct Element *preced;
}Element ;

typedef struct{
    Element *pr;
    Element *der;
}LDC ;

void ajouyDebut(LDC *l,int val){
    Element *NE=(Element *)malloc(sizeof(Element));
    NE->num=val;
    NE->preced=NULL;
    NE->suiv=NULL;
    if (l->pr==NULL) {
        l->pr=NE;
        l->der=NE;
    }else {
        NE->suiv=l->pr;


    }

}
