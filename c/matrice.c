#include <stdint.h>
#include <stdio.h>
typedef struct {
  uint32_t row,col;
  float *data;
} Mat;

void mat_print(Mat a){
  for (int i=0;i<a.col;++i) {
      for (int j=0; j < a.row; ++j) {
          printf("%f\t",a.data[i]);
      }
      printf("\n");
  }
}

int main(int argc, char *argv[])
{
    Mat a = {.col=2,.row=2,.data=(float[]){1,2,3,4}};
    mat_print(a);
  return 1;
}
