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
#include "interruptTIMER.h"

CY_ISR(Custom_TIME_ISR)
{  
    if(Timer_ReadStatusRegister()){
    time+=1;
    }
}

/* [] END OF FILE */
