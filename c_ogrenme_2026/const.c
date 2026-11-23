#include <stdio.h>
#include <string.h>

// ============================================================
// ÖRNEK 1: Const Değişkenler - Sabit Değerler
// ============================================================
// Const değişkenler atandıktan sonra değiştirilemez.
// Bu, değişmemesi gereken veriler için kullanılır.

void ornek1_const_degiskenler(void) {
    printf("\n=== ÖRNEK 1: Const Değişkenler ===\n");

    const int MAX_OGRENCI = 100;      // Maksimum öğrenci sayısı
    const float PI = 3.14159;         // Pi sayısı
    const char VERSION[] = "1.0.0";   // Sürüm numarası

    printf("Maksimum öğrenci: %d\n", MAX_OGRENCI);
    printf("Pi değeri: %.5f\n", PI);
    printf("Versiyon: %s\n", VERSION);

    // MAX_OGRENCI = 200;  // HATA! Const değişken değiştirilemez
}


// ============================================================
// ÖRNEK 2: Const Pointers - Değişmeyen Adres
// ============================================================
// Const pointer, işaret ettiği adresi değiştiremez.
// Ama işaret ettiği verinin içeriğini değiştirebilir.

void ornek2_const_pointers(void) {
    printf("\n=== ÖRNEK 2: Const Pointers ===\n");

    int x = 10;
    int y = 20;

    int * const ptr = &x;  // Const pointer - adresi değişmez

    printf("İlk değer: *ptr = %d\n", *ptr);

    *ptr = 15;  // UYGUN: İçeriği değiştirebiliriz
    printf("Değiştirdikten sonra: *ptr = %d\n", *ptr);
    printf("x de değişti: x = %d\n", x);

    // ptr = &y;  // HATA! Const pointer, başka adrese işaret edemez
}


// ============================================================
// ÖRNEK 3: Pointer to Const - Değişmeyen Veriler
// ============================================================
// Const veriye işaretçi, işaret ettiği veriyi değiştiremez.
// Ama farklı adreslere işaret edebilir.

void ornek3_pointer_to_const(void) {
    printf("\n=== ÖRNEK 3: Pointer to Const ===\n");

    int deger1 = 100;
    int deger2 = 200;

    const int *ptr = &deger1;  // Const veriye işaretçi

    printf("İşaret edilen ilk değer: %d\n", *ptr);

    ptr = &deger2;  // UYGUN: Başka adrese işaret edebilir
    printf("Şimdi işaret edilen değer: %d\n", *ptr);

    // *ptr = 300;  // HATA! Const veriyi değiştiremez
}


// ============================================================
// ÖRNEK 4: Const Fonksiyon Parametreleri
// ============================================================
// Fonksiyonda const parametreler, fonksiyon içinde
// değiştirilemeyeceğini garanti eder.

void yazdir_ogrenci(const char *isim, const int yas) {
    printf("Adı: %s, Yaşı: %d\n", isim, yas);

    // isim[0] = 'A';  // HATA! Const string değişmez
    // yas = 30;       // HATA! Const parametreyi değişmez
}

void diziye_yazdır_readonly(const int *dizi, const int uzunluk) {
    printf("Dizi elemanları: ");
    for (int i = 0; i < uzunluk; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");

    // dizi[0] = 999;  // HATA! Const dizi elemanı değişmez
}

void ornek4_const_parametreler(void) {
    printf("\n=== ÖRNEK 4: Const Fonksiyon Parametreleri ===\n");

    yazdir_ogrenci("Ahmet", 25);
    yazdir_ogrenci("Fatma", 22);

    int sinif[] = {85, 90, 78, 92, 88};
    diziye_yazdır_readonly(sinif, 5);
}


// ============================================================
// BONUS: Const String Literalleri
// ============================================================

void ornek_bonus_const_strings(void) {
    printf("\n=== BONUS: Const String Literalleri ===\n");

    const char *mesaj = "Bu bir sabit metindir";
    const char *hosgeldiniz[] = {
        "Merhaba",
        "Hello",
        "Hola"
    };

    printf("%s\n", mesaj);
    printf("Selamlamalar: %s, %s, %s\n", hosgeldiniz[0], hosgeldiniz[1], hosgeldiniz[2]);
}


// ============================================================
// Main Fonksiyonu
// ============================================================

int main(void) {
    printf("╔════════════════════════════════════════╗\n");
    printf("║  CONST KULLANIM ALANLARI - 4 ÖRNEK    ║\n");
    printf("╚════════════════════════════════════════╝\n");

    ornek1_const_degiskenler();
    ornek2_const_pointers();
    ornek3_pointer_to_const();
    ornek4_const_parametreler();
    ornek_bonus_const_strings();

    printf("\n✓ Tüm örnekler tamamlandı.\n\n");

    return 0;
}
