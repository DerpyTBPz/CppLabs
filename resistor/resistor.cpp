#include <iostream>
#include "resistor.h"

struct Resistor
{
    float resistance;
    float max_power;
};

// struct Resistors
// {
//     Resistor res;
// };

int initResistor(Resistor res, float R, float U)
{
    res.resistance = R;
    res.max_power = U;

    return 1;
}

int initResistors(Resistor res[])
{
    return 2;
}

int showResistor()
{
    return 3;
}

int showResisitor()
{
    return 4;
}

int checkResistor()
{
    return 5;
}