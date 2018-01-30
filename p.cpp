//Threads.cpp
#include <iostream>
#include <unistd.h>
#include <pthread.h>
using namespace std;

void *thread(void *ptr)
{
    cout << "This is a pthread." << endl;
    sleep(1);
    return 0;
}

int main() {
    pthread_t id;
	while(1)
	{
    int ret = pthread_create(&id, NULL, thread, NULL);
 //   pthread_join(id, NULL);
        cout <<  "This is the main process." << endl;
		sleep(1);
    }
    return 0;
}
