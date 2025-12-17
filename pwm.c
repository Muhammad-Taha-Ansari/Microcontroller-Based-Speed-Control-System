/*
 	The firmware used to generate square wave of desired
 	frequency and duty-cycle.

	Pin Connections:
	
	PA9 = square-wave output with varying duty

 	Created by: Furqan Nathani
 	Verified by: Furqan Nathani & Uzair Khan
 	Date: 19-October-2023

*/

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>

#define duty_cycle  40
#define reg_val		(uint32_t)(((float)duty_cycle/100.0)*8400)

/* 	setting timer1 for generating square-wave of 
	desired frequency & duty-cycle at PA9 */
void timer1_setup()
{
	// enable timer1 clock
	rcc_periph_clock_enable(RCC_TIM1);
	// edge aligned counter
	timer_set_alignment(TIM1,TIM_CR1_CMS_EDGE);
	// downcounting mode
	timer_direction_down(TIM1);
	// run forever
	timer_continuous_mode(TIM1);
	// new value of auto-reload register will be effective
	// immediately after writing
	timer_disable_preload(TIM1);
	// timer clock prescaler = 1+1 = 2
	// APB2 / 2 = 84 MHz / 2 = 42 MHz
	timer_set_prescaler(TIM1,1);
	// top value of the counter (set frequency of wave)
	timer_set_period(TIM1,8400);
	// set PWM mode on specific pin
	timer_set_oc_mode(TIM1,TIM_OC2,TIM_OCM_PWM1);
	// enabling preload required in PWM mode
	// as per reference manual
	timer_enable_oc_preload(TIM1,TIM_OC2);
	// enabling output compare pin of timer
	timer_enable_oc_output(TIM1,TIM_OC2);
	// enabling output pin automatically
	// on next update event
	timer_enable_break_automatic_output(TIM1);
	// set output compare register value (set duty cycle of wave)
	timer_set_oc_value(TIM1,TIM_OC2,reg_val);
	// setting update generation in 
	// event generation register as per
	// reference manual
	timer_generate_event(TIM1,TIM_EGR_UG);
	// initial value of the counter
	timer_set_counter(TIM1,0);
	// start timer
	timer_enable_counter(TIM1);
}

int main(void)
{
	rcc_clock_setup_pll(&rcc_hse_25mhz_3v3[RCC_CLOCK_3V3_84MHZ]);
	rcc_periph_clock_enable(RCC_GPIOA);
	
    /* Timer1 output pin (PA9) */
   gpio_mode_setup(GPIOA,GPIO_MODE_AF,
    	GPIO_PUPD_PULLDOWN,GPIO9);
	gpio_set_output_options(GPIOA,GPIO_OTYPE_PP,
		GPIO_OSPEED_25MHZ,GPIO9);
	gpio_set_af(GPIOA,GPIO_AF1,GPIO9);

	/* timer1 setup call */
	timer1_setup();
	/* do nothing */

	while(1)
	{
		__asm__("nop");
	}

	return 0;
}
