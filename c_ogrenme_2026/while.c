#include <stdio.h>
#include <stdint.h>

int main(){
   uint8_t sayi = 0;
   uint8_t adet = 0;

   while(sayi <= 100){
       printf("%d\n", sayi);
       sayi += 2;
       adet++;
   }
   printf("Toplam %d adet sayi yazdirildi\n", adet);


return 0;
}