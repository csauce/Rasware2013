#include <RASLib/inc/common.h>
#include <RASLib/inc/adc.h>
#include <RASLib/inc/motor.h>

//Right now we are just doing the wall following code - Chris Sauceda 10/24/2014 7:56 PM
//2 IR sensors will be needed (for addressing the corners of course)
static tADC *adc;
static tBoolean initialized = false;
static tMotor *motors[2]; //driving servos left motor - 0 right motor - 1

void initDevices(void) 
{
    // don't initialize this if we've already done so
    if (initialized) 
		{
        return;
    }
    
    initialized = true;

    // initialize 2 pins to be used for ADC input
    adc = InitializeADC( PIN_D0 ); //again, side IR sensor
		
		motors[0] = InitializeServoMotor(PIN_B3, false); //left motor 
		motors[1] = InitializeServoMotor(PIN_C4, true); //right motor
		
}

int main(void) 
{
		initDevices(); //initialize ALL of the components in one fell sweep.
		/*
		*
		* 
		* Just some testing code to verify motor functionality (it's below)
		*/
		while(1)
		{
			SetMotor(motors[0], 1.0); 
			SetMotor(motors[1], 1.0);
		}
}
