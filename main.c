#include<stdio.h>
#include<stdlib.h>
#include"fun.h"
int main(void) {
 int ** a = NULL, str, col, i, j, err, x;
 err=Input("data.dat",&a,&str,&col);
 if(err) printf("Error\n");
 else {
  x=Check(a,str,&col);
  printf("x=%d\n",x);
  if(x == -1) return -3;
  for(i = 0;i < str;i ++)
   for(j = 0;j  < col;j++) {
     printf("%d ",a[i][j]);
     if(j == col - 1) printf("\n");
    }
  free(a); a=NULL;
  return 0;
 }
}
