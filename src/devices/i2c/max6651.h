/*
 *************************************************************************************
 * Interface for Emulation of MAX6651 Fan-Controller 
 *************************************************************************************
 *
 */

#include <i2c.h>
I2C_Slave * MAX6651_New(char *name);
typedef struct MAX6651 MAX6651;