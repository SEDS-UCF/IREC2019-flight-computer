#include "StateInitialize.h"

#include "FlightComputer.h"
#include "Checkout.h"

/**
 * The flight computer interfaces (SPI, USART, etc.) have already been initialized
 * at this point. This method is for setting up any data structs we may end up needed,
 * as well as getting all of the sensors initialized. This method will mostly be a series
 * of calls to other auxiliary methods for each of the sensors, which will themselves
 * be largely a collection of SPI exchanges to set up the various registers.
 */
void StateInitialize() {
	// TODO: Do initialization.

	// TODO: Establish ground contact and confirm with test handshake.

	uint32_t sanity = FullCheckout();
	// TODO: Check sanity and actually do something if the system is insane.

	sdata.next_state = FSTATE_PADIDLE;
}