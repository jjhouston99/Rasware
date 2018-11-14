#include <RASLib/inc/common.h>
#include <RASLib/inc/gpio.h>
#include <RASLib/inc/time.h>
#include <RASLib/inc/adc.h>
#include <RASLib/inc/motor.h>
#include <RASLib/inc/linesensor.h>
// Blink the LED to show we're on
tBoolean blink_on = true;

void blink(void) {
    SetPin(PIN_F3, blink_on);
    blink_on = !blink_on;
}
/*void values(tADC * ADC1, tADC * adcline){
	Printf("IR Value : %f\n",ADCRead(ADC1));
	Printf("Line Sensor Value: %f\n", ADCRead(adcLine));
	
}*/
// The 'main' function is the entry point of the program
int main(void) {
    // Initialization code can go here
	tADC *ADC1 = InitializeADC(PIN_D0);
	//tLineSensor *line = InitializeGPIOLineSensor(PIN_B0);
	tADC *line1 = InitializeADC(PIN_D1);
	tADC *line2 = InitializeADC(PIN_D2);
	tADC *line3 = InitializeADC(PIN_D3);
	float linevals[8];
    	CallEvery(blink, 0, 0.5);
    	//CallEvery(values(ADC1,adcLine),0,1.0);
	tMotor *servoLeft = InitializeServoMotor(PIN_A6, false); //left motor
	tMotor *servoRight = InitializeServoMotor(PIN_A7, false); //right motor
	
	SetMotor(servoRight, -.25); // 
	SetMotor(servoLeft, .25);
	
	
    while (1) {
        // Runtime code can go here
		//Printf("IR Value : %f\n",ADCRead(ADC1));

		//Printf("Line Sensor Value: %f\n", ADCRead(adcLine));
		//Wait(2.0);
		//LineSensorReadArray(line,linevals);
		//Printf("%f",linevals[0]);
		//Printf("%f\n", ADCRead(line1));

		//Printf(" LineSensor 1:%f\n",ADCRead(line1));
		//Printf("LineSensor 2:%f\n",ADCRead(line2));
		//Printf("LineSensor 2:%f\n",ADCRead(line3));
		
		//Distance Code
		if(ADCRead(ADC1) > .500){ //this block is prioritized 
		   SetMotor(servoLeft,1);
		   SetMotor(servoRight,-1);	
		}

		//Line Following Code:
		
		else if(ADCRead(line2) > .700){
		   SetMotor(servoLeft,-1);
		   SetMotor(servoRight,1);
		}
		else if(ADCRead(line1) > .700){
		   SetMotor(servoLeft,0);
		   SetMotor(servoRight,-.25);
		}
		else if(ADCRead(line3) > .700){
		   SetMotor(servoLeft,.25);
		   SetMotor(servoRight,0);
		}
		/*else if(ADCRead(line1) > .700 && ADCRead(line2) > .700 && ADCRead(line3) > .700 ){
		   SetMotor(servoRight,0);
		   SetMotor(servoLeft,0);		
		}*/
		else{
		   SetMotor(servoLeft, 0.75);
		   SetMotor(servoRight,0);
		}



    }
}

