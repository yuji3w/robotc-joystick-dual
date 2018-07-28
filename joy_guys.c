#include "JoystickDriver.c";

task main()
{
	TJoystick joystick;
	while(1)
	{
		getJoystickSettings(joystick);
		float y1=joystick.joy1_y1+83;
		float y2=joystick.joy1_y2-83;
		float b=joystick.joy1_Buttons;
		setMotorSpeed(motorB,-y1/1.28);
		setMotorSpeed(motorC,-y2/1.28);
		if(b>0)
		{
			setMotorSpeed(motorA,50);
			setMotorSpeed(motorD,50);
		}
		else
		{
			setMotorSpeed(motorA,0);
			setMotorSpeed(motorD,0);
		}
		sleep(100);
	}
}
