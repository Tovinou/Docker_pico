#include <stdio.h>
#include "pico/stdlib.h"

int main() {
    stdio_init_all();
    printf("Hello,World from pico zero!\n");

    while (true) {
	  sleep_ms(1000);
    }

}




