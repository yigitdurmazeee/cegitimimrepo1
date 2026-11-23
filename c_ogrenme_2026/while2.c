#include <stdio.h>
#include <stdint.h>

int main(){
   uint8_t sayi = 0;
   uint8_t adet = 0;
   int secim;
   printf("sinirlari dahil etmek icin secin 1\nsinirlari dahil etmemek icin secin 2\n");
   scanf("%d", &secim);
   switch(secim){
       case 1:
           while(0 <= sayi && sayi <= 100){
               printf("%d\n", sayi);
               sayi += 2;
               adet++;
           }
           break;
       case 2:
           while(sayi < 98){
               sayi += 2;
               printf("%d\n", sayi);
               adet++;
           }
           break;
       default:
           printf("yanlis secim yaptiniz\n");
   }

   printf("Toplam %d adet sayi yazdirildi\n", adet);
    
   while(getchar() != '\n'){


   }
   getchar();
   
   return 0;
}
