#include <stdio.h>

int main(){
//degisken tanımladık
    char a=100;
//yazdırdık
    printf("a karakterinin degeri: %d\n", a);
//adresini yazdırdık
    printf("a karakterinin adresi: %p", &a);
//pointer tanımladık
    char* pharf = &a;
    //char *pharf = &a;
//dereferans ile pointerin gösterdiği değeri yazdırdık
    char deger = *pharf;

    printf("\nokunan deger: %d", deger);
//pointer ile a karakterinin değerini değiştirdik
 
    *pharf = 120;
    printf("\npharf pointeri ile a karakterinin degeri: %d", a);
 
return 0;
}