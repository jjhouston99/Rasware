#include <RASLib/inc/common.h>
#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>

#include <RASLib/inc/motor.h>

// Blink the LED to show we're on
tBoolean blink_on = true;

void blink(void) {
    SetPin(PIN_F3, blink_on);
    blink_on = !blink_on;
}


// The 'main' function is the entry point of the program
int main(void) {
    // Initialization code can go here
    CallEvery(blink, 0, 0.5);
    
	tMotor *Servo = InitializeServoMotor(PIN_A6, false);
	tMotor *Servo2 = InitializeServoMotor(PIN_A7, false);

    while (1) {
        // Runtime code can go here
        Printf("Hello World!\n");

	SetMotor(Servo, 1);
	SetMotor(Servo2, 1);
        
    }
}
