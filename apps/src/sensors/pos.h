#ifndef POS_H
#define POS_H

#include <stdint.h>
#include "sensors.h"

typedef struct
{
    uint16_t x;
    uint16_t y;
    uint16_t z;
} pos;

printSensorInfo PosInfo(uint8_t *data);

#endif