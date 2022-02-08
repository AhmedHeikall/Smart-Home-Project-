/*
 * DIO.c
 *
 * Created: 17/11/2021 08:25:11 ص
 *  Author: ascom
 */
#include "DIO_CFG.h" 
#include "DIO.h"
#include "REG.h"
#include "BIT_MATH.h"
#include "STD_TYPES.h"

void M_PinMode(u8 Pin,u8 Mode){
	
	/*check if is a portA*/
	if ((Pin>=PA_ST)&&(Pin<=PA_ST+PIN_NUMBER))
	{
		u8 x =Pin-PA_ST ; 
		if(Mode==OUTPUT){ 
	
		SET_BIT(DDRA,x);//make it output 
			
		}else if(Mode==INPUT){
			
		CLR_BIT(DDRA,x);
		}
		
		
		/*check if is a portB*/
     }else if((Pin>=PB_ST)&&(Pin<=PB_ST+PIN_NUMBER))
     {
		 
	   u8 x =Pin-PB_ST ;
	   if(Mode==OUTPUT){
	   	
		SET_BIT(DDRB,x);//make it output
		
		}else if(Mode==INPUT){
		
		CLR_BIT(DDRB,x);
	}
	
	
	/*check if is a portC*/
   }else if((Pin>=PC_ST)&&(Pin<=PC_ST+PIN_NUMBER))
  {
	  
	  u8 x =Pin-PC_ST ; 
	  if(Mode==OUTPUT){
	 SET_BIT(DDRC,x);//make it output
		  
	  } else if(Mode==INPUT){
		  
		  CLR_BIT(DDRC,x);
	  }
	  
	  
	  /*check if is a portD*/
   }else if ((Pin>=PD_ST)&&(Pin<=PD_ST+PIN_NUMBER))
  {
	  
	  u8 x =Pin-PD_ST ;
	  if(Mode==OUTPUT){
		  
     SET_BIT(DDRD,x);//make it output 
	 }else if(Mode==INPUT){
		  
		  CLR_BIT(DDRD,x);
	  }  
  }
}


/*THE IMPLEMENTATION OF THE WRITE FUNCYION */
void M_PinWrite(u8 Pin ,u8 Status){
	/*check if is a portA*/
	if ((Pin>=PA_ST)&&(Pin<=PA_ST+PIN_NUMBER))
	{
		u8 x =Pin-PA_ST ;
		if(Status==HIGH){
			/*make it +5V*/
	   SET_BIT(PORTA,x);
			
			}else if(Status==LOW){
			
			CLR_BIT(PORTA,x);
		}
		
		
		/*check if is a portB*/
	}else if((Pin>=PB_ST)&&(Pin<=PB_ST+PIN_NUMBER))
	{
		
		u8 x =Pin-PB_ST ;
		if(Status==HIGH){
			/*make it +5V*/
			SET_BIT(PORTB,x);
			
			}else if(Status==LOW){
			
			CLR_BIT(PORTB,x);
		}
		
		
		/*check if is a portC*/
	}else if((Pin>=PC_ST)&&(Pin<=PC_ST+PIN_NUMBER))
	{
		
		u8 x =Pin-PC_ST ;
		if(Status==HIGH){
			/*make it +5V*/
			SET_BIT(PORTC,x);
			
			} else if(Status==LOW){
			
			CLR_BIT(PORTC,x);
		}
		
		
		/*check if is a portD*/
	}else if ((Pin>=PD_ST)&&(Pin<=PD_ST+PIN_NUMBER))
	{
		
		u8 x =Pin-PD_ST ;
		if(Status==HIGH){
			/*make it +5V*/
			SET_BIT(PORTD,x);
			}else if(Status==LOW){
			
			CLR_BIT(PORTD,x);
		}
	}
}


/*the implementation of the read function*/
 u8 M_PinRead(u8 Pin ){
	 u8 res=0;
	     
		 /*check if is a portA*/
	 if ((Pin>=PA_ST)&&(Pin<=PA_ST+PIN_NUMBER)){
		 u8 x =Pin-PA_ST ;
		res= GET_BIT(PINA,x);
		
		/*check if is a portB*/
	 } else if((Pin>=PB_ST)&&(Pin<=PB_ST+PIN_NUMBER)){
		  u8 x =Pin-PB_ST ;
		  res= GET_BIT(PINB,x);
		  
		  
	 	/*check if is a portC*/
 	}else if((Pin>=PC_ST)&&(Pin<=PC_ST+PIN_NUMBER)){
		 
		 u8 x =Pin-PC_ST ;
		 res= GET_BIT(PINC,x);
		 
		 
	  	/*check if is a portD*/
	}else if((Pin>=PD_ST)&&(Pin<=PD_ST+PIN_NUMBER)){
	  	
	  	u8 x =Pin-PD_ST ;
	  	res= GET_BIT(PIND,x);
  	}
	 
	 return res ;
 }
 
 
 
 /*the implementation of the toggle function */
 void M_PinTog(u8 Pin){
	 
	 /*check if is a portA*/
	 if ((Pin>=PA_ST)&&(Pin<=PA_ST+PIN_NUMBER)){
		 	u8 x =Pin-PA_ST ;
		 TOG_BIT(PORTA,x);
		 
		 
		 /*check if is a portB*/
	 }else if((Pin>=PB_ST)&&(Pin<=PB_ST+PIN_NUMBER)){
	 u8 x =Pin-PB_ST ;
	 TOG_BIT(PORTB,x);
	 
	 
	 /*check if is a portC*/
    }else if((Pin>=PC_ST)&&(Pin<=PC_ST+PIN_NUMBER)){
    u8 x =Pin-PC_ST ;
    TOG_BIT(PORTC,x);
	
	
	/*check if is a portD*/
    }else if((Pin>=PD_ST)&&(Pin<=PD_ST+PIN_NUMBER)){
    u8 x =Pin-PD_ST ;
    TOG_BIT(PORTD,x);
    }
 }
 