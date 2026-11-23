#include <stdio.h>
#include <stdint.h>

int main(){

    int i, j, yukseklik;

    printf("yukseklik giriniz: ");
    scanf("%d", &yukseklik);


    for (i=0; i<=yukseklik; i++){
        for (j=i; j>0; j--){
            printf("%d\t", j);


        }
        printf("\n");
    }

    return 0;
}