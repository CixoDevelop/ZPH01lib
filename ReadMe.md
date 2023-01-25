# ZPH01lib

This library is design for reading value from sensor ZPH01 in normal form.
Data is returning as long value, project must read all data from sensor to 
buffer, that size is minimul 9 bytes. When received 9 bytes, then can 
parse it with function from that library, to get parsed data and flush 
buffer.


## Sample (pseudo code)

while (true) {
    if (buffer_lenght() < 9) continue;

    long data = sensor_parse_uart_buffer(buffer_get_pointer());

    buffer_flush();
}
