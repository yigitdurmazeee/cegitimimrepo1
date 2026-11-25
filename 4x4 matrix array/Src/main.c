#include <stdint.h>
#include <stdio.h>
#include "clkgpio.h"

// Tarama için düz 32 bit register erişimi (dizilerle kullanılacak)

#define SATIR 4
#define SUTUN 4

void delay(uint32_t count);

// Pin numaraları
const uint8_t satirlar[SATIR] = {11,12,13,14} ; // PB11–PB14 (output)
const uint8_t sutunlar[SUTUN] = {2,3,4,5};      // PC2–PC5  (input)

// Tuş haritası
const uint8_t tuslar[SATIR][SUTUN] = {
		{1,  2,  3,  4},
		{5,  6,  7,  8},
		{9,  10, 11, 12},
		{13, 14, 15, 16},
};

int main(void)
{
    // Struct pointer'ları
    volatile RCC_AHB2ENR_t *const pClock = (RCC_AHB2ENR_t*)(0x40021000 + 0x4C);
    volatile GPIOx_MODER_t *const pModeB = (GPIOx_MODER_t*)(0x48000400);
    volatile GPIOx_MODER_t *const pModeC = (GPIOx_MODER_t*)(0x48000800);
    volatile GPIOx_PUPDR_t *const pPupdC = (GPIOx_PUPDR_t*)(0x48000800 + 0x0C);

    // 1. Clock
    pClock->gpiob_en = 1;
    pClock->gpioc_en = 1;

    // 2. Satırlar başlangıçta HIGH (mode'dan önce)
    for(int s = 0; s < SATIR; s++)
        GPIOB_ODR |= (1 << satirlar[s]);

    // 3. Satırlar → output
    pModeB->mode11 = 1;
    pModeB->mode12 = 1;
    pModeB->mode13 = 1;
    pModeB->mode14 = 1;

    // 4. Sütunlar → input + pull-up
    pModeC->mode2 = 0;
    pModeC->mode3 = 0;
    pModeC->mode4 = 0;
    pModeC->mode5 = 0;

    pPupdC->pupd2 = 1;
    pPupdC->pupd3 = 1;
    pPupdC->pupd4 = 1;
    pPupdC->pupd5 = 1;

    // 5. Tarama
    for(;;)
    {
     for(int s=0; s<SATIR; s++){
    	 GPIOB_ODR &= ~(1 << satirlar[s]);
    	 for(int c=0; c<SUTUN; c++)
    	 {
    		 if(((GPIOC_IDR >> sutunlar[c]) & 1) == 0){
    			 printf("%u\n", tuslar[s][c]);
    			 delay(300000);
    		 }
    	 }
    	 GPIOB_ODR |= (1 << satirlar[s]);
     }
}
}
void delay(uint32_t count)
{
    for(volatile uint32_t i = 0; i < count; i++);
}
