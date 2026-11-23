#include <stdio.h>

int main(){
     

    char ch1, ch2, ch3, ch4, ch5, ch6;

    printf("6 karakter giriniz: ");

    fflush(stdout);

    scanf("%c %c %c %c %c %c", &ch1, &ch2, &ch3, &ch4, &ch5, &ch6);

    printf("\nGirilen karakterler: %u %u %u %u %u %u", ch1, ch2, ch3, ch4, ch5, ch6);

    while(getchar() != '\n'){


    }
    getchar();

}