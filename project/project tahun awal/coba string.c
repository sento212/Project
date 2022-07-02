 #include<stdio.h>
 #include<string.h>

int main()
{
    int  jumkar=-1,jumspasi=0,i,a;
    char text[100];
    printf("masukan kalimat=");
     strupr(text);
    a=strlen(text);

while((text[100] = gets(text)) != '\n')
{


    jumkar++;
    if(text==' ')
        jumspasi++;
}

      for(a-1;a>0;a--)
    {
        printf("%c",text[a-1]);
    }
    printf("\n");

i= jumkar - jumspasi;
    printf("jumlah karakter = %d", i);


}
