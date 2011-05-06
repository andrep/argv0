/* vim:et:ts=8:sts=4:sw=4:ft=c:sm:ai:
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(const int argc, char* const argv[])
{
    if(argc < 3)
    {
        printf("usage: %s ARGV0 REALNAME ZERO ARGS...\n\n", argv[0]);
        printf("executes REALNAME with an argv[0] of ZERO, passing ARGS as the program's remaining arguments.\n");

        return 0;
    }

    /* -1 since we don't need argv[0] for the current command; +1 for the
     * final NULL. */
    char** const execArgv = malloc(sizeof(char*) * (argc-1+1));
    
    unsigned i;
    for(i = 0; i < argc; i++)
    {
        execArgv[i] = argv[i+2];
    }

    execvp(argv[1], execArgv);

    return 0;
}

