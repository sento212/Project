#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    /*int a,b,c=0;
    printf("masukan data: ");
    scanf("%i",&a);
    int tinggi[a];
    for(b=0;b<a;b++)
    {
        printf("tinggi ke %i= ",b);
        scanf("%i",&tinggi[b]);
    }
      for(b=0;b<a;b++)
      {
c = c + tinggi[b];

      }
printf("hasil penjumahan = %i",c);*/
/*
int a,b,i,j ;
printf("masukan tinggi : ");
scanf("%d",&a);
printf("masukan kolom : ");
scanf("%d",&b);
int matriks[a][b];
for(i=0;i<a;i++)
{
    for(j=0;j<b;j++)
    {
        printf("masukan indeks %i %i",i,j);
        scanf("%i",&matriks[i][j]);
    }
}
for(i=0;i<a;i++)
{
    for(j=0;j<b;j++)
    {
        printf("%d ",matriks[i][j]);

    }
   printf("\n");
}
*/
char a[100],i;
printf("masukan nama : ");
scanf("%[^\n]",&a);
for(i<=strlen(a)-1;i>=0;i--)
printf("%c",a[i]);

}

