#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int licznik = 0;
pthread_t tid[2];

void* increment(void *arg){
	pthread_t id = pthread_self();
	licznik++;
	sleep(1);
}

void* pri(void *arg){
	pthread_t id = pthread_self();
	printf("%d\n",licznik);
}

int main(int argc, char * argv[]){
	int err;
	err = pthread_create(&(tid[0]), NULL, &increment, NULL);
	pthread_join(tid[0], NULL); 
	
	while(1){
		
	err = pthread_create(&(tid[1]), NULL, &pri, NULL);
	
	err = pthread_create(&(tid[0]), NULL, &increment, NULL);
	int i;
	for(i = 0; i<2; i++){
		pthread_join(tid[i], NULL); 
	}
	
	}
	return 0;
}