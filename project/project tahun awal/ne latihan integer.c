#include <stdio.h>
int main()
{
char kar;
int jumkar = 0, jumspasi = 0,huruf_kecil = 0, huruf_besar =0 ,jum_angka = 0,i, max;

printf("Masukkan sebuah kalimat dan akhiri dgn ENTER.\n");
 printf("Saya akan menghitung jumlah karakter\n ");
printf("jumlah spasi, huruf kecil dan besar, beserta angka\n ");
 printf("pada kalimat tersebut.\n");

while((kar = getchar()) != '\n')
{
 jumkar++;
if (kar == ' ')
jumspasi++;
if (kar >= 'A'  &&  kar <= 'Z')
huruf_besar++;
if (kar  >= 'a'  && kar <= 'z')
huruf_kecil++;
if (kar  >= '1'  && kar <= '9')
jum_angka++;
if (kar  >= 'a'  && kar <= 'z')
i = kar + 1 ;

}
printf("\nJumlah karakter = %d", jumkar);
 printf("\nJumlah SPASI = %d\n\n", jumspasi);
 printf("\nJumlah huruf kecil= %d\n\n", huruf_kecil);
 printf("\nJumlah huruf besar= %d\n\n", huruf_besar);
 printf("\nJumlah jumlah angka= %d\n\n", jum_angka);
  printf("\nJumlah jumlah angka= %c\n\n", i);
}
