 #include <stdio.h>
 #include <stdint.h>

void kullanicikomutunubekle();

 int main(){

    float sayi1, sayi2;
    int sonuc;

    printf("2 adet sayi giriniz:\n");
    if (scanf("%f %f", &sayi1, &sayi2) == 0){
        printf("sadece sayilar karsilastirilir\n");
        return 0;
    }

    int32_t s1, s2;

    s1 = sayi1;
    s2 = sayi2; 

    if((s1 != sayi1) || (s2 != sayi2))
    {
        printf("sadece tamsayilar karsilastirilir\n");
    }
 
    if (s1 == s2){

        printf("1. sayi 2. sayiya esittir\n");
    }
    else if (s1 < s2){
        printf("1. sayi 2. sayidan kucuktur\n");
        printf("%d daha buyuktur\n", s1);
    }
    else if (s1 > s2){
        printf("1. sayi 2. sayidan buyuktur\n");
        printf("%d daha kucuktur\n", s2);
    }
    void kullanicikomutunubekle();
    return 0;
}
void kullanicikomutunubekle(){
    while (getchar() != '\n'){
        //input bufferı oku ve bekle
    }
    getchar();
}