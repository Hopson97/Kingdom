#include "rand.h"

int kingdom_random::num(int low, int high)	//Call this method f
{
	return rand() % (high - low + 1) + low;
}
