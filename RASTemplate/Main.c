#include <RASLib/inc/common.h>
#include <RASLib/inc/servo.h>
#include <RASLib/inc/time.h>
#include <RASLib/inc/gpio.h>

void initServo(void);
void initServo2(void);

static tServo *servo;
static tServo *my_name;

static tBoolean initialized = false;
static tBoolean second = false;
float position = 1.0;


int main(void){
    //SetPin(PIN_C4, true);    
    initServo();
    SetServo(servo, position);
    
    //SetPin(PIN_B3, true);
    //initServo2();
    //SetServo(my_name, position);
}

void initServo() {
    // don't initialize this if we've already done so
    if (initialized) {
        return;
    }
    
    initialized = true;

    servo = InitializeServo(PIN_C4);
}

void initServo2() {
    // don't initialize this if we've already done so
    if (second) {
        return;
    }
    
    second = true;

    my_name = InitializeServo(PIN_B3);
}

