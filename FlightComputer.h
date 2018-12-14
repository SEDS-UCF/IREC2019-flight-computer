#ifndef IREC19_FC_FLIGHTCOMPUTER_H
#define IREC19_FC_FLIGHTCOMPUTER_H

#include "System/main.h"

typedef enum {
	// Default upon boot, leads directly into FSTATE_INITIALIZE.
	FSTATE_UNDEFINED	= 0,

	FSTATE_INITIALIZE,
	FSTATE_PADIDLE,
	FSTATE_TERMINAL,
	FSTATE_ASCENT,
	FSTATE_COAST,
	FSTATE_LANDED,

	// Reserved placeholder, do not use!
	FSTATES_MAX_SIZE
} FC_State_Type;

// max of 32 flags not including 0. 1<<0 through 1<<31.
typedef enum {
	FFLAG_NONE      = 0,
	FFLAG_FILLING   = 1 << 0,
	FFLAG_TM3_EVENT = 1 << 1
} FC_Flags;

typedef struct _FC_State_Data {
	FC_State_Type state;
	FC_State_Type next_state;

	uint32_t entry_tick; // tick of first state run
	uint32_t timer_tick; // timer for per-state usage
	uint32_t run_count;  // # times state run
	uint32_t met_zero;   // MET zero tick

	// Global bit flags for cross-state information. See FC_Flags and bit flags.
	/* Bit flag crash course:
	 * To set FLAG_A:    flags |= FLAG_A;
	 * To unset FLAG_A:  flags &= ~FLAG_A;
	 * To toggle FLAG_A: flags ^= FLAG_A;
	 * To test FLAG_A:   (flags & FLAG_A);
	 *
	 * Anywhere (other than testing a bit value) you see FLAG_A,
	 * you can use multiple flags by ORing them.
	 * To set FLAG_A and FLAG_B: flags |= (FLAG_A | FLAG_B);
	 */
	uint32_t flags;
} FC_State_Data;

// Define a global FC_State_Data instance.
extern FC_State_Data sdata;

void FC_Setup();
void FC_Tick();

#endif //IREC19_FC_FLIGHTCOMPUTER_H
