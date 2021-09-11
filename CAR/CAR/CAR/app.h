/*
 * app.h
 *
 * Created: 11/9/2021 11:55:40 AM
 *  Author: OWNER
 */ 


#ifndef APP_H_
#define APP_H_

#include "Button_Driver/button.h"
#include "Motor_Driver/motor.h"
#include "macros.h"

void app_init()
{
	button_init(&PORTA,&DDRA,buttonG);
	button_init(&PORTA,&DDRA,buttonL);
	button_init(&PORTA,&DDRA,buttonM);
	button_init(&PORTA,&DDRA,buttonR);
	
	//led_init(&PORTB,&DDRB,led0); // used for debugging
	
	// Inintial State
	motor_init(&PORTC,&PORTC,&DDRC,&DDRC,motor1_IN1,motor1_IN2);
	motor_init(&PORTC,&PORTC,&DDRC,&DDRC,motor2_IN1,motor2_IN2);
	
	
}

void car_forward(void)
{
	move_forward(&PORTC,&PORTC,motor1_IN1,motor1_IN2);
	move_forward(&PORTC,&PORTC,motor2_IN1,motor2_IN2);
}

void car_bacwards(void)
{
	move_backwards(&PORTC,&PORTC,motor1_IN1,motor1_IN2);
	move_backwards(&PORTC,&PORTC,motor2_IN1,motor2_IN2);
}

void car_stop(void)
{
	stop(&PORTC,&PORTC,motor1_IN1,motor1_IN2);
	stop(&PORTC,&PORTC,motor2_IN1,motor2_IN2);
}

void car_rotate_left(void)
{
	move_forward(&PORTC,&PORTC,motor1_IN1,motor1_IN2);
	move_backwards(&PORTC,&PORTC,motor2_IN1,motor2_IN2);
	set_speed(30);

}

void car_rotate_right(void)
{
	move_forward(&PORTC,&PORTC,motor2_IN1,motor2_IN2);
	move_backwards(&PORTC,&PORTC,motor1_IN1,motor1_IN2);
	set_speed(30);

}

void setState(uint8_t state)
{
	if(state >= 0 && state!=3 )
	{
		car_forward();
		if(state == 0) set_speed(30);
		else if (state == 1) set_speed(60);
		else if (state == 2) set_speed(90);
	}
	else
	{
		car_bacwards();
		set_speed(30);
	}
}
uint8_t is_button_pressed(uint8_t button_bit_number)
{
	return button_pressed(&PINA,button_bit_number);
}

#endif /* APP_H_ */