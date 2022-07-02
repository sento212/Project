#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

void sorth(int sort[],int n){
int i,j,s ;
for(i =0;i<= n; i++)
{
for(j=1; j <= n-i-1; j ++){
      if(sort[j] > sort[j+1]){
        s = sort[j];
        sort[j] = sort[j+1];
        sort[j+1] = s;
}
}
}
}

void median(int sort[], int n){
    int x,y;
    float median;
if(n%2==1)
{
median = (n+1)/2;
}
if(n%2==0)
{
    x = n/2;
    y = n/2+1;
    median =(sort[x] + sort[y]);
    median = median/2;

}
printf("%.1f",median);
}

void cari(int n,int c,int sort[])
{
    int d = 0;
    for(int i = 0; i <= n ;i++)
{
  if (c == sort[i])
  {
      d = 1;
      printf("%d",sort[i]);
  }

}
if (d == 0)
{
    printf("data tidak ditemukan");
}
}

int main(){
int sort[100000];
int n ,i,k,c ;
char pilihan;
menu :
printf("1. Kualitas produksi\n");
printf("2. Tebak tebakan jerapah\n");
 printf("Pilih problem : ");
pilihan=getche();
    switch(pilihan){
    case '1':
scanf("%d",&n);
for(i =1; i <= n ; i++)
{
    scanf("%d",&k);
if(k>100)
{
    printf("nilainya berlebihan masukan lagi : ");
    scanf("%d",&k);
}
    sort[i] = k;
}
sorth(sort, n);
printf("\n");
median(sort,n);
getch();
     system("cls");
     goto menu;
break;
    case '2':
        scanf("%d",&n);
        scanf("%d",&c);
for(i =1; i <= n ; i++)
{
    scanf("%d",&k);
if(k>1000)
{
    printf("nilainya berlebihan masukan lagi : ");
    scanf("%d",&k);
}
    sort[i] = k;
}
sorth(sort, n);
printf("\n");
cari(n,c,sort);
getch();
     system("cls");
     goto menu;
        break;
    }
return 0;
}
