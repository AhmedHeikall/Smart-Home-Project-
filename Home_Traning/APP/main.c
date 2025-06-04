/*
 * Home_Traning.c
 *
 * Created: 17/11/2021 08:22:12 ص
 */ 
/*#include "FreeRTOS.h"
#include "task.h"*/
//#include "LEDS.h"
//#include "SERVO.h"
#include "BUZZER_RTOS.h"
#include "EPPROM.h"
#include "ENTERNAL_EPPROM.h"
#include "USART.h"
#include "keypad.h"
#include "BIT_MATH.h"
#include "TIMER.h"
#include <avr/interrupt.h>
#include "EXT_INIT.h"
#include "ADC.h"
#include "LED.h"
#include "BUZZER.h"
#include "LCD.h"
#include "SSD.h"
#include "PUSH_BUTTON.h"
# define F_CPU 16000000UL
#include <util/delay.h>
//extern u32 number_of_overflow ;
//extern u32 number_of_compare_match;

u8 Number_Of_PS=0;
u8 Uart_Data;
u8 i=0;
u8 int_flag = 0;
u8 Data_check[5];
/*Admin Password*/
u8 Entered_data[20]= "kha" ;
u8 Password_Leng=3;
/*LasT user in EEprom */


int main (void){
	u8 Last_user=0;
	

		u8 Admin_Selection=0;
		u8 User_Selection=0;
		u8 Password_Length=5;
		u8 Password_flag=0;
		
		
		u8 count =0 ;// iteration of error password
		u8 Key_Pad_reading=0 ;
		u8 i=0 ; //columns
		u8 arr[16];
		u8 *ptr=arr ;
		u8 array_len=0;
		u8 flag =0 ;
		u8 Admin_check=0;
        
	    u8 returned_value =1 ;
	    /*user passwords */
		
		
	    u8 User_One_Ps[3]="123";
	    u8 User_2_Ps[3]="456";
	    u8 User_3_Ps[3]="789";
	    u8 Keypad_LED_on[3]="*";
	    u8 Keypad_cond_On[3]="+";
	    u8 Keypad_cond_OFF[3]="-";
	
	H_BuzzerInit();
	SERVO_INIT();
	 SERVO_MOVE(7);
	TEMP_S_INIT();
	M_UsarIntInit();
	H_EppromInit();
	DC_INIT();
	H_LcdInit();
	KeypadInit();
    M_UsartSendString("Welcome To Admin Mode\r\nEnter Password\r\n\r\n");
	M_UsartSendString("you can OPen the Door Enter D =\r\n\r\n");
	M_UsartSendString("you can Close the Door Enter N =\r\n\r\n");
	M_UsartSendString("you can OPen the air conditioner Enter A=\r\n\r\n");
	M_UsartSendString("you can Run 6 leds Enter 1 To 6 A=\r\n\r\n");
	M_UsartSendString("You can also follow the system and see what users are doing\r\n\r\n");
	M_UsartSendString("You can also find out Last one from the register Enter L=\r\n\r\n");
    M_UsartSendString("Then Don't Forget Enter '='\r\n\r\n");
    H_LcdFirstLine();//mohim ykono bra
	H_Lcd_Write_String("User Mode");
	
	_delay_ms(2000);
	H_Lcd_Clear();
    H_Lcd_Write_String("Enter The PS ");
    H_LcdSecondLine();
    
	while(1){
		
		 Key_Pad_reading=KeypadRead();
		 
		 /*this loop to copy the number in array and print it in lcd */
		 while (i!=16 && Key_Pad_reading!='a')  
		 {
			 if (Key_Pad_reading=='C' || Key_Pad_reading=='=')
			 {
				 if(Key_Pad_reading=='C'){
					 
					 array_len=0;// storing from index 0 again
					 H_Lcd_Clear();
					 H_Lcd_Write_String("Enter The PS ");
					 
					 H_LcdSecondLine();//go to second line position 0
					 
					 }else if (Key_Pad_reading=='='){
					 flag=1 ;
					 
				 }
				 
				 }else{// hina else 34an mitba3at4 "C"
				 H_Lcd_Write_Char(Key_Pad_reading);
				 
				 arr[array_len]=Key_Pad_reading;// store the returned character in array
				 H_CoursorIncrement(); // Cursor increment
				 array_len++; //to store the new character in a next index
				 Number_Of_PS++;
			 }
			 /*It is on the ground, because the first time I finish reading it from the air, and the user enters the number, 
			 I will take this number and store it, and then leave the loop so that I can go to read again.*/
			 break;
			 
		 }
		 
		 if (flag==1){ // all of this if the user enter = this mean he completed his password 
			 /*this is flag fired when the user enter = this mean that he ended enter the data*/
			 
			 i=0 ;
			 array_len=0 ;
			// u8 res =Password(arr);*/
			 
			 
			 
			 
			 
			 arr[array_len];
			 
			 
			 

			/* this code to compare the entered data from the keypad in user mode 
			 and to select the position */
			
			 for(u8 i =0 ;i<3;++i){
				 if(Number_Of_PS !=3){
					 returned_value =0 ;
					 break;
				 }
				 if (User_One_Ps[i]!=arr[i]) { //i have  problem here that not valid to use && (Number_Of_PS !=3)
					 returned_value =0 ;
					 break;
				 }
			 }

			 if (returned_value ==0 )
			 {
				 for(u8 i =0 ;i<3;++i){
					 
					 if(User_2_Ps[i]!=arr[i]){
						 returned_value =2;
						 break;
					 }
			 }                                                         			 
		
			 }
			 if (returned_value ==2)
			 {
				 for(u8 i =0 ;i<3;++i){
					 if(User_3_Ps[i]!=arr[i]){
						 returned_value=3;
						 break;
					 }
				 }
		 } if (returned_value ==3)
		 {
			 for(u8 i =0 ;i<1;++i){
				 if(Keypad_LED_on[i]!=arr[i]){
					 returned_value=4;
					 break;
				 }
			 }
	 } if (returned_value ==4)
	 {
		 for(u8 i =0 ;i<1;++i){
			 if(Keypad_cond_On[i]!=arr[i]){
				 returned_value=5;
				 break;
			 }
		 }
 } if (returned_value ==5)
 {
	 for(u8 i =0 ;i<1;++i){
		 if(Keypad_cond_OFF[i]!=arr[i]){
			 returned_value=6;
			 break;
		 }
	 }
 }
			u8 res= returned_value;
		
		
			 				  
			 
			 
			 
			 
			 
			 /**************************Password Part ********************************************/
		
	 		 
			 if (res==1){
				 H_Lcd_Clear();
				 H_Lcd_Write_String("Welcome user1 ");
				// H_EppromWrite("user1",0b1010110);
				 H_LcdSecondLine();
				 M_UsartSendString("\r\nAdmin !!\r\n You have a message\r\n There is a user_One logged in\r\n");
				 
				 
				 }else if (res==0){
				 H_Lcd_Clear();
				 H_Lcd_Write_String("Welcome user2 ");
				H_EppromWrite("user2",0b10100100);
				 H_LcdSecondLine();
				 M_UsartSendString("\r\nAdmin !!\r\n You have a message\r\n There is a user_Two logged in\r\n");
			     }
			     else if (res==2){
				 H_Lcd_Clear();
				 H_Lcd_Write_String("Welcome user3 ");
				 H_LcdSecondLine();
				 H_EppromWrite("UU",0b10100100);
				  _delay_ms(100);
				 //M_UsartSendString("\r\nAdmin !!\r\n You have a message\r\n There is a user_Three logged in\r\n");
			//	 M_UsartSendString("The Last is \r\n");
			//_delay_ms(100);
			// M_UsartSendString(H_EppromRead(0b1010110));
				 }else if(res==3){
				 H_Lcd_Clear();
			     H_Lcd_Write_String("LED ON ");
				 SET_BIT(DDRC,3);
				 SET_BIT(PORTC,3);
				 M_UsartSendString("\r\nAdmin !!\r\n You have a message\r\n There is a user_RUN LED\r\n\r\n");
				
				 }else if(res==4){
				 H_Lcd_Clear();
				 
				 H_Lcd_Write_String("DC ON ");
				
					u8 p= TEMP_S_READ();
					if (p>=27)
					{
						DC_ON();
					}
			    }else if(res==5){
			    H_Lcd_Clear();
			    H_Lcd_Write_String("DC OFF ");				
					u8 n=TEMP_S_READ();
						if (n<27)
						{
							DC_OFF();
						}
				
				 M_UsartSendString("\r\nAdmin !!\r\n You have a message\r\n There is a user_OFF air conditioning\r\n\r\n");
				}
				  if(res==6){ // incorrect Password
				 //iteration of incorrect pasword 
				 count++ ;//kol ma hid5l hina hizid 1 l7ad 3 alarm
				 H_Lcd_Clear();
				 H_Lcd_Write_String("Incorrect Password ");

				 _delay_ms(1500);
				 H_Lcd_Clear();
				 H_Lcd_Write_String("Try Again ");
				 _delay_ms(1500);
				 H_Lcd_Clear();
				 H_Lcd_Write_String("Enter The PS ");
				 H_LcdSecondLine();
				 M_UsartSendString("\r\nBe aware ...\r\nthere are incorrect attempts to enter\r\n");
			 }
			 
			
			 
			 
			/***********/
			
			 
			 /**************************EEPROM And Storing The Last User  Part ********************************************/
			_delay_ms(100);
		 Last_user=H_EppromRead(0b10100100);
		 
		
		 
		
			 /***************************return any thing to the basic position to start new iteration*********************/
			 flag=0;
			 Number_Of_PS=0 ; // More Important to be Zero
			 
			 /***********************This To Select The Number Of iteration for Enter The ps********************************/
			 if (count>2)
			 {
				 /*this Count expresses the number of wrong iterations*/ 
				 H_Lcd_Clear();
				 H_Lcd_Write_String("Sorry Can't Open ");
				 H_BuzzerOn();
				 M_UsartSendString("\r\nBe aware ...\r\nthere are THREE incorrect attempts to enter\r\n");
				 
			 }
			 /**********if the Flag not 1 this mean the user still enter the number ***************************************/
			 }else{
			 ++i ;
		 }

		 
		                       
			   			     
	 }
	
} 


       

	
	ISR(USART_RXC_vect){
		
		
		
		
		Uart_Data=UDR; //الداتا بتاعك جهزت تعالي خدها
	
		
		/*I will take every letter that the user enters and store it so that 
		I can go to compare it. I will store it until I press =*/
			if (Uart_Data!='=')
			{
				                        /*Assign the entered data in array to check it */
				Data_check[i]=Uart_Data;
				++i;
				                       /*when the user completely enter the data that mean this data ready to compare */
			}else if (Uart_Data=='='){
			
		for (u8 j=0;j<i;j++)
		{ 
			                         /*Because it is about letters, so each letter will be compared to it alone*/
		if (Data_check[j]==Entered_data[j])
		{
			int_flag++ ;
		}else{
			                      /*make this equal 0to be ready for another iteration*/
			i=0;
			 
			/*LED Code*/
		}
			if (Data_check[i]=='1'){
				//i=0;
				/*switch on the led */
				SET_BIT(DDRC,2);
				SET_BIT(PORTC,2);
				/*Switch off the leds*/ 
			}if (Data_check[i]=='C')
			{
				CLR_BIT(PORTC,2);
				CLR_BIT(PORTC,3);
				CLR_BIT(PORTD,2);
				CLR_BIT(PORTD,3);
				CLR_BIT(PORTA,3);
				//CLR_BIT(PORTB,7);
			}
			if ((Data_check[i]=='2'))
			{
				SET_BIT(DDRC,3);
				SET_BIT(PORTC,3);
			//	i=0;
			}if (Data_check[i]=='3')
			{
				SET_BIT(DDRD,2);
				SET_BIT(PORTD,2);
			//	i=0;
			}if (Data_check[i]=='4')
			{
				 SET_BIT(DDRD,3);
				SET_BIT(PORTD,3);
				//i=0;
		   }
		   /*Close the Door*/
		   if (Data_check[i]=='A'){
		   SERVO_MOVE(5) ;
		   
	         }
			  if (Data_check[i]=='N'){
				  for(u8 i=0;i<10;++i){
					  SERVO_MOVE(i) ;
				  }
			 
			 /*Close the Door
			 }if (Data_check[i]=='B'){
				 SERVO_MOVE(5) ;
				 
			}*/
		   if (Data_check[i]=='5')
		   {
			SET_BIT(DDRA,4);
			SET_BIT(PORTA,4);
			//i=0;
	     }
			break;
		}
			/*here int_flag mean the number of valid char*/
		}if (int_flag==Password_Leng)
		{
			M_UsartSendString("Wellcome Admin \r\n");
			
		}
		
		/*Get ready, because when you come, you will never have a new operation*/
			i=0;
			int_flag=0;
			Uart_Data=0;
			//u8 Test_data[20];
			
		
		
		         
	          }
		   }
	ISR(USART_TXC_vect){
		
		
	}
	
	
	
	
	


  /* M_Timer_0_Set_Ctc(1500);
   M_Timer_0_Start();
  M_PwmFast_0_Set_Duty_cycle(70);
   M_PwmFast_0_Start();*/
   
  /*  H_LedInit(LED2);
	_delay_ms(5000);
	H_LedToggel(LED2);
	_delay_ms(5000);
	H_LedToggel(LED2);*/
		/*H_LedInit(LED0);
		H_BuzzerInit();
		H_BuzzerOn();
		H_LedOn(LED0);
		_delay_ms(100);
		H_LedOff(LED0);
		H_BuzzerOff();
		_delay_ms(100);
		H_LedInit(LED1);
		//H_BuzzerInit();
		H_BuzzerOn();
		H_LedOn(LED1);
		_delay_ms(100);
		H_LedOff(LED1);
		H_BuzzerOff();
		_delay_ms(100);
		H_LedInit(LED2);
		//H_BuzzerInit();
		H_BuzzerOn();
		H_LedOn(LED2);
		_delay_ms(100);
		H_LedOff(LED2);
		H_BuzzerOff();
		_delay_ms(100);
		H_BuzzerTwis();
		_delay_ms(100);
		H_BuzzerOff();
		*****************************************
		H_ButtonInit(BUTTON2);
		H_LedInit(LED2);
		H_BuzzerInit();
		while(1){
			u8 res =H_ButtonRead(BUTTON2);
			if (res==1)
			{
				H_LedToggel(LED2);
				_delay_ms(1000);
				H_BuzzerTwis();
				_delay_ms(100);
				H_BuzzerOff();
				
			}
			
		}*/
		/*
		H_SsdInit();
		while(1){
		u8 i =0;
		for(i=0;i<=9;++i){
				
			H_Ssd_2_Disable();
			H_Ssd_1_Display(i);
			_delay_ms(500);
			H_Ssd_1_Disable()
			
			if (i==9)
			{
		     	H_Ssd_1_Display(1);
				for(u8 x=0;x<=9;++x){
					H_Ssd_2_Display(i);
					_delay_ms(500);
					H_Ssd_2_Disable();
					if (x==9)
					{
						H_Ssd_2_Display(i);
						_delay_ms(500);
						H_Ssd_2_Disable();
					}
				}
			}
			
		}*/					 
		/*
		H_SsdInit();
		while(1){
			H_Ssd_1_Display(5);
			_delay_ms(5);
		
			for(u8 x=0;x<=9;x++){
				
				
				H_Ssd_2_Display(x);
				H_Ssd_1_Disable();
				_delay_ms(1);
				//_delay_ms(150);
				H_Ssd_2_Disable();
			}
			
		}*/
		
		
		
	/*	while(1){
			
			H_Lcd_Write_Data('k');
			H_Lcd_Write_Data('h');
			H_Lcd_Write_Data('a');
			H_Lcd_Write_Data('i');
			H_Lcd_Write_Data('r');
			H_Lcd_Write_Data('y');
			//M_AdcRead();
			//x=M_AdcRead();
			H_Lcd_Write_String("khairy");
			_delay_ms(5);
			H_Lcd_shift_data();
		//	H_Lcd_Write_Clear();
		
			
		}*/
	/*H_LcdInit();
	M_ExtInt_0_Init();
	H_LedInit(LED2);
	
		while(1){
			
			
			
		}
  
}

 ISR(INT0_vect){
	 _delay_ms(100);
	 H_LedToggel(LED2);
	 
	 
 }*/
	
	
     
	 
	/*H_Lcd_Write_Clear();
	_delay_ms(500);
	
	while(1){
		//H_Lcd_Write_String("ADC_VAL = ");
		x =M_AdcRead();
		H_LcdInteger(x);
		_delay_ms(5);
		H_Lcd_Write_Clear();
		
		
	}*/
	/*
	EppRom Code
	   H_LcdInit();
	   H_EppromInit();
	u8 x = 3 ;
	
	while (1)
	{
		
	
	
	
    H_EppromWrite(x,0b10100100);
	_delay_ms(100);
	u8 y=H_EppromRead(0b10100100);
	
	H_LcdInteger(y);
	++x;
	}*/
	


 /*ISR(TIMER0_COMP_vect){
	 static u32 y =0 ;
	if (y==number_of_compare_match)
	{
		H_LedToggel(LED0);
		y=0 ;
		
	}
	y++;
 }*/

