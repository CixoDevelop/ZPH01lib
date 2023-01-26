#ifndef SENSOR_H_INCLUDED
#define SENSOR_H_INCLUDED

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

/** \def SENSOR_BUADRATE
 * This is serial buadrate for sensor.
 */
#define SENSOR_BUADRATE 9600

/** \def SENSOR_MINIMUM_BUFFER
 * This is minimum buffer size that must full of data read from uart, 
 * to parse it as measuremen from sensor.
 */
#define SENSOR_MINIMUM_BUFFER 9

/** \fn sensor_parse_uart_buffer
 * This function parse uart buffer as measurement from sensor. Return result
 * as long number that is normalized value from sensor. Be careful, bufer 
 * must have size minimum 9 bytes.
 * @*buffer Buffer to parse
 * @size Buffer size, function 
 */
long sensor_parse_uart_buffer(unsigned char *buffer, uint8_t size);
 
/** \fn sensor_get_pulse_rate
 * This get pulse rate in procents from decimal and integer part of
 * number, that read from sensor.
 * @decimal Decimal part of number
 * @integer Integer part of number
 */
float sensor_get_pulse_rate(uint8_t decimal, uint8_t integer); 

/** \fn sensor_normalize
 * This get normalized value from pulse rate. That return number of the 
 * elements in the air.
 * @pulse_rate Pulse rate read from sensor
 */
long sensor_normalize(float pulse_rate);

#endif
