#include <stdio.h>
float valeurabsolue(float);
void bonj(){
    printf("bonjour tous le mond\n");
}
void saisir_return(){
    float x=0;
    printf("entrer une valeur :");
    scanf("%f", &x);
    printf("tu saisie %f \n",x);
}
void affiche_nbr(int a){
    printf("%d",a);
}
int main(){
float x=-5.7,y;
y=valeurabsolue(x);
printf("la valeur absolue de %f est : %f\n",x,y);
bonj();
saisir_return();
affiche_nbr(55);
}
float valeurabsolue(float a){
    if (a<0) a=-a;
    return a;
}