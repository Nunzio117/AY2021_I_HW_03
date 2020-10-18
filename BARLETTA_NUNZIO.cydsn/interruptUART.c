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

CY_ISR(Custom_UART_RX_ISR)
{  
    if (UART_ReadRxStatus() == UART_RX_STS_FIFO_NOTEMPTY)
    {  
        rec=1;
        
    }
    
}

/* [] END OF FILE */
