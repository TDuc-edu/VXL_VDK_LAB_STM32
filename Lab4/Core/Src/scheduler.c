/*
 * scheduler.c
 *
 *  Created on: Nov 25, 2025
 *      Author: TD
 */

#include "scheduler.h"

struct sTask SCH_tasks_G[SCH_MAX_TASKS];

void SCH_Init(void) {
	uint8_t Index;
	for (Index = 0; Index < SCH_MAX_TASKS; Index++) {
		SCH_tasks_G[Index].pTask = 0;
		SCH_tasks_G[Index].Delay = 0;
		SCH_tasks_G[Index].Period = 0;
		SCH_tasks_G[Index].RunMe = 0;
		SCH_tasks_G[Index].TaskID = 0;
	}
}

void SCH_Update(void) {
	uint8_t Index;

	for (Index = 0; Index < SCH_MAX_TASKS; Index++) {
		if (SCH_tasks_G[Index].pTask) {
			if (SCH_tasks_G[Index].Delay == 0) {
				SCH_tasks_G[Index].RunMe += 1;
				SCH_tasks_G[Index].Delay = SCH_tasks_G[Index].Period;
			} else {
				SCH_tasks_G[Index].Delay -= 1;
			}
		}
	}
}

void SCH_Add_Task(void (*pFunction)(void), uint32_t DELAY, uint32_t PERIOD) {
	uint8_t Index = 0;

	while ((SCH_tasks_G[Index].pTask != 0) && (Index < SCH_MAX_TASKS)) {
		Index++;
	}

	if (Index == SCH_MAX_TASKS) {
		return;
	}

	SCH_tasks_G[Index].pTask = pFunction;
	SCH_tasks_G[Index].Delay = DELAY;
	SCH_tasks_G[Index].Period = PERIOD;
	SCH_tasks_G[Index].RunMe = 0;
	SCH_tasks_G[Index].TaskID = Index;
}

void SCH_Dispatch_Tasks(void) {
	uint8_t Index;

	for (Index = 0; Index < SCH_MAX_TASKS; Index++) {
		if (SCH_tasks_G[Index].RunMe > 0) {
			(*SCH_tasks_G[Index].pTask)();

			SCH_tasks_G[Index].RunMe -= 1;

			if (SCH_tasks_G[Index].Period == 0) {
				SCH_Delete_Task(Index);
			}
		}
	}
}

void SCH_Delete_Task(uint32_t taskID) {
	if (SCH_tasks_G[taskID].pTask == 0) {
		return;
	}

	SCH_tasks_G[taskID].pTask = 0;
	SCH_tasks_G[taskID].Delay = 0;
	SCH_tasks_G[taskID].Period = 0;
	SCH_tasks_G[taskID].RunMe = 0;
	SCH_tasks_G[taskID].TaskID = 0;
}
