#include "Checkout.h"

#include "FlightComputer.h"

// TODO: Set this appropriately to cover all the FC_Flags related to checkout.
#define SELFTEST_MASK 0x1

/**
 * Quicker checkout variant, this just checks sensor data against our own values.
 * Does NOT perform sensor self-tests, since those are time consuming and expect
 * the sensor to be recently powered on. When sitting on the pad, we need a quick
 * go/no-go style test to check for anything going wacky, but nothing too intense
 * here, that's what FullCheckout is for.
 *
 * This function sets sdata.flags accordingly. Also returns sdata.flags AND'd with
 * the relevant self-test flag bits for easy retval checking.
 */
uint32_t QuickCheckout() {

}

/**
 * Perform any available automated self-tests provided by the sensor's.
 * Additionally, perform our own sanity checks of data from both the external
 * sensors, as well as our ADC values and any internal states.
 *
 * This function sets sdata.flags accordingly. Also returns sdata.flags AND'd with
 * the relevant self-test flag bits for easy retval checking.
 */
uint32_t FullCheckout() {
	// TODO: Do battery of tests, setting flags appropriately if errors.
	return sdata.flags & SELFTEST_MASK;
}