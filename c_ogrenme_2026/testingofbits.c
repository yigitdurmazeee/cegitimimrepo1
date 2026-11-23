#include <stdio.h>
#include <stdint.h>

int main(){

    int rakam;
    printf("rakam giriniz: ");
    if(scanf("%d", &rakam) == 0){
        printf("sadece sayilar karsilastirilir\n");
        return 0;
    }

    if(rakam & 1 == 0)
    printf("girdiginiz sayi cift sayidir\n");
    else
    printf("girdiginiz sayi tektir\n"); 
return 0;

}