#include <stdint.h>
#include <stdio.h>
int main(){
int somm=0;
int T[2][2];
int i,j;
for (i=0; i<2; i++) {
    for (j=0; j<2; j++) {
        printf("enter T[%d][%d] :",i,j);
        scanf("%d",&T[i][j]);
        somm=T[i][j]+somm;
    }
}
printf("la somme de matrice egale a :%d",somm);

}