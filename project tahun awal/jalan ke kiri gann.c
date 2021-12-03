#include<stdio.h>
int main()
{
   int p=4,i,j;
    for(i=0;i<=p;i++)
    {
    for(j=0;j<i*2;j++)
        printf(" ");

      for(j=0;j<=p-4;j++)
     printf("     \\");
    for(j=0;j<=p-4;j++)
     printf(" ");
      for(j=0;j<=p-4;j++)
     printf(" \\");
       for(j=0;j<=p-4;j++)
     printf("  \\");
     printf("\n") ;
   {
       for(j=-1;j<i*2;j++)
        printf(" ");

    for(j=0;j<=p-4;j++)
     printf("     \\");
       for(j=0;j<=p-4;j++)
     printf("     ");
       for(j=0;j<=p-4;j++)
        printf("\\");
    for(j=0;j<=p-4;j++)
     printf("\n");
   }



}
}
