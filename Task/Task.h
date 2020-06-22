#ifndef __TASK_H
#define __TASK_H


#define GET_SYSTICK()			SysTick
#define GET_TIME(timer)		(SysTick>=timer) ? (SysTick-timer) : (0xffffffffU-timer+SysTick)

typedef struct{
	unsigned int enable;
	unsigned int period_cnt;
	unsigned int period;
	void (*fptr)(void);
}Task_st;

typedef enum ENUM_TASK_NAME{
	LED_TOGGLE,
	PRINT_CNT
}Task_Name_st;


extern void Task_Run(void);
extern void Task_Enable(Task_Name_st name);
extern void Task_Disable(Task_Name_st name);
#endif	
