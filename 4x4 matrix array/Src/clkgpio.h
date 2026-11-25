#ifndef CLKGPIO_H_
#define CLKGPIO_H_

#include <stdint.h>

#define GPIOB_ODR  (*(volatile uint32_t*)(0x48000400 + 0x14))
#define GPIOC_IDR  (*(volatile uint32_t*)(0x48000800 + 0x10))


typedef struct {
    uint32_t gpioa_en  : 1;
    uint32_t gpiob_en  : 1;
    uint32_t gpioc_en  : 1;
    uint32_t gpiod_en  : 1;
    uint32_t gpioe_en  : 1;
    uint32_t gpiof_en  : 1;
    uint32_t gpiog_en  : 1;
    uint32_t reserved1 : 6;   // 5 → 6 düzeltildi
    uint32_t adc12_en  : 1;
    uint32_t adc345_en : 1;
    uint32_t reserved2 : 1;
    uint32_t dac1_en   : 1;
    uint32_t dac2_en   : 1;
    uint32_t dac3_en   : 1;
    uint32_t dac4_en   : 1;
    uint32_t reserved3 : 4;
    uint32_t aes_en    : 1;
    uint32_t reserved4 : 1;
    uint32_t rng_en    : 1;
    uint32_t reserved5 : 5;
} RCC_AHB2ENR_t;

typedef struct {
    uint32_t mode0 : 2;  uint32_t mode1 : 2;  uint32_t mode2 : 2;  uint32_t mode3 : 2;
    uint32_t mode4 : 2;  uint32_t mode5 : 2;  uint32_t mode6 : 2;  uint32_t mode7 : 2;
    uint32_t mode8 : 2;  uint32_t mode9 : 2;  uint32_t mode10 : 2; uint32_t mode11 : 2;
    uint32_t mode12 : 2; uint32_t mode13 : 2; uint32_t mode14 : 2; uint32_t mode15 : 2;
} GPIOx_MODER_t;

typedef struct {
    uint32_t pupd0 : 2;  uint32_t pupd1 : 2;  uint32_t pupd2 : 2;  uint32_t pupd3 : 2;
    uint32_t pupd4 : 2;  uint32_t pupd5 : 2;  uint32_t pupd6 : 2;  uint32_t pupd7 : 2;
    uint32_t pupd8 : 2;  uint32_t pupd9 : 2;  uint32_t pupd10 : 2; uint32_t pupd11 : 2;
    uint32_t pupd12 : 2; uint32_t pupd13 : 2; uint32_t pupd14 : 2; uint32_t pupd15 : 2;
} GPIOx_PUPDR_t;

#endif /* CLKGPIO_H_ */
