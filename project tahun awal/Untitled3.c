#include <stdio.h>
int sum(int,int);

void main(){
    int a,b, c;

    printf("masukan nilai a: ");
    scanf("%d", &a);
      printf("masukan nilai b: ");
    scanf("%d", &b);

   c = sum(a ,b);

    printf("hasil = %d", c);
}

 int sum (int x ,int y){

        return  sum (x + y);


}
