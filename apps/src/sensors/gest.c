#include <stdio.h>
#include "gest.h"

gest gesto;

void printTapGest()
{
    printf("Gesto detectado: Tap\n");
}

void printDoubleTapGest()
{
    printf("Gesto detectado: Double Tap\n");
}

void printPresionHapticaGest()
{
    printf("Gesto detectado: Presión Haptica\n");
}

void printNoGesto()
{
    printf("No se detectó ningún gesto\n");
}

printSensorInfo GestInfo(uint8_t *data)
{
    if (data[0] & (1 << 0))
    {
        gesto.tap = 1;
        return printTapGest;
    }
    else if (data[0] & (1 << 1))
    {
        gesto.doubletap = 1;
        return printDoubleTapGest;
    }
    else if (data[0] & (1 << 2))
    {
        gesto.presionHaptica = 1;
        return printPresionHapticaGest;
    }
    else
    {
        return printNoGesto;
    }
}