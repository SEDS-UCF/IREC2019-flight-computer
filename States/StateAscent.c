#include "StateAscent.h"

#include "FlightComputer.h"

void StateAscent() {
	// WE CAN NOT ACTIVATE ANY CONTROLS DURING THIS STATE.

	// TODO: Just monitor data and relay to ground.

	// TODO: Check for burnout using estimated time, acceleration, and altitude delta.
	// Also, confirm with combustion chamber pressure if we have access to that?
	sdata.next_state = FSTATE_COAST;
}