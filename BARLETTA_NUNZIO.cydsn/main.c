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

#include "interruptUART.h" /*include relativo all'header della isr del UART
                            in questo header sono inclusi anche "cytypes.h" e "UART.h"*/
#include "InterruptRoutines.h" //include relativo all'header della isr del timer
#include "main.h" /*include relativo a:
                   -inizializzazioni di variabili per il main;
                   -funzioni per il controllo dei canali del led RGB tramite i due pwm*/


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    UART_ISR_StartEx(Custom_UART_RX_ISR); //enable della isr relativa alla UART
    TIMER_ISR_StartEx(Custom_TIMER_ISR); //enable della isr relativa al Timer
    UART_Start(); //start per la UART
    Timer_Start(); //start per il timer
    RGBLed_Start(); //start per i pwm RG e Blue (pwm per il rosso e verde, pwm per il blu)
    
    //inizializzazione di variabili descritte nel "main.h"
    flag=0;
    value=0;
    cont=0;
    //variabile usata per il conteggio dei 5 secondi ed inizializzata in "InterruptRoutines.h"
    time=0;
    //variabile usata come flag per indicare l'avvenuta trasmissione di un dato da app a PSoC
    rec=0;//inizializzata in "interruptUART.h"
    
    for(;;)
    {
        //stato per la connessione con la applicazione per la recezione colori
        if(!flag && rec){
            rec=0;
            time=0;
            value=UART_ReadRxData();
            UART_ClearRxBuffer();
            if(value=='v'){
                flag=1;
                UART_PutString(aaa);
            }
        }
        
        //stato di ascolto in attesa del byte di header per la recezione colori
        if (flag && rec && !cont){
            rec=0;
            time=0;
            value=UART_ReadRxData();
            UART_ClearRxBuffer();
            if(value==0xA0){
                time=0;
                cont=1;
            }
        }
        
        //controllo trasmissione tra byte che deve avvenire entro 5 secondi
        if(cont!=0 && time==5 && flag){
           UART_PutString("\nK");
           cont=0;
           time=0;
           value=0;
        }
        
        //stato di recezione dei 3 byte relativi al rosso, verde e blu
        if(cont>0 && cont<4 && rec && flag){
            rec=0;
            time=0;
            col[cont-1]=UART_ReadRxData();
            UART_ClearRxBuffer();
            //UART_PutString("\n-1");
            cont+=1;
        }
        
        //stato di recezione dell'ultimo byte di trasmissione
        if (flag && rec && cont==4){
            rec=0;
            value=UART_ReadRxData();
            UART_ClearRxBuffer();
            //UART_RGB_PutString("\n-4");
            if(value==0xC0){
                RGBLed_WriteColor(); 
                cont=0;
            }else{
                UART_PutString("error");
                cont=0;
                value=0;
            }
        }
           
    }
}

/* [] END OF FILE */
