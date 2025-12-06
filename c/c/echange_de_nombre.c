#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    int x,y;
    printf("entrer x :");
    scanf("%d",&x);
    printf("entrer y :");
    scanf("%d",&y);
    printf("Avant l'échange : x = %d, y = %d\n", x, y);

    swap(&x, &y);

    printf("Après l'échange : x = %d, y = %d\n", x, y);

    return 0;
}
