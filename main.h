/*************************************************************************/
/* Author        : Omar Yamany                                    		 */
/* File          : main.h                                    	     */
/* Date          : May 11, 2023                                           */
/* Version       : V1                                                    */
/* GitHub        : https://github.com/Piistachyoo             		     */
/*************************************************************************/
#ifndef MAIN_H_
#define MAIN_H_

#include "HAL/BUZZER/buzzer_interface.h"
#include <util/delay.h>
#include "HAL/LCD_4bit/lcd_interface.h"
#include "HAL/HCSR04_Ultrasonic_Sensor/HCSR04.h"
#include <stdlib.h>

void buzzer_alarm();
void app_init();

#define delay_high_risk			0
#define delay_short_distance	1
#define delay_medium_distance	2
#define delay_long_distance		3
#define delay_far_distance		4
#define delay_not_in_range		5

buzzer_cfg myBUZZER = {.buzzer_port = PORTD, .buzzer_pin = PIN7};
LCD_4bit_cfg myLCD = {.LCD_PORT = PORTC, .LCD_RS_PIN = PIN0 ,.LCD_EN_PIN = PIN2,.LCD_RW_PIN = PIN1};

u8 delay;



#endif /* MAIN_H_ */
