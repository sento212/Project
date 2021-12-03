#include <stdio.h>
#include <stdlib.h>
//nama : pius aldi septio
//nim  : 672019046
//nama :  albertus agung fernando
//nim  : 672019239


void main()
{
char a[10], d[10];
int  b,e,z,x,n,m,k,l,o,p ;
float e1,c,f;

printf("Masukan nama\n");
scanf("%s",&a);
printf("Masukan nim\n");
scanf("%d",&b);
printf("Masukan ipk\n");
scanf("%f",&c);
printf("Masukan nama\n");
scanf("%s",&d);
printf("Masukan nim\n");
scanf("%d",&e);
printf("Masukan ipk\n");
scanf("%f",&f);
e1=(c+f)/2;

 printf("Pilih segitiga yang mana?\n");
  printf("jika satu tekan 8\n");
  printf("jika dua tekan 9\n");
  scanf("%d",&z);



  switch(z)
  {
  case 8:
      printf("pilihan segitiga kamu\n");
  for(x=1; x<=z; x++)
  {
      for(n=1;n<=2*z-1;n++)
      {
          if(n>=z-(x-1)&&n<=z+(x-1))
          {
              printf("*");

          }
          else
          {
              printf(" ");
          }
      }
      printf("\n");
  }

break;
  case 9:
         printf("pilihan segitiga kamu\n");
    for(m=1;m<=z;m++)
    {
        for(k=1;k<=m;k++)
        {
            printf("*");
        }
        printf("\n");
    }
for(l=1;l<=k;l++)
{
    for(o=1;o<=1-l;o++)
        printf(" ");
    for(p=0;p>=(l-m);p--)
        printf("*");
    printf("\n");
}
break;

  }
printf(" Hai %s dan %s\n",a,d);
printf("nim kalian %d & %d\n",b,e);
printf("rata rata ipk kalian %f ",e1);


getchar();
}
