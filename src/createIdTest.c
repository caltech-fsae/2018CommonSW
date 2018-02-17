#include "identifiers.h"
#include <stdio.h>

uint16_t create_ID(uint16_t board, uint16_t type)
{
	return ( (uint16_t)type & 0b0000011111110000 | ((uint16_t)board & 0b00001111));
}

void printId(uint16_t id) {
    int i;
    int n = id;
    for (i = 0; i < 16; i ++) {
        if (i%4 == 0) {
            printf(" ");
        }
        if (n & 0x8000) {
            printf("1");
        } else {
            printf("0");
        }
        n <<= 1;
    }
    printf("\n");
}
        

int main() {
    printf("Testing\n");
    uint16_t test;

    printId(0b1010101010101010);

    printf("Creating id for BID_BMS_MASTER, FAULT_NR \n");
    test = create_ID(BID_BMS_MASTER, FAULT_NR);
    printId(test);

    printf("Creating id for BID_CORE, TORQUE_STATUS \n");
    test = create_ID(BID_CORE, TORQUE_STATUS);
    printId(test);

    printf("Testing invalid BID \n");
    test = create_ID((uint16_t)0xFFFF, (uint16_t)0x0000);
    printId(test);

    printf("Testing invalid message type \n");
    test = create_ID((uint16_t)0x0000, (uint16_t)0xFFFF);
    printId(test);

    return 0;
}
