#include <stdio.h>
#include <stdint.h>

/* case int olmak zorundadır */

/*int main(void)
{
    uint8_t tus_oku = read_keypad();

    switch (tus_oku)
    {
    case 1:
        all_leds_race();
        break;
    case 2:
        all_leds_blink();
        break;
    case 3:
        all_leds_on(); 
        break;
    case 4:
        all_leds_toggle();
        break;
    default:
        all_leds_off();
        printf("gecersiz tus\n");




    }
    return 0;
}
break gorene kadar caseler arasında calısır */


//5 farklı geometrik şekil için alan hesaplaması yapan program


int main(){
    
    int secim, T, Z, C, S, R;
    printf("1. ucgen\n2. dikdortgen\n3. kare\n4. daire\n5. yamuk\n");
    printf("alanini hesaplamak istediginiz sekli seciniz: ");
    scanf("%d", &secim);

    switch(secim){
        case 1:
            printf("ucgenin taban uzunlugunu giriniz: ");
            scanf("%d", &T);
            printf("ucgenin yuksekligini giriniz: ");
            scanf("%d", &Z);
            printf("ucgenin alani: %d\n", (T * Z) / 2);
            break;
        case 2:
            printf("dikdortgenin uzunlugunu giriniz: ");
            scanf("%d", &R);
            printf("dikdortgenin genisligini giriniz: ");
            scanf("%d", &C);
            printf("dikdortgenin alani: %d\n", R * C);
            break;
        case 3:
            printf("karenin kenar uzunlugunu giriniz: ");
            scanf("%d", &S);
            printf("karenin alani: %d\n", S * S);
            break;
        case 4:
            printf("dairenin yaricapini giriniz: ");
            scanf("%d", &R);
            printf("dairenin alani: %.2f\n", 3.14 * R * R);
            break;
        case 5:
            printf("yamugun alt taban uzunlugunu giriniz: ");
            scanf("%d", &T);
            printf("yamugun ust taban uzunlugunu giriniz: ");
            scanf("%d", &Z);
            printf("yamugun yuksekligini giriniz: ");
            scanf("%d", &C);
            printf("yamugun alani: %d\n", ((T + Z) * C) / 2);
            break;
        default:
            printf("gecersiz secim\n");
            while(getchar() != '\n'){
                //input bufferı oku ve bekle
            }
    }

    
    return 0;
}
