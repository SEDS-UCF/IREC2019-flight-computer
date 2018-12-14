#include "StateCoast.h"

#include "FlightComputer.h"

void StateCoast() {
	// TODO: Collect sensor data.

	// TODO: Send telemetry to ground.

	// TODO: Simulate trajectory and deploy air brakes accordingly.

	// TODO: Deploy recovery appropriately. (At apogee?)

	// TODO: Check for landing. We should see sharp deceleration and altitude delta ~= 0;
	sdata.next_state = FSTATE_LANDED;
}