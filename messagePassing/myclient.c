# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/msg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define SIZE 40
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

	msgrcv (qid , &rbuf ,SIZE , SERVER_MTYPE , 0);
	printf("[client] recieved message: %s\n",rbuf.mtext);

	sbuf.mtype = CLIENT_MTYPE ;
        strcpy ( sbuf.mtext ,"Hi there generous server!");
	msgsnd(qid, &sbuf, strlen(sbuf.mtext)+1, 0);
	printf("[client] sent message: %s\n",sbuf.mtext);
}














