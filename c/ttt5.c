#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct poly{
    int puissance_inconue;
    float coefficient_element;
    struct poly *nxt;
}poly ;

poly* saisiPolynome(poly *P){
    int max;
    printf("le maximum puissance est ");
    scanf("%d",&max);

    poly *tail = P;
    while (tail != NULL && tail->nxt != NULL) tail = tail->nxt;

    for (int i =0; i<=max; i++) {
        poly *NE =(poly *)malloc(sizeof(poly));
        if (NE == NULL) return P;
        NE->puissance_inconue=i;
        printf("le coefficient de l'element de puissance %d est ",i);
        scanf("%f",&NE->coefficient_element);
        NE->nxt=NULL;
        if (P==NULL) {
            P=NE;
        }else {
            tail->nxt=NE;
        }
        tail=NE;
    }
    return P;
}


float valPoly(poly *p,float x){
    float v=0;
    while (p!=NULL) {
        v+=p->coefficient_element*pow(x, p->puissance_inconue);
        p=p->nxt;
    }return v;
}

void afficher(poly *p){
    while (p!=NULL) {
        if (p->puissance_inconue==0) {
            printf("%.2f",p->coefficient_element);
        }
        else {
        printf("+ %.2fx^%d",p->coefficient_element,p->puissance_inconue);
            }
        p=p->nxt;
    }
    printf("\n");
}
int main(void){
    poly *polynome = NULL;
    polynome = saisiPolynome(polynome);

    printf("polynome : ");
    afficher(polynome);

    float x;
    printf("entrer la valeur de X ");
    scanf("%f",&x);
    printf("la valeur du polynome en %.2f est %.2f\n",x,valPoly(polynome, x));

    while (polynome != NULL) {
        poly *tmp = polynome->nxt;
        free(polynome);
        polynome = tmp;
    }
    return 0;
}
