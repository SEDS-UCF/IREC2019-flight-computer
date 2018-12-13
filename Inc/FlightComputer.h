#ifndef IREC19_FC_FLIGHTCOMPUTER_H
#define IREC19_FC_FLIGHTCOMPUTER_H

#include "main.h"

typedef enum {
	// Default upon boot, leads directly into FSTATE_INITIALIZE.
	FSTATE_UNDEFINED	= 0,

	FSTATE_INITIALIZE,
	FSTATE_PADIDLE,

	// Reserved placeholder, do not use!
	FSTATES_MAX_SIZE
} FC_State_Type;

typedef union _WTC_State_Payload {
// Empty for now, but will eventually contain each state's payload.
} FC_State_Payload;

typedef struct _WTC_State_Data {
	FC_State_Payload* prev_payload;
	FC_State_Payload* payload;
	FC_State_Payload* next_payload;

	FC_State_Type prev_state;
	FC_State_Type state;
	FC_State_Type next_state;

	uint32_t entry_tick;
	uint32_t timer_tick;
	uint32_t run_count;
} FC_State_Data;

// Define a global FC_State_Data instance.
extern FC_State_Data sdata;

void FC_Tick();

#endif //IREC19_FC_FLIGHTCOMPUTER_H
