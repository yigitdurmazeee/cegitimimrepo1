#include <stdio.h>
#include "math.h"


int main() {
    
    int a = 10;
    int b = 5;

    toplamyazmatematik(a, b);
    carpmayazmatematik(a, b);
    cikarmayazmatematik(a, b);
    bolmeyazmatematik(a, b);

    printf("toplam: %d\n", toplammatematik(12, 125));
    printf("carpim: %d\n", carpmamatematik(12, 125)); 
    printf("fark: %lld\n", cikarmamatematik(12, 125));
    printf("bolum: %f\n", bolmamatematik(12, 125));

    return 0;


}