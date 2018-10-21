#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int data[1000];
int chunk=100;

void *add(void *arg)
{
    int start=(int)arg;
    int end=start+chunk;
    int sum=0;
    for(int i=start;i<end;i++)
    	{
        	sum+=data[i];
    	}

    return ((void*)sum);
}

int main()
{
    
    
    int array[10];
    pthread_t p_thread[10];
    int total=0;
    for(int i=0;i<1000;i++){
        data[i]=i+1;
    }
    for(int i=0;i<10;i++){
        pthread_create(&p_thread[i],NULL,add,(void*)(i*chunk));
    }
    for(int i=0;i<10;i++){
        pthread_join(p_thread[i],(void**)&array[i]);
    }
    for(int i=0;i<10;i++){
        total+=array[i];
    }
    printf("sum of 1000 numbers using thread: %d \n",total);
}
