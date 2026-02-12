#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>


int main(int argc, char *argv[]){
  if (argc > 2){
    fprintf(stderr, "Useage %s <path/to/a.out> [args....]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  pid_t pid = fork();

  if (pid < 0){
    perror("fork failed");
    exit(EXIT_FAILURE);
  } else if (pid == 0){
    execvp(argv[1], &argv[1]);

    perror("execvp failed");
    exit(EXIT_FAILURE);
  }else{
    int status;
    struct rusage usage;

    if(wait4(pid, &status, 0, &usage) == -1){
      perror("wait4 failed");
      exit(EXIT_FAILURE);
    }

    printf("\n -- Child Process Performance Stats -- \n");
    printf("Real time: %ld.%06ld seconds \n",
           (long)usage.ru_utime.tv_sec + (long)usage.ru_stime.tv_sec,
           (long)usage.ru_utime.tv_usec + (long)usage.ru_stime.tv_usec
          );
    printf("User CPU time: %ld.%06ld seconds \n",
           (long)usage.ru_stime.tv_sec, (long)usage.ru_stime.tv_usec);
    printf("System CPU time: %ld.%06ld seconds \n", 
           (long)usage.ru_stime.tv_sec, (long)usage.ru_stime.tv_usec);
    printf("Major page faults: %ld \n", usage.ru_majflt);
    printf("Minor page faults:  %ld \n", usage.ru_minflt);
    printf("Voluntary context switches:  %ld \n", usage.ru_nvcsw);
    printf("Involuntary context switches:  %ld \n", usage.ru_nivcsw);
  }
  return 0;
}
