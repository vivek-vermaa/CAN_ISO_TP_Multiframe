/*
 ============================================================================
 Name        : CAN_ISO_TP.c
 Author      : Vivek Verma
 Version     :
 Copyright   : Published in opensource
 Description : Driver App for the library
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "CAN_ISO_TP.h"
#include "send.h"
#define TRUE 1
#define FALSE 0
extern IsoTpShims SHIMS;
extern void message_sent(const IsoTpMessage* message, const bool success);
status Send_Multiframe();


int main(void) {

	setup();
	Send_Multiframe();
	return EXIT_SUCCESS;
}

status Send_Multiframe()
{
	 const uint8_t payload[] = {0x12, 0x34, 0x56, 0x78, 0x90, 0x01, 0x23};
	    uint16_t arbitration_id = 0x2a;

	    IsoTpSendHandle handle = isotp_send(&SHIMS, arbitration_id, payload, sizeof(payload), message_sent);
	    if ((handle.completed  && handle.success )== TRUE)
	    {
	    	printf("Success");
	    }
	    else
	    {
	    	printf("Message Sending failed");
	    }


  return EXIT_SUCCESS;
}

