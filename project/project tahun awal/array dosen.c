#include<stdio.h>

main()
{
    int i,j;
    printf("pius aldi septio\n");
    int nama_depan[8][8]=
    {
        {0,0,1,1,1,1,0,0},
        {0,0,1,0,0,1,0,0},
        {0,0,1,1,1,1,0,0},
        {0,0,1,0,0,0,0,0},
        {0,0,1,0,0,0,0,0},
        {0,0,1,0,0,0,0,0},
        {0,0,1,0,0,0,0,0},
        {0,0,1,0,0,0,0,0},
    };
    for(i=0;i<8;i++)
    {
        for(j=0;j<8;j++)
            if(nama_depan[i][j] !=0 )
            putchar('\xDB');
        else
            putchar(' ');
        putchar('\n');
    }
}

