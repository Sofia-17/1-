#include<stdlib.h>
#include<stdio.h>
#include"fun.h"
int Check(int **a, int str, int (*col)) {
 int i,j,x,xs;
 if (a == NULL)
 return -1;
 else {
 xs=a[0][0];
 for(i = 1;i < (*col);i++)
  if(xs < a[0][i]) {xs = a[0][i]; x = i;}

 for(i = 1;i < str;i++)
  for(j = 0;j < (*col);j++) {
   if(j == x) continue;
   if(a[i][x] <= a[i][j]) return -2;
  }
 (*col)--;
  for( j = 0;j < str;j++)
  for(i = x;i < (*col);i++) {
   a[j][i] = a[j][i + 1]; 
  }
 }
   return 0;
}
