#include<stdio.h>
int main()
{
  int n,k,l;
printf("masukan tinggi ");
scanf("%d",n);
for(k=1; k<=n;k++)
{
    for(l=n;l>k;l--)
    {


        printf("*");
    }
 printf("\n");
}
}
