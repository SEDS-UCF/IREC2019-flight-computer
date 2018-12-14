#include "StatePadIdle.h"

#include "FlightComputer.h"

/**
 * This state represents the period of time after initialization but prior to
 * beginning the pre-launch procedures. This will likely include running the
 * self test on a timer, plus some other stuff. Primarily, we'll be listening
 * for the signal from the ground computer to begin either fill procedures or
 * terminal count (or abort procedures).
 */
void StatePadIdle() {
	// TODO: Send telemetry to ground.

	// TODO: Listen for FILL signals.
	// if we get FILL signal:
		// set valves for filling
		sdata.flags |= FFLAG_FILLING;
	// if we get FILL_DONE signal:
		// close fill valves
		sdata.flags &= ~FFLAG_FILLING;

	// TODO: Listen for TERMINAL signal.
	// if we receive TERMINAL signal:
		sdata.next_state = FSTATE_TERMINAL;
}