/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "interruptUART.h"
#include "InterruptRoutines.h"
#include "main.h"


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_ISR_StartEx(Custom_UART_RX_ISR);
    Timer_Start();
    TIME_ISR_StartEx(Custom_TIMER_ISR);
    UART_RGB_Start();
    RGBLed_Start();
    
    time=0;
    rec=0;
    flag=0;
    value=0;
    cont=0;
    
    for(;;)
    {
        
        if(!flag && rec){
            rec=0;
            time=0;
            value=UART_RGB_ReadRxData();
            UART_RGB_ClearRxBuffer();
            if(value=='v'){
                flag=1;
                UART_RGB_PutString(aaa);
            }
        }
        if (flag && rec && !cont){
            rec=0;
            time=0;
            value=UART_RGB_ReadRxData();
            UART_RGB_ClearRxBuffer();
            if(value==0xA0){
                time=0;
                cont=1;
            }
        }
        if(cont!=0 && time==5 && flag){
           UART_RGB_PutString("\nK");
           cont=0;
           time=0;
           value=0;
        }
        if(cont==1 && rec && flag){
            rec=0;
            color.red=UART_RGB_ReadRxData();
            UART_RGB_ClearRxBuffer();
            UART_RGB_PutString("\n-1");
            cont+=1;
        }
        if(cont==2 && rec && flag){
            rec=0;
            color.green=UART_RGB_ReadRxData();
            UART_RGB_ClearRxBuffer();
            UART_RGB_PutString("\n-2");
            cont+=1;
        }
         if(cont==3 && rec && flag){
            rec=0;
            color.blue=UART_RGB_ReadRxData();
            UART_RGB_ClearRxBuffer();
            UART_RGB_PutString("\n-3");
            cont+=1;
        }
        if (flag && rec && cont==4){
            rec=0;
            value=UART_RGB_ReadRxData();
            UART_RGB_ClearRxBuffer();
            UART_RGB_PutString("\n-4");
            RGBLed_WriteColor();
            cont=0;
            //flag=0;
        }
            
    
    }
}

/* [] END OF FILE */
