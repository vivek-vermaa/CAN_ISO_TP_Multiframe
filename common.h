/*
 ============================================================================
 Name        : common.h
 Author      : Vivek Verma
 Version     :
 Copyright   : Published in opensource
 Description : CAN ISO Tp for multiframe
 ============================================================================
 */

#ifndef COMMON_H_
#define COMMON_H_

#include "isotp.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


void debug(const char* format, ...);
bool mock_send_can(const uint32_t arbitration_id, const uint8_t* data,const uint8_t size);
void message_received(const IsoTpMessage* message);
void message_sent(const IsoTpMessage* message, const bool success);
void can_frame_sent(const uint32_t arbitration_id, const uint8_t* payload,
        const uint8_t size);
void setup();


#endif /* COMMON_H_ */
