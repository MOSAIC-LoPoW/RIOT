/**
 * @ingroup     applications
 * @{
 *
 * @file
 * @brief       octa-test application
 * @}
 */

#include <stdio.h>
#include "board.h"

int main(void)
{
    printf("You are running RIOT on a(n) %s board.\n", RIOT_BOARD);
    printf("This board features a(n) %s MCU.\n", RIOT_MCU);
    //turn on R led
    LED0_ON;
    //turn on G led
    LED1_ON;
    //turn on B led
    LED2_ON;


    return 0;
}
