/**
 * Tests for CAN functions
 *
 * gcc src/createIdTest.c -I inc -o createIdTest
 **/

#include "identifiers.h"
#include "mycan.h"
#include <stdio.h>

/**
 * These functions come directly from mycan.h
 */
void CAN_short_msg(can_msg_t *msg, uint16_t identifier, uint16_t data);

uint16_t create_ID(uint16_t board, uint16_t type)
{
	return ( (uint16_t)type & 0b0000011111110000 | ((uint16_t)board & 0b00001111));
}

void create_ACK(can_msg_t *msg, uint16_t board, can_msg_t *ack) {
    uint16_t identifier = create_ID(board, MID_ACKNOWLEDGE);
    uint16_t payload = msg->identifier & 0x8F;
    CAN_short_msg(ack, identifier, payload);
}

void CAN_short_msg(can_msg_t *msg, uint16_t identifier, uint16_t data) {
	msg->identifier = identifier;
	msg->data_length = 2;
	*(uint16_t*)(msg->data + 6) = data;
}

/**
 * Ok, now actual test code.
 */

void printId(uint16_t id) {
    int i;
    int n = id;
    for (i = 0; i < 16; i ++) {
        if (i%4 == 0) {
            printf(" ");
        }
        printf("%d", (n>>(8*2 - 1))&0x1);
        n <<= 1;
    }
    printf("\n");
}
        

int main() {
    printf("Testing\n");
    uint16_t test;

    printId(0b1010101010101010);

    printf("Creating id for BID_BMS_MASTER, MID_FAULT_NR \n");
    test = create_ID(BID_BMS_MASTER, MID_FAULT_NR);
    printId(test);

    printf("Creating id for BID_CORE, MID_TORQUE_STATUS \n");
    test = create_ID(BID_CORE, MID_TORQUE_STATUS);
    printId(test);

    printf("Testing invalid BID \n");
    test = create_ID((uint16_t)0xFFFF, (uint16_t)0x0000);
    printId(test);

    printf("Testing invalid message type \n");
    test = create_ID((uint16_t)0x0000, (uint16_t)0xFFFF);
    printId(test);

    printf("\n");

    printf("Testing Create_ACK\n");
    printf("(MID_ACKNOWLEDGE = 0x000B << 4)\n");
    can_msg_t msg;
    uint16_t id = create_ID((uint16_t)0xFFF5, (uint16_t)0xFFFF);
    uint16_t payload = 0xFFFF;
    CAN_short_msg(&msg, id, payload);
    printf("Test message ID:\n");
    printId(msg.identifier);

    printf("Creating ack from board 0x0005\n");
    can_msg_t ack;
    create_ACK(&msg, 0x0005, &ack);
    printf("Ack identifier:\n");
    printId(ack.identifier);

    return 0;
}
