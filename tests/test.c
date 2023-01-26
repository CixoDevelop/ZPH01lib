#include <ZPH01lib.h>

int main() {
    char test_payload[30] = 
        {0xFF, 0x18, 0x00, 0x10, 0x20, 0x00, 0x01, 0x00, 0x05};

    if (sensor_parse_uart_buffer(test_payload, 30) == 4560) {
        puts("Work on good payload!");
    } else {
        puts("Not work on good payload!");
    }
    
    char test_payload_dirty[30] = 
        {0x00, 0x01, 0xFF, 0x18, 0x00, 0x10, 0x20, 0x00, 0x01, 0x00, 0x05};

    if (sensor_parse_uart_buffer(test_payload_dirty, 30) == 4560) {
        puts("Work on dirty good payload!");
    } else {
        puts("Not work on dirty good payload!");
    }

    return 0;
}
