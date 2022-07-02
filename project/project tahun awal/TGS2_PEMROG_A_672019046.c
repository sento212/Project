#include<stdio.h>
#include<conio.h>
#include<windows.h>
int main(void)
{
    int pilihan;
     int n,i,j,k,l,m,s,p=4;
     char o,z;
    do
    {
        menu:
            printf("\n");
        printf("=====Menu pilihan=====\n");
        printf("1.Rumah\n");
        printf("2.Arah Jalan\n");
        printf("3.Keluar\n");
        printf("Masukan Pilihan : ");
        scanf("%i",&pilihan);
        switch(pilihan)
        {
        case 1:

            printf("masukan tinggi rumah =");
            scanf("%d",&n);
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
printf("apakah mau dibalik y/t ?");
o=getche();
if(o=='y')
{
printf("\n");

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
else if(o=='t')
{
    goto menu;
}
break;
case 2:
printf("pilih membuat jalan\n");
printf("1.jalan lurus\n");
printf("2.jalan kanan\n");
printf("3.jalan kiri\n");
printf("mau jalan kemana:");
z=getche();
if(z=='1')
{ printf("\n");
      for(i=0;i<=p;i++)
{
    for(j=0;j<=p-4;j++)
     printf("     |");
    for(j=0;j<=p-4;j++)
     printf(" ");
      for(j=0;j<=p-4;j++)
     printf(" |");
       for(j=0;j<=p-4;j++)
     printf("  |");
     printf("\n") ;
   {
    for(j=0;j<=p-4;j++)
     printf("     |");
       for(j=0;j<=p-4;j++)
     printf("     ");
       for(j=0;j<=p-4;j++)
        printf("|");
    for(j=0;j<=p-4;j++)
     printf("\n");
   }
}
printf("Ini Arah Jalan");
}
else if(z=='2')
{
    printf("\n");
     for(i=0;i<=p;i++)
    {
        for(j=12;j>i*2;j--)
            printf(" ");
for(j=0;j<=p-4;j++)
     printf("  /");
    for(j=0;j<=p-4;j++)
     printf(" ");
      for(j=0;j<=p-4;j++)
     printf(" /");
       for(j=0;j<=p-4;j++)
     printf("  /");
     printf("\n") ;
   {
        for(j=11;j>i*2;j--)
            printf(" ");

    for(j=0;j<=p-4;j++)
     printf("  /");
       for(j=0;j<=p-4;j++)
     printf("     ");
       for(j=0;j<=p-4;j++)
        printf("/");
    for(j=0;j<=p-4;j++)
     printf("\n");
}
}
printf("Ini Arah Jalan");
}
else if(z=='3')
{
    printf("\n");
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
printf("Ini Arah Jalan");
}
break;
case 3:
break;
default : goto menu;
}
}
while(pilihan!=3);
}
