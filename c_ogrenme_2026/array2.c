#include <stdio.h>
#include <stdint.h>

void girisbekle(void);
void display_array(uint32_t *pArray, uint32_t nitem);
void swaparrays(uint32_t *array1, uint32_t *array2, uint32_t nitem1, uint32_t nitem2);

int main(void){
    int item1, item2;
    printf("array1 ve array2 eleman sayilarini gir: ");
    scanf("%d %d", &item1, &item2);

    if((item1 <= 0) || (item2 <= 0)){
        printf("0 veya 0'dan kucuk olamaz\n");
        girisbekle();
        return 0;
    }

    uint32_t array1[item1];
    uint32_t array2[item2];

    for(uint32_t i = 0; i < (uint32_t)item1; i++){
        printf("array1 in %u. elemani: ", i);
        scanf("%u", &array1[i]);
    }
    for(uint32_t i = 0; i < (uint32_t)item2; i++){
        printf("array2 in %u. elemani: ", i);
        scanf("%u", &array2[i]);
    }

    printf("Onceki arrayler\n");
    display_array(array1, item1);
    printf("\n");
    display_array(array2, item2);
    printf("\n");

    swaparrays(array1, array2, item1, item2);

    printf("Sonraki arrayler\n");
    display_array(array1, item1);
    printf("\n");
    display_array(array2, item2);
    printf("\n");

    girisbekle();
    return 0;
}

void display_array(uint32_t *pArray, uint32_t nitem){
    for(uint32_t i = 0; i < nitem; i++){
        printf("%u ", pArray[i]);
    }
}

void girisbekle(void){
    // scanf'ten kalan karakterleri (ve '\n') temizle
    while(getchar() != '\n'){
    }
    printf("Cikmak icin Enter'a bas...");
    while(getchar() != '\n'){
    }
}

// Kisa olan array'in boyu kadar elemani karsilikli yer degistirir
void swaparrays(uint32_t *array1, uint32_t *array2, uint32_t nitem1, uint32_t nitem2){
    uint32_t len = (nitem1 < nitem2) ? nitem1 : nitem2;

    for(uint32_t i = 0; i < len; i++){
        uint32_t temp = array1[i];
        array1[i] = array2[i];
        array2[i] = temp;
    }
}
