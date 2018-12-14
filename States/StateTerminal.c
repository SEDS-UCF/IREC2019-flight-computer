#include "StateTerminal.h"

#include "FlightComputer.h"

// 10 seconds from count start to T-0 (10 * 1000)
#define T_ZERO_OFFSET 10000

// Example event at T-3 seconds
#define T_M3_EVENT 3000

void StateTerminal() {
	if(sdata.run_count == 0)
		sdata.met_zero = sdata.entry_tick + T_ZERO_OFFSET;

	/*
	 * Save the current tick to avoid an edge case where after the GetTick < met_zero check,
	 * we advance past zero. This would give us a negative number for future met_zero - GetTick
	 * checks, which we don't want to deal with. Instead, just save the tick and avoid shenanigans.
	 */
	uint32_t this_tick = HAL_GetTick();

	// Check whether the current tick is past the set T-0 tick.
	if(this_tick >= sdata.met_zero) {
		// if launch verified with accel data and altitude data:
			sdata.next_state = FSTATE_ASCENT;
			return;
	}

	// TODO: Do whatever we have to do in our terminal count. Talk with prop for this.

	// Example of checking MET time and an event flag.
	if((sdata.met_zero - this_tick) < T_M3_EVENT && !(sdata.flags & FFLAG_TM3_EVENT)) {
		// Do whatever the example T-3 event is...

		// Set that we've completed the event so we don't repeat it on the next state run.
		sdata.flags |= FFLAG_TM3_EVENT;
	}
}