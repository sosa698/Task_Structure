#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h> 
#include <windows.h>
#include "./Task/Task.h"
#define DELAY_ms  1

unsigned int SysTick = 0;

void *Timer_1ms(void* a)
{

	while(1)
	{
		sleep(DELAY_ms);
		SysTick++;
		printf("SysTick = %d \n" , SysTick);
	

	}
}

void *thread_2(void* b)
{
	while(1)
	{
	}
}

void LEDToggle(void){
	printf("LEDToggle\n");
}

void print_cnt(void){
	static unsigned int cnt=0;
	printf("cnt = %d\n",cnt++);
}

int main(int argc, char *argv[]) {
	
	pthread_t thread_id_1, thread_id_2;
	pthread_create(&thread_id_1, NULL, Timer_1ms, (void *)NULL);	
	pthread_create(&thread_id_2, NULL, thread_2, (void *)NULL);	

	
	while(1){
		Task_Run();
	}

	
	return 0;
}


