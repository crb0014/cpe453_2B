#include "pwrmgmt.h"

/**
 * @brief PWRMGMT::PWRMGMT
 */
PWRMGMT::PWRMGMT(QString src[I][J], QString iP1, QString iP2)
{
    IP1 = iP1;
    IP2 = iP2;
    for (int i = 0; i < I; i++)
        for (int j = 0; j < J; j++)
            array[i][j] = src[i][j];
}
