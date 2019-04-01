#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>


int    numberOfTetriminos(char **file);



int     main(int argc, char **argv)
{
    if (argc == 2)
    {
        
    }    
    else if (argc != 2)
        write(1, "error\n", 6);
    return (0);
}
