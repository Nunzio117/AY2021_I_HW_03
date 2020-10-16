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
#include "UART_RGB.h"

CY_ISR(Custom_UART_RX_ISR)
{  
    if (UART_RGB_ReadRxStatus() == UART_RGB_RX_STS_FIFO_NOTEMPTY)
    {
       rec=1;
    }
    //UART_RGB_ClearTxBuffer();
    //UART_RGB_ClearRxBuffer();
}

/* [] END OF FILE */
