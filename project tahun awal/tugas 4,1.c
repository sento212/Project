#include <stdio.h>

int total(int a, int b){
    int hasil = (int)a + (int)b;
    return hasil;
}

void main(){
    printf("Hasil 10+10 adalah : %d\n", total(10, 10));
}
