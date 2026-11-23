#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define MAXOGR 10
void kayitgoruntule(void);
void kayitekle(void);
void kayit_sil(void);
typedef struct{
    uint32_t ogrenci_numarasi;
    char isim[30];
    char alan[30];
    char dob[30];
    uint8_t somestr;
}OGRENCI_BILGISI_t;
OGRENCI_BILGISI_t ogrenciler[MAXOGR];

int main(){
    int devam = 1;
    uint32_t secim;

    while(devam){
        printf("\nogrenci kayit duzenleme ekrani:\n");
        printf("1- tum kayitlari goruntule\n");
        printf("2- yeni kayit ekle\n");
        printf("3- kayit sil\n");
        printf("4- cik git\n");

        while(1){
            printf("secim: ");
            int sonuc = scanf("%u", &secim);
            while(getchar() != '\n');
            if(sonuc == 1){
                break;
            }
            printf("sadece sayi gir\n");
        }

        switch(secim){
            case 1:
                kayitgoruntule();
                break;
            case 2:
                kayitekle();
                break;
            case 3:
                kayit_sil();
                break;
            case 4:
                devam = 0;
                break;
            default:
                printf("gecersiz secim\n");
                break;
        }
    }
    return 0;
}

void kayitgoruntule(void){
    int ogrflag = 0;
    for(int i=0; i<MAXOGR; i++){
        if(ogrenciler[i].ogrenci_numarasi != 0){
            printf("ogrencinin numarasi %u\nogrencinin ismi %s\nogrencinin alani %s\nogrencinin dob %s\nogrencinin somestr %u\n",
                ogrenciler[i].ogrenci_numarasi,
                ogrenciler[i].isim,
                ogrenciler[i].alan,
                ogrenciler[i].dob,
                ogrenciler[i].somestr);
                ogrflag++;
        }
    
    }
    if(ogrflag == 0){
            printf("hicbir kayit yok");
        }

}

void kayitekle(void){
    uint32_t ogrno;
        while (1){
            printf("numara gir: ");
            int sonuc = scanf("%u", &ogrno);
            while (getchar() != '\n');      
            if (sonuc == 1) {
            break;
        }
        printf("sadece sayi gir\n");
    }
    if(ogrno == 0){
        printf("sifir giremezsiniz\n");
        return;
    }
    for(int i=0; i<MAXOGR; i++){
        if(ogrenciler[i].ogrenci_numarasi == ogrno){
            printf("bu ogrenci kayitlidir:\n");
            return;
        }
    }
    for(int i=0; i<MAXOGR; i++){
        if(ogrenciler[i].ogrenci_numarasi == 0){
            ogrenciler[i].ogrenci_numarasi = ogrno;
            printf("isim gir:");
            scanf("%29s", ogrenciler[i].isim);
            printf("alan gir:");
            scanf("%29s", ogrenciler[i].alan);
            printf("dob gir:");
            scanf("%29s", ogrenciler[i].dob);
            printf("somestr gir:");
            scanf("%hhu", &ogrenciler[i].somestr);
            return;
        }
    }
    printf("Yer yok, kayit eklenemedi\n");
}



/*for(int i=0; i<MAXOGR; i++){
        if(ogrenciler[i].ogrenci_numarasi == 0){
            printf("numara gir:");
            scanf("%u", &ogrenciler[i].ogrenci_numarasi);
            printf("isim gir:");
            scanf("%s", &ogrenciler[i].isim); 
            printf("alan gir:");
            scanf("%s", &ogrenciler[i].alan);
            printf("dob gir:");
            scanf("%s", &ogrenciler[i].dob);
            printf("somestr gir:");
            scanf("%u", &ogrenciler[i].somestr);
        }*/

void kayit_sil(void){
    uint32_t ogrno;
    
    while(1){
        printf("silinecek ogrencinin numarasini gir:\n");
        int sonuc = scanf("%u", &ogrno);
        while (getchar() != '\n'); 
        if (sonuc == 1){
            break;
        }
        printf("sadece sayi gir\n");
    }
    if(ogrno == 0){
        printf("sifir giremezsiniz\n");
        return;
    }
    for(int i=0; i<MAXOGR; i++){
        if(ogrenciler[i].ogrenci_numarasi == ogrno){
            uint8_t *pOgr = (uint8_t *)&ogrenciler[i];
            for(uint32_t j=0; j<sizeof(ogrenciler[i]); j++){
                pOgr[j] = 0;
            }
            printf("kayit silindi.\n");
            return;
        }
    }
    
    printf("ogrenci kayitli degildir.\n");
}


/* main 
 int devam = 1;

    while(devam){
        printf("ogrenci kayit duzenleme ekrani:\n");
        printf("1- tum kayitlari goruntule\n");
        printf("2- yeni kayit ekle\n");
        printf("3- kayit sil\n");
        printf("4- cik git\n");

    uint32_t secim;
    scanf("%u", &secim);
    if(secim == 0){
        printf("sifir giremezsiniz\n");
        return;
        while (1){
            printf("numara gir: ");
            int sonuc = scanf("%u", &secim);
            while (getchar() != '\n');      
            if (sonuc == 1) {
            break;
        }
        printf("sadece sayi gir\n");
    }
    }
        switch(secim){
            case 1:
            kayitgoruntule();
            break;
            case 2:
            kayitekle();
            break;
            case 3:
            kayit_sil();
            break;
            case 4:
            devam = 0;
            break;
            default: 
            printf("gecersiz secim\n")
        }
    }
    return 0;
    */