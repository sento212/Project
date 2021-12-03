#include<stdio.h>
int main()
{
   int n,i,j,k,l,m,s;
   printf("masukan tinggi");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       for(j=0 ;j<n*4-1;j++)
        printf(" ");
            for(j=0 ;j<n;j++)
        printf("|");
       printf("\n");
   }
    for(k=0;k<n;k++)
    {
        for(i=n;i>k+1;i--)
            printf(" ");
        for(i=0;i<=k;i++)
        printf("*");
          for(i=1;i<=k;i++)
        printf("*");
        for(i=0;i<=n*4-2;i++)
        printf("H");
            printf("\n");
    }
    for(m=0;m<n;m++)
    {
        for(s=0;s<n*2-1;s++)
            printf("F");
              for(s=0;s<n*4-1;s++)
            printf("H");
        printf("\n");
    }
}
