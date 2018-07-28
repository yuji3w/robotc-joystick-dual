#include "JoystickDriver.c";

task main()
{
	TJoystick joystick;
	//	while(1)
	{
		getJoystickSettings(joystick);
		float y1=joystick.joy1_y1+1;
		float y2=joystick.joy1_y2+1;
		float b=joystick.joy1_TopHat;
		float shady = -y1/1.28;
		float shadx = -y2/1.28;
		if((y1>5 || y1<-5) || (y2>5 || y2<-5))
		{
			setMotorSpeed(motorC,-y1/1.28);
			setMotorSpeed(motorB,-y2/1.28);
		}
		if(b>0)
		{
			resetMotorEncoder(motorA);
			while(getMotorEncoder(motorA)<.25)
			{
				setMotorSpeed(motorA,50);
				sleep(100);
			}
			setMotorSpeed(motorA,0);
			sleep(150);
			resetMotorEncoder(motorA);
			while(getMotorEncoder(motorA)>-.25)
			{
				setMotorSpeed(motorA,-50);
				sleep(100);
			}
			setMotorSpeed(motorA,0);
			return;
		}
		else
		{
			setMotorSpeed(motorA,0);
		}
		sleep(100);
	}
}
