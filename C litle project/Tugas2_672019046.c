#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
int main()
{
    char pilihan;
    int a,i,k,small,end,end2;
    int j,u,l,kk;
     int b[10000],s[10000];
       float d[10000];
float jj=0 , m = 0 ;
    menu :
    printf("========= Elegant Competitive Programing =========\n");
    printf("1. problem undian berhadiah \n");
    printf("2. Di atas Rata Rata \n");
        printf("Pilih problem : ");
pilihan=getche();
    switch(pilihan)
    {
    case '1' :
      scanf("%d",&a);
      scanf("%d",&k);

    for(i=1; i <= a ; i++)
    {
        scanf("%d",&b[i]);

    }
    for(i=1; i<= a ; i++)
    {
 s[i] =k - b[i];
 if(s[i]<0)
 {
     s[i]=-1*s[i];
 }
    }
  small = s[1];
  for (i = 1; i < a+1; i++) {
    if (s[i] < small){
      small = s[i];}
  }
end = k - small;
   int encore=3;
for(i = 1; i < a+1; i++){

   if(end==b[i])
   {
        printf("%d ",end);
        encore+=1;
   }
}
if(encore==3){
end2 = (k*2)-end;
     printf("%d ",end2);}
        getch();
     system("cls");

     goto menu;
        break;
    case '2':
         scanf("%d",&kk);
for (j = 1; j <=kk; j++){
         scanf("%d",&u);
  for( i=1; i <= u ; i++)
  {
       scanf("%f",&d[i]);
    m = m+d[i];
  }
  m = m/u;
  for(i=1;i<= u; i++)
  {
   if (d[i] > m )
{
    d[i]= 1;
    jj = jj + d[i];
}
  }
jj= jj / u * 100;
printf("%.3f%%",jj);
jj = jj - jj;
m = m - m;
   printf("\n");
}
getch();
     system("cls");
     goto menu;
        break;
    }
     return(0);
}
