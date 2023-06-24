#ifndef SCHEDULER_H_
#define SCHEDULER_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FCFS 0
#define SPT 1
#define R_R 2
#define WAITING 0
#define RUNNING 1
#define NOT_EXIST -1
#define NOT_ARRIVED -2

typedef struct process{
    int label;
    int arrive;
    int start;
    int finish;
    int response;
    int length;
    int remain;
    int status;
} process;

typedef struct queue{
    process pro;
    struct queue *next;
} queue;

queue* gen_queue(process);
process dequeue(queue**);
void init(process*, int);
int checking_finish(process*, int);
//int checking_not_arrived(process*, int);
void enqueue(int, int, process*, queue**, int);
void arrive(process*, int, int, int, queue**,int*);
void run(process*);
process start_run(queue**, int);
int terminate(process*, process, int, int, int*, int*);
//void calc_response(process*,int);
void print_pro(process*,int,int);
//void calc_ave(process*, int);
void print_queue(queue*);

#include "FCFS.h"
#include "SPT.h"
#include "Round_Robin.h"
#endif /* SCHEDULER_H_ */
