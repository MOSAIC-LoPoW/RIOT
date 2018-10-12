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
#include "xtimer.h"

#define SLEEP       (100 * 1000U)

int main(void)
{
    printf("You are running RIOT on a(n) %s board.\n", RIOT_BOARD);
    printf("This board features a(n) %s MCU.\n", RIOT_MCU);

    while(1)
    {
        //turn on R led
        LED0_ON;
        xtimer_usleep(SLEEP);
        LED0_OFF;
        //turn on G led
        LED1_ON;
        xtimer_usleep(SLEEP);
        LED1_OFF;
        //turn on B led
        LED2_ON;
        xtimer_usleep(SLEEP);
        LED2_OFF;
    }
    

    


    return 0;
}
