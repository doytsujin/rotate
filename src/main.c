#include "include/args.h"

int main(int argc, char *argv[])
{
    int exit_status = EXIT_SUCCESS;
    // deal with the arguments
    if (argc == 1)
    {
        printf("ROTATE Compiler\n");
        printf("Usage: rotate {filename}\n");
        printf("Version: %d.%d.%d\n", VERSION, SVERSION, SSVERSION);
    }
    else
    {
        exit_status = deal_the_args(argc, argv);
    }
    return exit_status;
}
