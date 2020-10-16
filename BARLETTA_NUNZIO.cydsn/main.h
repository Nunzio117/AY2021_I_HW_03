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
    
    static void RGBLed_WriteRed(uint8_t red);
    static void RGBLed_WriteGreen(uint8_t green);
    static void RGBLed_WriteBlue(uint8_t blue);
    void RGBLed_Start();
    void RGBLed_Stop();
    void RGBLed_WriteColor();
    
    static char aaa[20]="RGB LED Program $$$\n";
    typedef struct {
        uint8_t red;
        uint8_t green;
        uint8_t blue;
    } Color;
    
    Color color;
    uint8 ba;
    uint8 value;
    uint8 cont,flag;
    
    void RGBLed_Start(){
    PWM_RG_Start(); // inizializza il dispositivo pwm RG
    PWM_BLUE_Start();  // inizializza il dispositivo pwm BLUE
    }

    void RGBLed_Stop(){
    PWM_RG_Stop(); // stoppa il dispositivo pwm RG.
    PWM_BLUE_Stop();  // stoppa il dispositivo pwm BLUE.
    }

    void RGBLed_WriteColor(){
    RGBLed_WriteRed(color.red);
    RGBLed_WriteBlue(color.blue);
    RGBLed_WriteGreen(color.green);
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
