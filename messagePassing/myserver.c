# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/msg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

#define  SIZE 40
# define SERVER_MTYPE 27L
# define CLIENT_MTYPE 42L

struct message {
long mtype ;
char mtext [40];
};

void main(){
	

	struct message sbuf,rbuf;
	key_t key = 1234;
	int qid;
	qid = msgget(key, 0666 | IPC_CREAT);
	sbuf.mtype = SERVER_MTYPE ;

        strcpy ( sbuf.mtext ,"Hello loyal client!");
	msgsnd(qid, &sbuf, strlen(sbuf.mtext)+1, 0);
	printf("[server] sent message: %s\n",sbuf.mtext);
	//sleep(10);
	
	msgrcv (qid , &rbuf , SIZE , CLIENT_MTYPE , 0);
	printf("[server] recieved message: %s\n",rbuf.mtext);
	msgctl (qid , IPC_RMID , ( struct msqid_ds *) 0);
}



















