#include "StateLanded.h"

#include "FlightComputer.h"

// 2 minutes in milliseconds = (2 * 60 * 1000)
#define SHUTDOWN_DELAY 120000

void StateLanded() {
	if(sdata.run_count == 0)
		sdata.timer_tick = HAL_GetTick() + SHUTDOWN_DELAY;
	else if(HAL_GetTick() > sdata.timer_tick) {
		// TODO: Shunt battery power.
	}

	// TODO: Any gas safing procedures, data flushing, and other last minute cleanup.
}