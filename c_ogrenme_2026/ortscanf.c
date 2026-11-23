#include<stdio.h>


int main(){

    float numara1, numara2, numara3;
    float ort;

    printf("1. sayiyi giriniz: ");
    fflush(stdout);
    scanf("%f", &numara1);
    printf("\n2. sayiyi giriniz: ");
    scanf("%f", &numara2);
    printf("\n3. sayiyi giriniz: ");
    scanf("%f", &numara3);

    ort = (numara1 + numara2 + numara3) / 3;
    printf("Ortalama: %.4f\n", ort);

    //getchar();

    while(getchar() != '\n'){
        
    }
    getchar();


}