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
#include "project.h"
#include "interruptUART.h"
#include "stdio.h"
#include "UART_RGB.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_ISR_StartEx(Custom_UART_RX_ISR);
    UART_RGB_Start();
    EEPROM_Start();
    EEPROM_UpdateTemperature();
    uint8 value, flag;
    static char aaa[19]="RGB LED Program $$$";
    rec=0;
    cont=0;
    flag=0;
    value=0;
    //uint8 startAddress=0x0000;
    typedef struct{
        uint8_t red;
        uint8_t green;
        uint8_t blue;
    } color;
    
    color c;
    uint8 ba;
    for(;;)
    {
        if(rec==1){
            value=UART_RGB_ReadRxData();
            UART_RGB_ClearRxBuffer();
            rec=0;
            cont+=1;
            if (value == 0xA0){
                cont=0;
            }
         }
        if(value=='v'&& !flag){
            flag=1;
            UART_RGB_PutString(aaa);
            cont=0;
        }
        if(flag){
            switch(cont){
                case 4: 
                    cont=0;
                    flag=0;
                    break;
                case 1: 
                    EEPROM_WriteByte(value,0x00);
                    ba= EEPROM_ReadByte(0x00);
                    //c.red = value;
                    break;
                case 2:
                    EEPROM_WriteByte(value,0x01);
                    ba= EEPROM_ReadByte(0x01);
                    //c.green = value;
                    break;
                case 3:
                    EEPROM_WriteByte(value,0x02);
                    ba= EEPROM_ReadByte(0x02);
                    //c.blue = value;
                    break;
                 default:
                    break;
            }
        }
        
        /*
        while(rec && count<5){// rec è in interruptUART.h
            rec=0;
            EEPROM_WriteByte(UART_RGB_ReadRxData(),startAddress+count);
            count+=1;
            value=UART_RGB_ReadRxData();
            if(value=='v'){
                UART_RGB_PutString(aaa);
            }*/ /*
        }
        if (EEPROM_ReadByte(startAddress+count-1)==0xc0){
          count=0; 
        }*/
    }
}

/* [] END OF FILE */
