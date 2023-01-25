#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "sensor.h"

/** \fn sensor_parse_uart_buffer
 * This function parse uart buffer as measurement from sensor. Return result
 * as long number that is normalized value from sensor. Be careful, bufer 
 * must have size minimum 9 bytes.
 * @*buffer Buffer to parse
 * @size Buffer size, function 
 */
long sensor_parse_uart_buffer(char *buffer, uint8_t size) {
    while (*(buffer++) != 0xFF) if (--size < 8) return 0x00;

    if (*(buffer++) != 0x18) return 0x00;
    if (*(buffer++) != 0x00) return 0x00;

    uint8_t integer = *(buffer++);
    uint8_t decimal = *(buffer++);

    if (*(buffer++) != 0x00) return 0x00;
    if (*(buffer++) != 0x01) return 0x00;
    if (*(buffer++) != 0x00) return 0x00;

    uint8_t checksum = *buffer;

    return sensor_normalize(sensor_get_pulse_rate(decimal, integer));
}

/** \fn sensor_get_pulse_rate
 * This get pulse rate in procents from decimal and integer part of
 * number, that read from sensor.
 * @decimal Decimal part of number
 * @integer Integer part of number
 */
float sensor_get_pulse_rate(uint8_t decimal, uint8_t integer) {
    return integer + (float) (decimal / 100);
}

/** \fn sensor_normalize
 * This get normalized value from pulse rate. That return number of the 
 * elements in the air.
 * @pulse_rate Pulse rate read from sensor
 */
long sensor_normalize(float pulse_rate) {
    return (long) (285 * pulse_rate);
}
