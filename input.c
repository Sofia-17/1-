#include<stdio.h>
#include<stdlib.h>
#include"fun.h"

int Input(const char *fn, int ***a, int *m, int *n) {
 int i,j; FILE *f;
 f=fopen(fn, "r");
 if(f==NULL) return -1;
 if(fscanf(f,"%d",m)!=1) {
   fclose(f);
   return-2;
  }
 if(fscanf(f,"%d",n)!=1) {
  fclose(f);
  return -3;
 }
 *a=(int**)malloc((*m)*sizeof(int*)+(*m)*(*n)*sizeof(int));
 if(*a==NULL) {
  fclose(f);
  return -4;
 }
 (*a)[0]=(int*)(*a+*m);
 for(i=1;i<*m;i++)
  (*a)[i]=(*a)[i-1]+*n;
 for(i=0;i<*m;i++)
  for(j=0;j<*n;j++)
   if(fscanf(f,"%d",(*a)[i]+j)!=1) {
    fclose(f);
    free(*a);
    *a=NULL;
    return -5;
   }
 fclose(f);
 return 0;
}
