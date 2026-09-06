
#define F_CPU 16000000UL
#include <util/delay.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "STEPPER.h"

int main(void) {
	stepperInit(); 

	while (1) {
		
		stepperRotate(STEPPER_CW,STEPPER_FULL_STEP ,360, 10);
		_delay_ms(1000);

		stepperRotate(STEPPER_CCW,STEPPER_FULL_STEP, 360, 10);
		_delay_ms(1000);
		
		stepperRotate(STEPPER_CW,STEPPER_HALF_STEP ,360, 10);
		_delay_ms(1000);

		stepperRotate(STEPPER_CCW,STEPPER_HALF_STEP, 360, 10);
		_delay_ms(1000);
	}

	return 0;
}
