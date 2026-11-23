#include <stdio.h>

int main(){
    int sayi1, sayi2, sonuc;

    printf("2 adet sayi giriniz:\n");
    scanf("%d %d", &sayi1, &sayi2);

    sonuc= sayi1 - sayi2;
    if (sonuc < 0){
        printf("1. sayi 2. sayidan kucuktur\n");
        printf("%d\n", sayi2);
    }
    else if (sonuc > 0){
        printf("1. sayi 2. sayidan buyuktur\n");
        printf("%d\n", sayi1);
    }
    else{
        printf("1. sayi 2. sayiya esittir\n");
    }

    while (getchar() != '\n'){
        //input bufferı oku ve bekle
    }
    getchar();


    return 0;

}

/* veya direkt if statementler ile yapılabilir 

int main(){
    int sayi1, sayi2;

    printf("2 adet sayi giriniz:\n");
    scanf("%d %d", &sayi1, &sayi2);

    if (sayi1 < sayi2){
        printf("1. sayi 2. sayidan kucuktur\n");
        printf("%d\n", sayi2);
    }
    else if (sayi1 > sayi2){
        printf("1. sayi 2. sayidan buyuktur\n");
        printf("%d\n", sayi1);
    }
    else{
        printf("1. sayi 2. sayiya esittir\n");
    }

    while (getchar() != '\n'){
        //input bufferı oku ve bekle
    }
    getchar();  
}




*/