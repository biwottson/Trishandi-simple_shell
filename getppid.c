#include <stdio.h>
#include <unistd.h>

/**
 * Main - Output (PID)
 *
 * Return Always 0.
 */
int main(void)
{
    pid_t parent_pid = getppid();

    printf("Parent PID: %u\n", parent_pid);
    return (0);
}
