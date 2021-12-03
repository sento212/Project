//nama pius aldi septio 672019046
//aldi krisandi kurniawan 672019013
//kevin ferdinand s 672019015
#include<stdio.h>
#include<string.h>


main()
{
    int a;
    char kata[20];
    printf("Pembalik Kata\n");
    printf("Masukan Kata : ");
    gets(kata);
    a=strupr(kata);
    a=strlen(kata);
    printf("kata setelah dibalik: \n");
    for(a-1;a>0;a--)
    {
        printf("%c",kata[a-1]);
    }
    printf("\n");
    return 0;
}


