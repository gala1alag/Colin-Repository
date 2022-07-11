#include<thread_copy.h>



int main(int argc ,char ** argv)
{
	int pronum;
	if(argv[3] == 0)
	{
		pronum = 3;
	}
	else 
		pronum = atoi(argv[3]);
	pram_check(argc,argv[1],pronum);
	int blocksize;
	blocksize = file_block(argv[1],pronum);
	thread_create(argv[1],argv[2],blocksize,pronum);
	return 0;
}
