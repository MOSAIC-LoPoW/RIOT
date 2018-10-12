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
#include "sht3x.h"
#include "sht3x_params.h"

#define SLEEP       (500 * 1000U)

int main(void)
{
    printf("You are running RIOT on a(n) %s board.\n", RIOT_BOARD);
    printf("This board features a(n) %s MCU.\n", RIOT_MCU);

    sht3x_dev_t sht_dev;
    lsm303dlhc_t lsm_dev;
     printf("+------------Initializing------------+\n");
     if (sht3x_init(&sht_dev, &sht3x_params[0]) != SHT3X_OK) {
        puts("SHT31 init [Failed]\n");
        return 1;
    }
    else {
        puts("SHT31 init [OK]\n");
    }
    if (lsm303dlhc_init(&lsm_dev, &lsm303dlhc_params[0]) == 0) {
        puts("LSM init [OK]\n");
    }
     else {
        puts("LSM init[Failed]");
        return 1;
    }
    
    printf("\n+--------Starting Measurements--------+\n");

    lsm303dlhc_3d_data_t acc_value;
    int16_t temp;
    int16_t hum;

    while (1) {
        if (lsm303dlhc_read_acc(&lsm_dev, &acc_value) == 0) {
            printf("Accelerometer x: %i y: %i z: %i\n", acc_value.x_axis,
                                                        acc_value.y_axis,
                                                        acc_value.z_axis);
        }
        else {
            puts("\nFailed reading accelerometer values\n");
        }
        
        if (sht3x_read(&sht_dev, &temp, &hum) == SHT3X_OK) {
            printf("Temperature [°C]: %d.%d\n"
                   "Relative Humidity [%%]: %d.%d\n"
                   "+-------------------------------------+\n",
                   temp / 100, temp % 100,
                   hum / 100, hum % 100);
        }
        else {
            printf("Could not read data from sensor, error");
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
