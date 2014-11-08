#include <RASLib/inc/common.h>
#include <RASLib/inc/adc.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/servo.h>
#include <RASLib/inc/time.h>
#include <math.h>

//purple cat
//#define leftPos 0
//#define frontPos 0
//new comment
//Right now we are just doing the wall following code - Chris Sauceda 10/24/2014 7:56 PM
//2 IR sensors will be needed (for addressing the corners of course)
static tADC *adc[2];
static tBoolean initialized = false;
static tMotor *motors[2]; //driving servos left motor - 0 right motor - 1
//static tServo *rotor;

/*
*	This method is going to convert the given float (which should be the value returned by ADCread) to a normalized distance in centimeters. The formula was taken from an exponential regression on the data points given by the sharp sensor's distance versus voltage output chart.
* Becomes more inaccurate as distance gets smaller.
*/
/*
float convertDist(float adcValue)
{
	return 180.0 * powf(0.010068, adcValue); 
}
*/
/*
float takeLeftRead(void)
{
	//SetServo(rotor, leftPos); //Move the IR sensor to the left facing position
	Wait(250); //Give the servo some time to move and the IR sensor some time to stabilize.
	return convertDist( ADCRead(adc) ); //returns value in cm.
	
}

float takeFrontRead(void)
{
	SetServo(rotor, frontPos); //Move the IR sensor to the right facing position
	Wait(250); //Give the servo some time to move and the IR sensor some time to stabilize.
	return convertDist( ADCRead(adc) ); //returns value in cm.
}
*/
void initDevices(void) 
{
    // don't initialize this if we've already done so
    if (initialized) 
		{
        return;
    }
    
    initialized = true;

    adc[0] = InitializeADC( PIN_D0 ); //left wheel's IR sensor
		adc[1] = InitializeADC( PIN_D1 ); //right wheel's IR sensor
		
		motors[0] = InitializeServoMotor(PIN_B3, false); //left motor 
		motors[1] = InitializeServoMotor(PIN_C4, true); //right motor
		
		//rotor = InitializeServo(PIN_C5); //the IR sensor is mounted onto this servo.
}

int main(void) 
{
		float valueL, valueR, IRthreshold = 0.45;
		initDevices(); //initialize ALL of the components in one fell sweep.	
		while(1)
		{
			valueL = ADCRead(adc[0]);
			valueR = ADCRead(adc[1]);
			if( valueL > IRthreshold )
			{
				SetMotor(motors[0], 0.5);
				SetMotor(motors[1], 1);
			}
			else if( valueR > IRthreshold)
			{
				SetMotor(motors[1], 0.5);
				SetMotor(motors[0], 1);
			}
			else
			{
				SetMotor(motors[1], 0.5);
				SetMotor(motors[0], 0.5);
			}
		}
	
}

