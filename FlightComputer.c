#include "FlightComputer.h"

#include "StateInitialize.h"
#include "StatePadIdle.h"
#include "StateTerminal.h"
#include "StateAscent.h"
#include "StateCoast.h"
#include "StateLanded.h"

// Initialize a new state data struct, initialized to zeroes.
FC_State_Data sdata = {0};

void FC_Setup() {
}

void FC_Tick() {

	// If we're in an illegal state, move into FSTATE_INITIALIZE. (Change this?)
	if(sdata.state <= FSTATE_UNDEFINED || sdata.state >= FSTATES_MAX_SIZE)
		sdata.state = FSTATE_INITIALIZE;

	// If next_state is defined and valid, switch to it.
	if(sdata.next_state > FSTATE_UNDEFINED && sdata.next_state < FSTATES_MAX_SIZE) {
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
		case FSTATE_TERMINAL:      StateTerminal();      break;
		case FSTATE_ASCENT:        StateAscent();        break;
		case FSTATE_COAST:         StateCoast();         break;
		case FSTATE_LANDED:        StateLanded();        break;

		case FSTATE_UNDEFINED:
		case FSTATES_MAX_SIZE:
		default:
			sdata.state = FSTATE_UNDEFINED;
			break;
	}
}
