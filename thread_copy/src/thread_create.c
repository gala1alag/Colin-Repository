#include<thread_copy.h>

typedef struct
{
	const char* sfile;
	const char* dfile;
	int blocksize;
	int pos;
}TEXT;


void * jobs(void * arg)
{
		TEXT* text = (TEXT*)arg;
		text->pos = (*(int *)arg) * (text->blocksize);
		char str_blocksize[50];
		char str_pos[50];
		bzero(str_blocksize,sizeof(str_blocksize));
		bzero(str_pos,sizeof(str_pos));
		sprintf(str_blocksize,"%d",text->blocksize);
		sprintf(str_pos,"%d",text->pos);
		printf("Copy Child thread Pid 0x%x Copy_Pos %d Copy_size %d\n",(unsigned int)pthread_self(),text->pos,text->blocksize);
		execl("/home/wangyilin/20210913/Pthread/thread_copy/moudle/COPY","COPY",text->sfile,text->dfile,str_blocksize,str_pos,NULL);


}


int thread_create(const char* sfile, const char* dfile,int blocksize,int pronum)
{
 	pthread_t tid;
 	int err;
 	int flag;
 	for(flag = 0;flag < pronum;flag++)
 	{
  		TEXT* text = (TEXT*)malloc(sizeof(TEXT));
  		text->sfile = sfile;
  		text->dfile = dfile;
  		text->blocksize = blocksize;
  		text->pos = flag*blocksize;
  		if((err = pthread_create(&tid,NULL,jobs,(void *)text) )> 0)
  		{
  			printf("pthread_create error:%s\n",strerror(err));
   			exit(0);
  		}

 	}
 	return 0;
}
