#include "JoystickDriver.c";

float y1, y2, b, shady, shadx;
int flag = 0;

task main()
{
	TJoystick joystick;
	resetMotorEncoder(motorA);
	while(1)
	{
		getJoystickSettings(joystick);
		y1=joystick.joy1_y1+1;
		y2=joystick.joy1_y2+1;
		b=joystick.joy1_TopHat;
		shady = -y1/1.28;
		shadx = -y2/1.28;
		if((y1>5 || y1<-5) || (y2>5 || y2<-5))
		{
			setMotorSpeed(motorD,-y1/1.28);
			setMotorSpeed(motorA,-y2/1.28);
		}
		else
		{
			setMotorSpeed(motorA, 0);
			setMotorSpeed(motorD, 0);
		}
		if(b>0)
		{
			setMotorSpeed(motorD,-100);
		}
	}
}
