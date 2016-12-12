#include <iostream>
#include <spawn.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, char *argv[], char*envp[]) {

    pid_t pid1, pid2;
    
    int ret1, ret2;
    
    int val;
    
    ret1 = posix_spawn(&pid1, "/bin/ls", NULL, NULL, argv, envp);
    
    if(ret1 == 0) {
        cout << "Process ls created with pid: " << pid1 << endl;
    } else {
        cout << "Process creation failed." << endl;
    }
    
    ret2 = posix_spawn(&pid2, "/bin/ps", NULL, NULL, argv, envp);
    
    if(ret1 == 0) {
        cout << "Process ps created with pid: " << pid2 << endl;
    } else {
        cout << "Process creation failed." << endl;
    }
    
    wait(&val);
    wait(&val);
    
    return 0;   
}
