#ifndef IREC19_FC_STATESELFTEST_H
#define IREC19_FC_STATESELFTEST_H

#include <stdint.h>

enum SelfTestResults {
	STR_GOOD = 0,
	STR_ERR1 = 1 << 0,
	STR_ERR2 = 1 << 1,
	STR_ERR3 = 1 << 2
	// etc...
};

uint32_t DoSelfTest();

#endif //IREC19_FC_STATESELFTEST_H
