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
			setMotorSpeed(motorC,-y1/1.28);
			setMotorSpeed(motorB,-y2/1.28);
		}
		else
		{
			setMotorSpeed(motorC, 0);
			setMotorSpeed(motorB, 0);
		}
		if(b>0)
		{
			flag = 1;
		}
		if((flag==1)&&(getMotorEncoder(motorA)<180))
		{
			setMotorSpeed(motorA,100);
			sleep(10);
			if(getMotorEncoder(motorA)>=175)
			{
				flag = 0;
			}
		}
		if((flag==0)&&(getMotorEncoder(motorA)>5))
		{
			setMotorSpeed(motorA,-45);
			sleep(10);
		}
		if((flag==0)&&(getMotorEncoder(motorA)<=5))
		sleep(10);
	}
}
