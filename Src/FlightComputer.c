#include "FlightComputer.h"

#include "StateInitialize.h"
#include "StatePadIdle.h"

// Create three state payloads.
FC_State_Payload p1;
FC_State_Payload p2;
FC_State_Payload p3;

// Initialize a new state data struct, with the three payloads.
FC_State_Data sdata = {&p1, &p2, &p3, 0};

void FC_Tick() {

	// If we're in an illegal state, move into FSTATE_INITIALIZE. (Change this?)
	if(sdata.state <= FSTATE_UNDEFINED || sdata.state >= FSTATES_MAX_SIZE)
		sdata.state = FSTATE_INITIALIZE;

	// If next_state is defined and valid, switch to it.
	if(sdata.next_state > FSTATE_UNDEFINED && sdata.next_state < FSTATES_MAX_SIZE) {
		sdata.prev_state = sdata.state;
		sdata.state = sdata.next_state;
		sdata.next_state = FSTATE_UNDEFINED;

		// If we change states, mark this as the new entry tick and reset the timer and run counter.
		sdata.entry_tick = HAL_GetTick();
		sdata.timer_tick = 0;
		sdata.run_count = 0;
	}

	switch(sdata.state) {
		case FSTATE_INITIALIZE:    StateInitialize();    break;
		case FSTATE_PADIDLE:       StatePadIdle();       break;

		case FSTATE_UNDEFINED:
		case FSTATES_MAX_SIZE:
			sdata.state = FSTATE_UNDEFINED;
			break;
	}
}
