#ifndef __SAVE_TO_INTERNAL_EEPROM_H__
#define __SAVE_TO_INTERNAL_EEPROM_H__

#include "stm32l0xx_hal.h"

HAL_StatusTypeDef WRITE_INTERNAL_EEPROM(void * data, uint16_t size, uint32_t address);

void READ_INTERNAL_EEPROM(void * data , uint16_t size, uint32_t address);


#endif  // __SAVE_TO_INTERNAL_EEPROM_H__
