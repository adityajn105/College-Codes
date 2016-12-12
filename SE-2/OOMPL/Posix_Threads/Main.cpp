#include <iostream>
#include <pthread.h>
#include <stdlib.h>

using namespace std;

void* add_task(void *arg) {

 
    int a = (int) (long) arg;
    
    
    int n1, n2;
    cout << "Enter numbers to add: ";
   cin >> n1 >> n2; 
    cout << n1 << " + " << n2 << " = "   << n1 + n2 << endl;
    
//    cout << "Work from Thread: " << a << endl;
    
//    sleep(2);
    
//    cout << "Thread complete: " << a << endl;   
    
}

void* sub_task(void *arg) {

    int n = (int) (long) arg;
    
    
    int n1, n2;
    cout << "Enter numbers to subtract: ";
    cin >> n1 >> n2; 
    cout << n1 << " - " << n2 << " = "   << n1 - n2 << endl; 
}

int main (int argc, char const* argv[], char * envp[])
{
    
    pthread_t add_threads[10];
    pthread_t sub_threads[10];
    
    if(argc != 2) {
        cout << "Illegal arguments";
        return -1;
    }
    
    int n = atoi(argv[1]);
    
    if(n > 10) n = 10;
    
    for(int i = 0; i < n; i++) {
    
        pthread_create(&add_threads[i], NULL, add_task, (void*) &i);
        
        //sleep(5);
        
        pthread_create(&sub_threads[i], NULL, sub_task, (void*) &i);
        
    }
    
    for(int i = 0; i < n; i++) {
        pthread_join(add_threads[i], NULL);
        pthread_join(sub_threads[i], NULL);
    }
    
    return 0;
}
