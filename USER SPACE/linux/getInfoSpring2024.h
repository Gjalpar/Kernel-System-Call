#include <linux/types.h>
#include <linux/unistd.h>
#include <errno.h>

extern int errno;

struct structSpring2024 {
 int flag; /* flag for option */
 pid_t pid; /* process id */
 pid_t pid_parent; /* process id of parent process */
 long process_counter; /* counter value of the process */
 long nice; /* nice value of the process */
 long nice_parent; /* nice value of parent process's owner */
 long uid; /* user id of process owner */
 long weight; /* weight is 0 if counter is 0, otherwise; value calculated with counter/2+20-nice */
};

_syscall1(int, getInfoSpring2024, struct structSpring2024*, data);