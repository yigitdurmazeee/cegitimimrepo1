#include <stdio.h>
#include <stdint.h>

int main(){

    float gelir, oran, vergi;

    while(1) {
    printf("gelirinizi giriniz: ");
    if(scanf("%f", &gelir) == 1) {
        break;  // Başarılı, döngüyü kır
    } else {
        printf("sadece sayilar hesaplanir\n");
        while(getchar() != '\n');  // ← ÖNEMLI! Buffer'ı temizle
    }
}

    if (gelir <= 9525){
        oran=0;
    }
    else if (gelir <= 38700){
        oran=0.12;
    }
    else if (gelir <= 82500){
        oran=0.22;
    }
    else{
        oran=0.32;
    
    }
    vergi = gelir * oran;

    if(gelir > 82500){
        vergi += 1000;
    }
    

    printf("vergi: %.4f\n", vergi);
    printf("kapatmak icin bir tusa bas...\n");
    getchar();

    while(getchar() != '\n'){
        //input bufferı oku ve bekle
        
    }

    return 0;

}