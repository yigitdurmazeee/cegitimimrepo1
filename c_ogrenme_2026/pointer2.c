#include <stdio.h>

long long int g_data = 0xFFFEABCD11112345;
int secondmain(void);

int main(void){

    char *pAdresss1;

    pAdresss1 = (char*)&g_data;

    printf("%p adresindeki deger : %x\n", pAdresss1, *pAdresss1);
    //burada sadece 1 byte okunduğu için 45 yazdırır

    long long int *pAdresss2;
    pAdresss2 = (long long int*)&g_data;
    printf("\n%p adresindeki deger : %I64x\n", pAdresss2, *pAdresss2);

    int *pAdresss3;
    pAdresss3 = (int*)&g_data;
    printf("\n%p adresindeki deger : %x\n", pAdresss3, *pAdresss3);

    secondmain();

    return 0;

}

int secondmain(void){

    char *pAdress;

    pAdress = (char*)&g_data;

    printf("adresin degeri: %p\n", pAdress);
    printf("%p adresindeki deger : %x\n", pAdress, *pAdress);
    
    pAdress = pAdress + 1;
    printf("%p adresindeki deger : %x\n", pAdress, *pAdress);
    printf("adresin degeri: %p\n", pAdress);
    
    for(int i = 0; i < 8; i++){
        printf("%p adresindeki deger : %x\n", pAdress, *pAdress);
        pAdress++;
        //char oldugu için 1 byte ilerler int olsaydı 4 byte ilerlerdi
    }

    return 0;

}

/* How is Pointer used in embedded programming?
Store data into required SRAM locations.
For copying data from Peripheral registerto SRAM memory and
vice versa.
To configure the peripheral registers. Because peripheral registers
are memory-mapped and each register Will be given unique address
in the MCU memory map.
Pointers to ISRs are stored in a vector table to handle the interrupts.
Pointers are also used to configure the memory-mapped processor
specific registers like interrupt configuration registers.*/