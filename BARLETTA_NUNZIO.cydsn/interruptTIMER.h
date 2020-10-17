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
#ifndef __INTERRUPT_TIMER_H
    #define __INTERRUPT_TIMER_H
    #include "cytypes.h"
    #include "Timer.h"
  
    uint8_t time;
    
    CY_ISR_PROTO(Custom_TIME_ISR);

#endif
/* [] END OF FILE */
