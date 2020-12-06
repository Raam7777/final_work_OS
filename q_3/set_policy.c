#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <linux/sched.h>
#include <pthread.h>
#include <stdint.h>
#include <unistd.h>


struct sched_attr {
    uint32_t size;
    uint32_t sched_policy;
    uint64_t sched_flags;
    int32_t sched_nice;
    uint32_t sched_priority;
    uint64_t sched_runtime;
    uint64_t sched_deadline;
    uint64_t sched_period;
};

int sched_setattr(pid_t pid,
              const struct sched_attr *attr,
              unsigned int flags)
{
    return syscall(__NR_sched_setattr, pid, attr, flags);
}



int main(int argc, char** argv) {

    if(argc<3){
        printf("usage: client <policy> <priority>");
       printf("where policy is an integer, one of: ");
       printf("0=SCHED_OTHER, 1=SCHED_FIFO, 2=SCHED_RR, 5=SCHED_IDLE, 6=SCHED_DEADLINE");
        printf("where priority is an integer, in [0..10]");

        printf("Exiting...");
        exit(0);
    }

    

    int policy = atoi(argv[1]);
    int priority = atoi(argv[2]);
    struct sched_param sched_param = {
        .sched_priority = priority
    };

    if (policy == 6){
        struct sched_attr attr = {
        .size = sizeof (attr),
        .sched_policy = SCHED_DEADLINE,
        .sched_runtime = 10 * 1000 * 1000,
        .sched_period = 2 * 1000 * 1000 * 1000,
        .sched_deadline = 11 * 1000 * 1000,
        .sched_priority = atoi(argv[2])
    };

    int status = sched_setattr(0 , &attr ,0);
    if (status == -1) {
        perror("sched_setscheduler");
        exit(1);
    }
    while(1);
    exit(0);
    }

    int status = sched_setscheduler(0, policy, &sched_param );
    if (status == -1) {
        perror("sched_setscheduler");
        exit(0);
    }

    while (1){}
    exit(0);
}


//https://man7.org/linux/man-pages/man2/sched_setattr.2.html
//https://www.i-programmer.info/programming/cc/13002-applying-c-deadline-scheduling.html?start=1

