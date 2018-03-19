#include "save_to_internal_eeprom.h"

HAL_StatusTypeDef WRITE_INTERNAL_EEPROM(void * data, uint16_t size, uint32_t address) {
	HAL_StatusTypeDef status;
	uint8_t * wsk = (uint8_t*) data;
	address =address + 0x08080000;
	HAL_FLASHEx_DATAEEPROM_Unlock();  //Unprotect the EEPROM to allow writing
	while(size-- && status == HAL_OK){
		status = HAL_FLASHEx_DATAEEPROM_Program(TYPEPROGRAMDATA_BYTE, address,*wsk++);
		address ++;
	}
	HAL_FLASHEx_DATAEEPROM_Lock();  // Reprotect the EEPROM
	return status;
}

void READ_INTERNAL_EEPROM(void * data , uint16_t size, uint32_t address){
	uint8_t * wsk = data;
	address = address + 0x08080000;
	    while(size--){
	    	*wsk++ = *(__IO uint8_t*)address;
	    	address ++;
	    }

}
