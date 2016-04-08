#include "rand.h"

int random::num(int low, int high)	//Call this method f
{
	return rand() % (high - low + 1) + low;
}
