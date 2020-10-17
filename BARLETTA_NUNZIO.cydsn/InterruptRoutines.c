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
#include "InterruptRoutines.h"

CY_ISR(Custom_TIMER_ISR)
{
    // Read TIMER Status Register -- Bring interrupt line low
    Timer_ReadStatusRegister();
    time+=1;
    
}

/* [] END OF FILE */
