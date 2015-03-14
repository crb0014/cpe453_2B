#include "safetysys.h"

SafetySys::SafetySys()
{

}

/**
 * @brief SafetySys::safetyCheck
 * @param str - the detection section to check
 * @return boolean true if is safe or false is not
 */
bool SafetySys::isSafe(QString str)
{
    if (isRed(str)) {return false;}
    else if (isYellow(str)) {return false;}
    else return true;
}

/**
 * @brief SafetySys::isDisabled
 * @param str - the detection section to check
 * @return boolean true if is red or false if not
 */
bool SafetySys::isDisabled(QString str)
{
    return false;
}

/**
 * @brief SafetySys::isRed
 * @param str - the detection section to check
 * @return boolean true if is red or false if not
 */
bool SafetySys::isRed(QString str)
{
    return false;
}

/**
 * @brief SafetySys::isYellow
 * @param str - the detection section to check
 * @return boolean true if is yellow or false if not
 */
bool SafetySys::isYellow(QString str)
{
    return false;
}
