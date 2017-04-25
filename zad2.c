#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int licznik = 0;
pthread_t tid[10];

pthread_mutex_t lock;

void* thre(void *arg){
	int j = 0;
	pthread_t id = pthread_self();
	srand(time(NULL));
	int r = rand() % 10001;
	int i;
	for(i = 0; i<r; i++){
			j++;
			printf("watek %d iteracja %d\n", (int)id, j);
	}
	
	pthread_mutex_lock(&lock);
	licznik+= j;
	pthread_mutex_unlock(&lock);
}

int main(int argc, char * argv[]){
	int err;
	int i;
	
	if (pthread_mutex_init(&lock, NULL) != 0){
	        printf("\n mutex init failed\n");
	        return 1;
	    }
	
	for(i = 0; i<10; i++){
		err = pthread_create(&(tid[i]), NULL, &thre, NULL);
	}
	
	
	for(i = 0; i<10; i++){
		pthread_join(tid[i], NULL); 
	}
	
	pthread_mutex_destroy(&lock);
	
	printf("iteracja %d\n", licznik);
	
	return 0;
}

