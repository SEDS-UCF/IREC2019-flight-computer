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
	// Check timers and communication lines. Return quickly if nothing to do.
}