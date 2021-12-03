#include<stdio.h>
#include<conio.h>

void main()
{

    char kata1 [20],kata2 [20],ganjil[2],genap[2],m;
     int a,b,c,n,i,j;
    menu:
printf("\n-----Tugas ASD-----\n");
printf("=====Menu Utama=====\n");
printf("1.Kombinasi Kata\n");
printf("2.Belah Ketupat\n");
printf("3.Keluar\n");
printf("Masukan pilihan menu : ");
m=getche();
getch();
switch(m)
{
case '1':
    printf("\nKombinasi Kata");
    printf("\nmasukan batas awal :");
scanf("%i",&i);
printf("masukan batas akhir :");
scanf("%i",&j);
printf("masukan kata awal :");
scanf("%s",&kata1);
printf("masukan kata akhir :");
scanf("%s",&kata2);
printf("hasil :");
for(i;i<=j;i++){
     if(i%2==1){printf("%s ",kata1);}
          if(i%2==0){ printf("%s ",kata2);}
}
printf("\n\nTekan apa aja untuk kembali ke menu utama\n");
getch();
goto menu ;
    break;
case '2':
    printf("\n=====Belah Ketupat=====");
    printf("\nMasukkan angka :");
scanf("%d", &n);
   printf("Masukkan Karakter ganjil : ");
         scanf("%s",&ganjil);
           printf("Masukkan Karakter ganjil : ");
         scanf("%s",&genap);
for(a=0;a<=n;a++)
{
    for(b=n-1;b>=a;b--){
    printf("   ");}
    for(c=0;c<=a*2;c++)
    {
        if(c%2==1){printf(" %s ",ganjil);}
          if(c%2==0){ printf(" %s ",genap);}

    }
    printf("\n\n");

    }
    for(b=0;b<=n;b++){
            for(a=0;a<=b;a++)
            {
                printf("   ");
            }
             for(c=n*2;c>=a*2;c--)
    {
           if(c%2==1){printf(" %s ",ganjil);}
          if(c%2==0){ printf(" %s ",genap);}
    }
        printf("\n\n");
    }
    printf("\nTekan apa aja untuk kembali ke menu utama\n");
     getch();
goto menu ;
    break;
case '3' :
    printf("\n\n_______________________________");
    break;
}

}
