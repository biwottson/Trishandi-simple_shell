  perror("Err input");
              break;
	              }
        
        size_t input_length = strlen(input_buffer);
	        if (input_length > 0 && input_buffer[input_length - 1] == '\n') {
			            input_buffer[input_length - 1] = '\0';
				            }

       #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void check_command(char *command) {
    if (access(command, F_OK) == 0)
        printf("%s: FILE FOUND\n", command);
    else
        printf("%s: FILE MISSING\n", command);
}

int main(void) {
    char *input_buffer = NULL;
    size_t buffer_size = 0;
    char *token;

    while (1) {
        printf("Usage: _which filename ...\nCISFUN$ ");
        
        if (getline(&input_buffer, &buffer_size, stdin) == -1) {
           token = strtok(input_buffer, " \t\n");
        if (token != NULL && strcmp(token, "_which") == 0) {
            token = strtok(NULL, " \t\n");
            while (token) {
                check_command(token);
                token = strtok(NULL, " \t\n");
            }
        } else {
            printf("CMD MISSING\n");
        }
    }

    free(input_buffer);

    return 0;
}
