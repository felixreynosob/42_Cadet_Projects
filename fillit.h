#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void usage(void);
int isFileValid(char *argv);
int checkTetriminoAmount(int fd);
int checkBlockFormat(int fd);
int transform2dimensions(char *block);
int checkTheShape(char **arryPtr);

