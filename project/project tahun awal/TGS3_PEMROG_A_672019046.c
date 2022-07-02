#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
int main()
{
    int a,b,i,j,kode;
    char o;
menu :
printf("masukan baris : ");
scanf("%d",&a);
printf("masukan kolom : ");
scanf("%d",&b);
int matriks [a][b],matriks2 [a][b],f [a][b];
for(i=0;i<a;i++)
{
    for(j=0;j<b;j++)
    {
        printf("masukan matriks 1 indeks %i %i ",i,j);

        scanf("%i",&matriks[i][j]);

    }
    printf("\n");
}
for(i=0;i<a;i++)
{
    for(j=0;j<b;j++)
    {
        printf("masukan matriks 2 indeks %i %i ",i,j);
        scanf("%i",&matriks2[i][j]);
    }
    printf("\n");
}
hitung :
printf("\n1.penjumlahan\n");
printf("2.pengurangan\n");
scanf("%i",&kode);
switch(kode)
{
case 1 :
for(i=0;i<a;i++)
{
    for(j=0;j<b;j++)
    {
        f[i][j] = matriks[i][j] + matriks2[i][j];



    }
    printf("\n\n");
}
 printf("%d\t",f[i][j]);
printf("\nhitung ulang y/t ?");
printf("\ntekan m untuk kembali ke menu\n ");
scanf("%c",&o);
o=getchar();
if(o=='y')
{
    system("cls");
    goto hitung;
}
else if (o=='m')
{
system("cls");
    goto menu;
}
else if (o=='t')
{

}

break;
case 2:
for(i=0;i<a;i++)
{
    for(j=0;j<b;j++)
    {
        f[i][j] = matriks[i][j] - matriks2[i][j];

        printf("%d\t",f[i][j]);

    }
    printf("\n\n");
}
printf("\nhitung ulang y/t ?");
printf("\ntekan m untuk kembali ke menu\n ");
scanf("%c",&o);
o=getchar();
if(o=='y')
{
   system("cls");
   goto hitung;
}
else if(o=='m')
{
system("cls");
   goto menu;
}
else if(o=='t')
{

}

break;
}

}
