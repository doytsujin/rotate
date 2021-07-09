#include "include/args.h"

int main(int argc, char *argv[])
{
    // deal with the arguments
    if (argc == 1)
    {
        printf("ROTATE Compiler\a\n");
        printf("Usage: rotate [filename]\n");
        printf("currently only supports one file\n");
        printf("Version: %d.%d.%d\n", VERSION, SVERSION, SSVERSION);
    }
    else
    {
        return deal_the_args(argc, argv);
    }
    return EXIT_SUCCESS;
}
