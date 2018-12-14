#include "StateInitialize.h"

#include "FlightComputer.h"

// TODO: Set this appropriately to cover all the FC_Flags related to checkout.
#define SELFTEST_MASK 0x1

/**
 * Perform any available automated self-tests provided by the sensor's.
 * Additionally, perform our own sanity checks of data from both the external
 * sensors, as well as our ADC values and any internal states.
 *
 * This function sets sdata.flags accordingly. Also returns sdata.flags AND'd with
 * the relevant self-test flag bits for easy retval checking.
 */
uint32_t DoCheckout() {
	// TODO: Do battery of tests, setting flags appropriately if errors.
	return sdata.flags & SELFTEST_MASK;
}

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

	uint32_t sanity = DoCheckout();
	// TODO: Check sanity and actually do something if the system is insane.

	sdata.next_state = FSTATE_PADIDLE;
}