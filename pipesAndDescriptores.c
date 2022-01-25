#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
int main(int argc, char *argv[])
{
    int fd[2];
    int randomNum = 0;
    srand(time(NULL));
    // create pipe descriptors
    pipe(fd);

     if (fork() != 0)
    {
        // parent: writing only, so close read-descriptor.
        close(fd[0]);

        // send the value on the write-descriptor.
        randomNum = rand()%(1000-1+1)+1;
        write(fd[1], &randomNum, sizeof(randomNum));
        printf("Parent(%d) send value: %d\n", getpid(), randomNum);
	
        // close the write descriptor
        close(fd[1]);
    }
    else
    {   // child: reading only, so close the write-descriptor
        close(fd[1]);

        // now read the data (will block)
        read(fd[0], &randomNum, sizeof(randomNum));
	if(randomNum < 500){
	printf("El numero es menor a 500\n");	
	}else{
	printf("El numero es mayor o igual a 500\n");
	}
        printf("Child(%d) received value: %d\n", getpid(), randomNum);

        // close the read-descriptor
        close(fd[0]);
    }
    return 0;
}
