#include <stdio.h>
#include <unistd.h>

/**
 * main - it's PID
 *
 * Output: is(Always) 0.
 */
int main(void)
{
    pid_t parentid_pid;

    parentid_pid = getpid();
    printf("%u\n", parentid_pid);
    return (0);
}
