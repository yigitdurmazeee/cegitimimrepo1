#include <stdio.h>

int toplama(int , int );

int main() {

    int donenDeger;
    donenDeger = toplama(11,26);
    donenDeger = toplama(11,99);

    int a = 5;
    int b = 10;
    donenDeger = toplama(a, b);
    

    return 0;
    
}

int toplama(int a, int b) {
    int sonuc = a + b;
    printf("Toplam: %d\n", sonuc);

    return sonuc;
}
