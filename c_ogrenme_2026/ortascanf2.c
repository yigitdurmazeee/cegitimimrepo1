#include<stdio.h>


int main(){

    float numara1, numara2, numara3;
    float ort;

    printf("3 sayiyi giriniz: ");
    fflush(stdout);
    scanf("%f %f %f", &numara1, &numara2, &numara3);

    ort = (numara1 + numara2 + numara3) / 3;
    printf("Ortalama: %.4f\n", ort);

    //getchar();

    while(getchar() != '\n'){

        
    }
    getchar();


}