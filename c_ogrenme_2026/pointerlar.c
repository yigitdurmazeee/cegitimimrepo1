#include <stdio.h>

int main(){

    char a1= 'a';
    unsigned long long int adressof_a1 = (unsigned long long int)&a1;
    printf("a1 = %c\n", a1);
    printf("adressof_a1 = %llu\n", adressof_a1);
    printf("adressof_a1 = %I64X\n", adressof_a1);
    return 0;
}