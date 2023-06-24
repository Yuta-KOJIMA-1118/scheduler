#ifndef ROUND_ROBIN_H_
#define ROUND_ROBIN_H_
#include "scheduler.h"


void R_R_enqueue(int, process*, queue**, int);
void R_R_replace(process, queue**);
void Round_Robin(process*, int);

#endif /* ROUND_ROBIN_H_ */




