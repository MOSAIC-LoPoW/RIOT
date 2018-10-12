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
#include "lsm303dlhc.h"
#include "lsm303dlhc_params.h"

#define SLEEP       (100 * 1000U)

int main(void)
{
    printf("You are running RIOT on a(n) %s board.\n", RIOT_BOARD);
    printf("This board features a(n) %s MCU.\n", RIOT_MCU);

    lsm303dlhc_t dev;
    if (lsm303dlhc_init(&dev, &lsm303dlhc_params[0]) == 0) {
        puts("LSM init [OK]\n");
    }
    else {
        puts("LSM init[Failed]");
        return 1;
    }

    lsm303dlhc_3d_data_t acc_value;
    while(1)
    {
         if (lsm303dlhc_read_acc(&dev, &acc_value) == 0) {
            printf("Accelerometer x: %i y: %i z: %i\n", acc_value.x_axis,
                                                        acc_value.y_axis,
                                                        acc_value.z_axis);
        }
        else {
            puts("\nFailed reading accelerometer values\n");
        }
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
