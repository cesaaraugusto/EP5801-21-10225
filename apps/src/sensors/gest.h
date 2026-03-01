#ifndef GEST_H
#define GEST_H

#include <stdint.h>
#include "sensors.h"

typedef struct
{
    uint8_t tap : 1;
    uint8_t doubletap : 1;
    uint8_t presionHaptica : 1;
    uint8_t bitsReservados : 5;
} gest;

printSensorInfo GestInfo(uint8_t *data);

#endif