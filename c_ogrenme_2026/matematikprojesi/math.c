#include <stdio.h>
#include <math.h>


int toplamyazmatematik(int a1, int a2);
int carpmayazmatematik(int a1, int a2);
long long int cikarmayazmatematik(int a1, int a2);
float bolmeyazmatematik(int a1, int a2);


int toplamyazmatematik(int a1, int a2) {
    int sonuc = a1 + a2;
    printf("Toplam: %d\n", sonuc);

    return sonuc;
}
int carpmayazmatematik(int a1, int a2){
    int sonuc = a1 * a2;
    printf("carpim: %d\n", sonuc);
    return sonuc;
}
long long int cikarmayazmatematik(int a1, int a2){
    long long int sonuc = a1 - a2;
    printf("Fark: %lld\n", sonuc);
    return sonuc;
}
float bolmeyazmatematik(int a1, int a2){
    float sonuc = (float)a1 / (float)a2;
    printf("Bolum: %f\n", sonuc);
    return sonuc;
}

int toplammatematik(int a1, int a2) {
    int sonuc = a1 + a2;
   
    return sonuc;
}
int carpmamatematik(int a1, int a2){
    int sonuc = a1 * a2;

    return sonuc;
}
long long int cikarmamatematik(int a1, int a2){
    long long int sonuc = a1 - a2;
    
    return sonuc;
}
float bolmamatematik(int a1, int a2){
    float sonuc = (float)a1 / (float)a2;
    
    return sonuc;
}