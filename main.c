#include "fillit.h"

int     main(int argc, char **argv)
{
    int     fd;

    if (argc == 2)
    {
        if (isFileValid(argv[1]))
            printf("THE FILE PROVIDED IS VALID\n");
        else
            printf("error\n");
    }
    else
    {   
        usage();
        exit(0);
    }
    return (0);
}
