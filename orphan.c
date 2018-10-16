#include<stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
int main() 
{ 
    //orphanprocess      
    int pid = fork(); 
  
    if (pid > 0) 
    {
        printf(" parent process"); 
	}
        
    else if (pid == 0) 
    { 
        sleep(30); 
        printf(" child process"); 
    } 
  
    return 0; 
}
