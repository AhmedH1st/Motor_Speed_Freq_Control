//#define F_CPU 16000000
#include "STD_TYPES.h"
#include "util/delay.h"
#include "Keypad_interface.h"
#include "LCD_interface.h"
#include "Timer0_interface.h"
#include "DC_Motor.h"
#include "ConfigurableD_F_proj.h"



void MotorControl_Freq_duty_Init (void)
{
	u8 PB=NO_PRESSED_KEY;
	u8 duty=0;
	u32 freq=0;

	H_LCD_Writestr("WELCOME IN MOTOR");
	H_LCD_GoTOAddress_UsingLine_Col(LINE_2,DIgit_5);
	H_LCD_Writestr("PROJECT");
	_delay_ms(2000);
	H_LCD_ClearDisplay();
	H_LCD_Writestr("DESIGNED BY:");
	H_LCD_GoTOAddress_UsingLine_Col(LINE_2,DIgit_1);
	H_LCD_Writestr("AHMED HESHAM");
	_delay_ms(3000);
	H_LCD_ClearDisplay();


	H_LCD_Writestr("Enter the Duty Cylce");
	H_LCD_GoTOAddress_UsingLine_Col(LINE_2,DIgit_1);


		while(PB != '=')
		{
			PB=H_KEYPAD_u8_getPressedKey();
			if (PB != NO_PRESSED_KEY)
			{
				if(PB>='0' && PB<='9')
				{
					H_LCD_WriteChar(PB);
					duty=(duty*10)+(PB-'0');
				}
			}
		}

		H_LCD_ClearDisplay();
		H_LCD_Writestr("Enter the Frequency");
		H_LCD_GoTOAddress_UsingLine_Col(LINE_2,DIgit_1);
		PB=NO_PRESSED_KEY;

		while(PB != '=')
		{
			PB=H_KEYPAD_u8_getPressedKey();
			if (PB != NO_PRESSED_KEY)
			{
				if(PB>='0' && PB<='9')
				{
					H_LCD_WriteChar(PB);
					freq=(freq*10)+(PB-'0');
				}
			}
		}

	H_void_Motor_Start_Cw();
	M_void_Timer_SetPhaseCorrectPWM(freq, duty);


	H_LCD_ClearDisplay();
	H_LCD_Writestr("Duty=");
	H_LCD_WriteNum(duty);
	H_LCD_GoTOAddress_UsingLine_Col(LINE_2,DIgit_1);
	H_LCD_Writestr("Frequency=");
	H_LCD_WriteNum(freq);
	//_delay_ms(2000);
	//H_LCD_ClearDisplay();
	H_LCD_GoTOAddress_UsingLine_Col(LINE_3,DIgit_1);
	H_LCD_Writestr("Press + to Change");
	H_LCD_GoTOAddress_UsingLine_Col(LINE_4,DIgit_1);
	H_LCD_Writestr("Setting Any time");
}


void MotorControl_Freq_duty_Runnable (void)
{
	u8 PB=NO_PRESSED_KEY;
	u8 duty=0;
	u32 freq=0;

	while (PB != '+')
	{
		PB=H_KEYPAD_u8_getPressedKey();
	}

	PB=NO_PRESSED_KEY;
	H_LCD_ClearDisplay();


	H_LCD_Writestr("Enter the Duty Cylce");
	H_LCD_GoTOAddress_UsingLine_Col(LINE_2,DIgit_1);


	while(PB != '=')
	{
		PB=H_KEYPAD_u8_getPressedKey();
		if (PB != NO_PRESSED_KEY)
		{
			if(PB>='0' && PB<='9')
			{
				H_LCD_WriteChar(PB);
				duty=(duty*10)+(PB-'0');
			}
		}
	}

	H_LCD_ClearDisplay();
	H_LCD_Writestr("Enter the Frequency");
	H_LCD_GoTOAddress_UsingLine_Col(LINE_2,DIgit_1);
	PB=NO_PRESSED_KEY;

	while(PB != '=')
	{
		PB=H_KEYPAD_u8_getPressedKey();
		if (PB != NO_PRESSED_KEY)
		{
			if(PB>='0' && PB<='9')
			{
				H_LCD_WriteChar(PB);
				freq=(freq*10)+(PB-'0');
			}
		}
	}

	M_void_Timer_SetPhaseCorrectPWM(freq, duty);

	H_LCD_ClearDisplay();
	H_LCD_Writestr("Duty=");
	H_LCD_WriteNum(duty);
	H_LCD_GoTOAddress_UsingLine_Col(LINE_2,DIgit_1);
	H_LCD_Writestr("Frequency=");
	H_LCD_WriteNum(freq);
	//_delay_ms(2000);
	//H_LCD_ClearDisplay();
	H_LCD_GoTOAddress_UsingLine_Col(LINE_3,DIgit_1);
	H_LCD_Writestr("Press + to Change");
	H_LCD_GoTOAddress_UsingLine_Col(LINE_4,DIgit_1);
	H_LCD_Writestr("Setting Any time");
}
