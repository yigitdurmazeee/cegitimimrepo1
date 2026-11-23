#include <stdio.h>
#include <stdint.h>


struct telefonmodeli {

    uint32_t marka
    uint32_t model
    uint8_t depolama
    float ekrancozunurluk
}
int main (){

    struct telefonmodeli xiaomi = {31,31,31,31}
    struct telefonmodeli samsung = {69,69,69,69}
    struct telefonmodeli motorola = {.depolama=54 ,.model=54 ,.marka=31 ,.ekrancozunurluk = 77.55}
    printf("Xiaomi Detayları\n");
    printf("Marka: %u\n", xiaomi.marka);
    printf("Model: %u\n", xiaomi.model);
     printf("Depolama: %u GB\n", xiaomi.depolama);
    printf("Ekran Çözünürlük: %.2f\n\n", xiaomi.ekrancozunurluk);

    samsung.model = 31;

    printf("Samsung Detayları\n");
    printf("Marka: %u\n", samsung.marka);
    printf("Model: %u\n", samsung.model);
    printf("Depolama: %u GB\n", samsung.depolama);
    printf("Ekran Çözünürlük: %.2f\n\n", samsung.ekrancozunurluk);

    printf("Motorola Detayları\n");
    printf("Marka: %u\n", motorola.marka);
    printf("Model: %u\n", motorola.model); 
    printf("Depolama: %u GB\n", motorola.depolama);
    printf("Ekran Çözünürlük: %.2f\n", motorola.ekrancozunurluk);

    printf("sizeof struct I64u\n", sizeof(struct telefonmodeli);)


    return 0; 
}

// ============================================================
// ALIGNED STRUCTURE (__attribute__((aligned)))
// ============================================================
struct aligned_telefonmodeli {
    uint32_t marka;
    uint8_t depolama;
    float ekrancozunurluk;
    uint32_t model;
} 

// ============================================================
// UNALIGNED STRUCTURE (__attribute__((packed)))
// ============================================================
struct unaligned_telefonmodeli {
    uint32_t marka;
    uint8_t depolama;
    float ekrancozunurluk;
    uint32_t model;
} __attribute__((packed));

// ============================================================
// Boyutları Karşılaştırma
// ============================================================
int main() {
    printf("╔════════════════════════════════════════╗\n");
    printf("║  ALIGNED vs UNALIGNED STRUCTURE        ║\n");
    printf("╚════════════════════════════════════════╝\n\n");
    
    printf("Aligned Struct Boyutu:   %zu byte\n", sizeof(struct aligned_telefonmodeli));
    printf("Unaligned Struct Boyutu: %zu byte\n\n", sizeof(struct unaligned_telefonmodeli));
    
    struct aligned_telefonmodeli xiaomi_aligned = {31, 31, 3.14, 31};
    struct unaligned_telefonmodeli xiaomi_unaligned = {31, 31, 3.14, 31};
    
    printf("Aligned Veriler:\n");
    printf("Marka: %u, Depolama: %u, Ekran: %.2f, Model: %u\n\n", 
           xiaomi_aligned.marka, xiaomi_aligned.depolama, 
           xiaomi_aligned.ekrancozunurluk, xiaomi_aligned.model);
    
    printf("Unaligned Veriler:\n");
    printf("Marka: %u, Depolama: %u, Ekran: %.2f, Model: %u\n", 
           xiaomi_unaligned.marka, xiaomi_unaligned.depolama, 
           xiaomi_unaligned.ekrancozunurluk, xiaomi_unaligned.model);
    
    return 0;
}

ikişer bit kontrol ederek padding eker derleyici

typedef struct{
    uint32_t marka;
    uint8_t depolama;
    float ekrancozunurluk;
    uint32_t model;
}TELEFONMODELI_t;

struct telefonmodeli {
    uint32_t marka;
    uint8_t depolama;
    float ekrancozunurluk;
    uint32_t model;
    struct telefonmodeli *pSamsung;
} //olur

struct telefonmodeli {
    uint32_t marka;
    uint8_t depolama;
    float ekrancozunurluk;
    uint32_t model;
    struct telefonmodeli *pSamsung;
} //olur

struct Data {
    char data1;
    int data2;
    char data3;
    short data4;
    struct {
        char data5;
        int data6;
    } moreData;
};//olur

#include <stdio.h>
#include <stdint.h>

struct CarModel {
    unsigned int carNumber;
    uint32_t carPrice;
    uint16_t carMaxSpeed;
    float carWeight;
    
    struct {
        float temperature;
        float airPressure;
        int fuel;
    } carParameters;
};
