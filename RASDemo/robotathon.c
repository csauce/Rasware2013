#include <RASLib/inc/common.h>
#include <RASLib/inc/adc.h>

static tADC *adc[1];
static tBoolean initialized = false;

void initIRSensor(void) {
    // don't initialize this if we've already done so
    if (initialized) {
        return;
    }
    
    initialized = true;

    // initialize 4 pins to be used for ADC input
    adc[0] = InitializeADC(PIN_D1);
}

int main(void) {
		initIRSensor();
    Printf("Press any key to quit\n");
        
    // loop as long as the user doesn't press a key 
    while (!KeyWasPressed()) {
        Printf(
            "IR values:  %1.3f\r",
            ADCRead(adc[0])
            );
    }
  
    Printf("\n");
}
