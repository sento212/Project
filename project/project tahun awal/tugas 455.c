#include<stdio.h>
#include<string.h>
 main()
 {
     char kar[15];
     int Ha=0,ha=0;
     printf("masukan sebua kalimat: ");

while((kar = getchar())!='\n')
{


     if(kar >='A' && kar<='Z')
        Ha++;
          if(kar >='a' && kar<='z')
        ha++;
}
        printf("jumlah huruf besar = %d\n",Ha);
          printf("jumlah huruf kecil = %d\n",ha);

 }
