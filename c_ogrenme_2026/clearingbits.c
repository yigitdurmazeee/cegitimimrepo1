#include <stdio.h>
#include <stdint.h>

int main(){
    uint32_t sayi;
    printf("Bir sayi giriniz: ");
    scanf("%d", &sayi);
    printf("islenmis sayi %d\n", sayi & (128+2+4+8+16));

    getchar();

    while(getchar() != '\n'){

    }

    return 0;


}