/*
 * EEPROM.c
 *
 * Created: 09-Nov-17 2:24:38 PM
 * Author : Thijs
 */ 

#include <avr/io.h>
#include <stdint.h>
#include <avr/eeprom.h>

uint16_t EEMEM name_addr;
uint16_t EEMEM status_addr;
uint16_t EEMEM maxt_addr;
uint16_t EEMEM mint_addr;
uint16_t EEMEM maxroll_addr;
uint16_t EEMEM minroll_addr;


void init_eeprom ()
{
	if (eeprom_is_ready())
		{
			eeprom_update_word(name_addr, "Arduino1");
			eeprom_update_word(status_addr, "up");
			eeprom_update_byte(maxt_addr, 0x1E);
			eeprom_update_byte(mint_addr, 0x18);
			eeprom_update_byte(maxroll_addr, 0xA0);
			eeprom_update_byte(minroll_addr, 0x05);
		}
}

void updatename(nameupdate){
	if(eeprom_is_ready()){
		eeprom_update_word(name_addr, nameupdate);
	}
}

void updatestatus(statusupdate){
	if(eeprom_is_ready()){
		eeprom_update_word(status_addr, statusupdate);
	}
}

void updatemaxtemp(maxtempupdate){
	if(eeprom_is_ready()){
		eeprom_update_byte(maxt_addr, maxtempupdate);
	}
}

void updatemintemp(mintempupdate){
	if(eeprom_is_ready()){
		eeprom_update_byte(mint_addr, mintempupdate);
	}
}

void updatemaxroll(maxrollupdate){
	if(eeprom_is_ready()){
		eeprom_update_byte(maxroll_addr, maxrollupdate);
	}
}

void updateminroll(minrollupdate){
	if(eeprom_is_ready()){
		eeprom_update_byte(minroll_addr, minrollupdate);
	}
}

void getname(){
	if(eeprom_is_ready()){
		eeprom_read_word(name_addr);
	}
}

void getstatus(){
	if(eeprom_is_ready()){
		eeprom_read_word(status_addr);
	}
}

void getmaxtemp(){
	if(eeprom_is_ready()){
		eeprom_read_byte(maxt_addr);
	}
}

void getmintemp(){
	if(eeprom_is_ready()){
		eeprom_read_byte(mint_addr);
	}
}

void getmaxroll(){
	if(eeprom_is_ready()){
		eeprom_read_byte(maxroll_addr);
	}
}

void getminroll(){
	if(eeprom_is_ready()){
		eeprom_read_byte(minroll_addr);
	}
}