#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<string.h>
#include<pthread.h>
#include<signal.h>

int pram_check(int argc,const char* sfile,int pronum);

int file_block(const char* sfile,int pronum);

int thread_create(const char* sfile,const char* dfile, int blcoksize, int pronum);

int thread_wait(void);
