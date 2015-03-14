#include "integration.h"

Integration::Integration()
{
    hash["ds1_1_1"] = "bob,bob2,bob3";
}

QString Integration::translate(QString ds)
{
    return hash.value(ds,"None");
}
