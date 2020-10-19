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
#ifndef __MAIN_H
    #define __MAIN_H
    
    #include "stdio.h"
    #include "project.h"
    
    //inizializzazione delle funzioni che seguiranno
    static void RGBLed_WriteRed(uint8_t red);
    static void RGBLed_WriteGreen(uint8_t green);
    static void RGBLed_WriteBlue(uint8_t blue);
    void RGBLed_Start();
    void RGBLed_Stop();
    void RGBLed_WriteColor();
    
    //stringa che PSoC manda ad app dopo aver ricevuto il carattere 'v' dalla app stessa
    static char message[20]="RGB LED Program $$$"; 
    
    uint8 value; //variabile per lettura valori da app a PSoC
    uint8 cont; //variabile per il conteggio dei byte 
    uint8 connect; //variabile per indicare lo stato di connessione tra app e PSoC
    uint8_t color[3]={'\0'}; //array per contenere i 3 byte dei colori (RED, GREEN, BLUE)
    
    void RGBLed_Start(){
    PWM_RG_Start(); //inizializza il dispositivo pwm RG
    PWM_BLUE_Start();  //inizializza il dispositivo pwm BLUE
    }

    void RGBLed_Stop(){
    PWM_RG_Stop(); //stoppa il dispositivo pwm RG.
    PWM_BLUE_Stop();  //stoppa il dispositivo pwm BLUE.
    }
    
    //funzioni per gestire canali del led RGB tramite i pwm con i valori ricevuti da app
    void RGBLed_WriteColor(){
        RGBLed_WriteRed(color[0]);
        RGBLed_WriteGreen(color[1]);
        RGBLed_WriteBlue(color[2]);
    }
    void RGBLed_WriteRed(uint8_t red){
    PWM_RG_WriteCompare1(red);
    }
    void RGBLed_WriteGreen(uint8_t green){
    PWM_RG_WriteCompare2(green);
    }
    void RGBLed_WriteBlue(uint8_t blue){
    PWM_BLUE_WriteCompare(blue);
    }

#endif
/* [] END OF FILE */
