#include <stdio.h>
#include "Task.h"
#include "../main.h"
unsigned int SysTick;




Task_st Task_tbl[] = {
						{1	,0	,5	,LEDToggle},
						{1	,0	,10	,print_cnt}
};

void Task_Run(void){
	unsigned int timer,i;
	static unsigned int pre_timer=0;
	timer = GET_TIME(pre_timer);
	
	if(timer){
		for(i=0;i<(sizeof(Task_tbl)/sizeof(Task_tbl[0]));i++){
			if(Task_tbl[i].enable){
				Task_tbl[i].period_cnt += timer;
				if(Task_tbl[i].period_cnt >= Task_tbl[i].period){
					Task_tbl[i].fptr();
					Task_tbl[i].period_cnt = 0;
				}				
			}
		}	
		pre_timer = GET_SYSTICK();		
	}
	
}

void Task_Enable(Task_Name_st name){
	Task_tbl[name].enable = 1;
}

void Task_Disable(Task_Name_st name){
	Task_tbl[name].enable = 0;
}
