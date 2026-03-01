#include <stdio.h>
#include <stdint.h>
#include "sensors/sensors.h"
#include "sensors/pos.h"
#include "sensors/gest.h"

// input
uint8_t sensor_read[] = {0x55, 0x089};

printSensorInfo printInfo;

int main()
{
    switch (sensor_read[0])
    {
    case 0x44:
        printInfo = PosInfo(sensor_read + 1);
        printInfo();
        break;

    case 0x55:
        printInfo = GestInfo(sensor_read + 1);
        printInfo();
        break;

    default:
        break;
    }
}