/*
 * clkgpio.h
 *
 *  Created on: 15 Kas 2026
 *      Author: Yiğit Durmaz
 */

#ifndef CLKGPIO_H_
#define CLKGPIO_H_



#endif /* CLKGPIO_H_ */
#include <stdint.h>


typedef struct{
	uint32_t gpioa_en:1;
	uint32_t gpiob_en:1;
	uint32_t gpioc_en:1;
	uint32_t gpiod_en:1;
	uint32_t gpioe_en:1;
	uint32_t gpiof_en:1;
	uint32_t gpiog_en:1;
	uint32_t reserved1:5;
	uint32_t adc12_en:1;
	uint32_t adc345_en:1;
	uint32_t reserved2:1;
	uint32_t dac1_en:1;
	uint32_t dac2_en:1;
	uint32_t dac3_en:1;
	uint32_t dac4_en:1;
	uint32_t reserved3:4;
	uint32_t aes_en:1;
	uint32_t reserved4:1;
	uint32_t rng_en:1;
	uint32_t reserved:5;
}RCC_AHB2ENR_t;

typedef struct{
	uint32_t mode0:2;
	uint32_t mode1:2;
	uint32_t mode2:2;
	uint32_t mode3:2;
	uint32_t mode4:2;
	uint32_t mode5:2;
	uint32_t mode6:2;
	uint32_t mode7:2;
	uint32_t mode8:2;
	uint32_t mode9:2;
	uint32_t mode10:2;
	uint32_t mode11:2;
	uint32_t mode12:2;
	uint32_t mode13:2;
	uint32_t mode14:2;
	uint32_t mode15:2;
}GPIOx_MODER_t;

typedef struct{
	uint32_t id0:1;
	uint32_t id1:1;
	uint32_t id2:1;
	uint32_t id3:1;
	uint32_t id4:1;
	uint32_t id5:1;
	uint32_t id6:1;
	uint32_t id7:1;
	uint32_t id8:1;
	uint32_t id9:1;
	uint32_t id10:1;
	uint32_t id11:1;
	uint32_t id12:1;
	uint32_t id13:1;
	uint32_t id14:1;
	uint32_t id15:1;
}GPIOx_IDR_t;

typedef struct{
	uint32_t od0:1;
	uint32_t od1:1;
	uint32_t od2:1;
	uint32_t od3:1;
	uint32_t od4:1;
	uint32_t od5:1;
	uint32_t od6:1;
	uint32_t od7:1;
	uint32_t od8:1;
	uint32_t od9:1;
	uint32_t od10:1;
	uint32_t od11:1;
	uint32_t od12:1;
	uint32_t od13:1;
	uint32_t od14:1;
	uint32_t od15:1;
}GPIOx_ODR_t;

typedef struct{
	uint32_t pupd0:2;
	uint32_t pupd1:2;
	uint32_t pupd2:2;
	uint32_t pupd3:2;
	uint32_t pupd4:2;
	uint32_t pupd5:2;
	uint32_t pupd6:2;
	uint32_t pupd7:2;
	uint32_t pupd8:2;
	uint32_t pupd9:2;
	uint32_t pupd10:2;
	uint32_t pupd11:2;
	uint32_t pupd12:2;
	uint32_t pupd13:2;
	uint32_t pupd14:2;
	uint32_t pupd15:2;
}GPIOx_PUPDR;

