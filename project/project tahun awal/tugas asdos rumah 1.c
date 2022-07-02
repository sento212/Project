#include<stdio.h>
int main()
{
    int n=4,i,j,k,l,m,s;

    for(i=0; i<=n; i++)
    {
        for(j=0;j<n-1;j++)

            printf(" ");

          for(j=0;j<n;j++)
            printf("|");
           printf("\n");
    }

for(k=1; k<=n;k++)
{
    for(l=n;l>k;l--)
        printf(" ");
        for(l=0;l<n*3;l++)
            printf("H");
        for(l=0;l<k;l++)
        printf("*");
         for(l=1;l<k;l++)
        printf("*");
 printf("\n");
}
for(m=0;m<=n;m++)
{
    for(s=0;s<n*3;s++)
        printf("H");
         for(s=0;s<n*2-1;s++)
            printf("F");
       printf("\n");
}

}
