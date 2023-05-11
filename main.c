/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : main.c                                    	     	 */
/* Date          : May 11, 2023                                          */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/

#include "main.h"

int main(){
	/* Initialization */
	app_init();
	u8 myString[7];
	f64 distance;
	while(1){
		/* Read sensor */
		HCSR04_vGet_Reading(&distance);
		/* Display reading on LCD */
		dtostrf(distance, 2, 2, (char*)myString);
		LCD_4bit_vSendString_pos(&myLCD, (u8*)"         ", ROW2, 5);
		LCD_4bit_vSendString_pos(&myLCD, myString, ROW2, 5);
		LCD_4bit_vSendString(&myLCD, (u8*)"cm");
		/* change delay value */
		if(5 >= distance){
			delay = delay_high_risk;
		}
		else if((5 < distance) && (distance <= 10)){
			delay = delay_short_distance;
		}
		else if((10 < distance) && (distance <= 15)){
			delay = delay_medium_distance;
		}
		else if((15 < distance) && (distance <= 20)){
			delay = delay_long_distance;
		}
		else if((20 < distance) && (distance <= 30)){
			delay = delay_far_distance;
		}
		else{ delay = delay_not_in_range; }
		buzzer_alarm();
		_delay_ms(150);
	}
	return 0;
}

void buzzer_alarm(){
	if(delay_high_risk == delay){
		BUZZER_vTurnOn(&myBUZZER);
	}
	else if(delay_short_distance == delay){
		BUZZER_vTurnOn(&myBUZZER);
		_delay_ms(50);
		BUZZER_vTurnOff(&myBUZZER);

	}
	else if(delay_medium_distance == delay){
		BUZZER_vTurnOn(&myBUZZER);
		_delay_ms(100);
		BUZZER_vTurnOff(&myBUZZER);
		_delay_ms(50);
	}
	else if(delay_long_distance == delay){
		BUZZER_vTurnOn(&myBUZZER);
		_delay_ms(100);
		BUZZER_vTurnOff(&myBUZZER);
		_delay_ms(300);
	}
	else if(delay_far_distance == delay){
		BUZZER_vTurnOn(&myBUZZER);
		_delay_ms(50);
		BUZZER_vTurnOff(&myBUZZER);
		_delay_ms(500);
	}
	else if(delay_not_in_range == delay){
		BUZZER_vTurnOff(&myBUZZER);
	}
	else{ /* Do Nothing */ }
}

void app_init(){
	BUZZER_vInit(&myBUZZER);
	LCD_4bit_vInit(&myLCD);
	HCSR04_vInit();
	LCD_4bit_vSendString_pos(&myLCD, (u8*)"Distance", ROW1, 5);
}
