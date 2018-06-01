#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
	int shmid;
	key_t key;
	key = 2018;


	char *message;
	
	if ((shmid = shmget(key, 200 , IPC_CREAT | 0666)) < 0) {
		printf("shmget error");
		exit(1);
	}
	if ((message = shmat(shmid, NULL, 0)) == (char *) -1) {
		printf("shmat error");
		exit(1);
	}

	int shmid2;
	key_t key2;
	key2 = 2019;

	int *change;

	if ((shmid2 = shmget(key2, sizeof(int) , IPC_CREAT | 0666)) < 0) {
		printf("shmget error");
		exit(1);
	}
	if ((change = shmat(shmid2, NULL, 0)) == (int *) -1) {
		printf("shmat error");
		exit(1);
	}

	while(1){
		if (*change == 3){
			printf("me: ");
			scanf("%s",message);
			*change = 2;
		}
		else if(*change == 1){
			printf("server: %s \n",message);
			*change = 3;
		}
	}

}
