/*
&& logical and ve & bitwise and                     mantıksal ve bitwise böylye olu bitwise bit bit and alır vs vs 
char a=40
char b=30      c= a&&b;   C=a&b;
                1 1  1     00101000 a
                           00011110 b
                           ----------
                           00001000 c = 8
testing bits &
setting bits |
clearin bits ~ ve & 
toggling bits ^ xor*/



#include <stdio.h>
#include <stdint.h>

int main(){

    int32_t a, b;
    printf("2 karakter giriniz:\n");
    scanf("%d %d", &a, &b);
    printf("bitwise and: %d\n", a & b);
    printf("bitwise or: %d\n", a | b);
    printf("bitwise xor: %d\n", a ^ b);
    printf("bitwise not: %d\n", ~a);

    return 0;



}