#include "fillit.h"

void usage(void)
{
    write(1, "usage: fillit source_file\n", 26);  
}

int     isFileValid(char *argv)
{
    int     fd;

    fd = open(argv, O_RDONLY);
    if (checkTetriminoAmount(fd) == 0)
        return (0); //File is invalid
    fd = open(argv, O_RDONLY);
    if (checkBlockFormat(fd) == 0)
        return (0);
    
    return (1); //If file passes all checks will return 1, is valid.
}






int     checkTetriminoAmount(int fd)
{
    int     ret;
    char    buf[547];

    ret = read(fd, buf, 547);

    if ((ret < 21) || (ret > 546))//Checks if the file has at least 1 full 
                                   //tetrimino or more than 26.
       {
           printf("This is not a valid tetrimino\n");
           return (0);
       }
    close(fd);
    return (1);
}













int checkBlockFormat(int fd)
{
    int     ret, dots, amp, i;
    char    buf[21];


    dots = amp = 0; 
    while ((ret = read(fd, buf, 21)) != 0)
    {
        i = 0;
        if (buf[4] != '\n' || buf[9] !='\n' || buf[14] != '\n'
          || buf[19] != '\n' || buf[20] != '\n')
        {
            printf("The lines are not breaking where's supposed to\n");
            return (0);
        }
        while (i < 19)
        {
            if (i == 4 || i == 9 || i == 14)
                ;
            else if (buf[i] == '.')
                dots++;
            else if (buf[i] == '#')
                amp++;
            i++;
        }
        if (dots != 12 || amp != 4)
        {
            printf("The amount of dots or amp is not correct\n");
            return (0);
        }
        transform2dimensions(buf);
    }
    close(fd);
    return (1);
}









int transform2dimensions(char *block)
{
    int     i, j, ret;
    char    *buf[4];


    ret = i = j = 0;
    while (i < 5)
    {
        buf[i] = (char*)malloc((sizeof(char) * 5 ));
        i++;
    }
    i = 0;
     while (i < 4)
     {

        j = 0;
        while (j < 4)
        {
            if (ret == 4 || ret == 9 || ret == 14 ||
                    ret == 19 || ret == 20)
            {
                ret++;
                continue;
            }
            buf[i][j] = block[ret];
            j++;
            ret++;
        } 
        buf[0][4] = buf[1][4] = buf[2][4] = buf[3][4] = '\0';
        i++;
    }
    if (checkTheShape(buf) == 1)
       return (1);
    else
        return (0);
}











int     checkTheShape(char **arryPtr)
{
    int     coordinates[4][2];
    int     x,y,i,j; 

    x = y = i = j = 0;
    while (i < 4)
    { 
        j = 0;
        while (j < 4)
        {
            if (arryPtr[i][j] == '#')
            {
                if (arryPtr[i-1][j] == '#' || arryPtr[i+1][j] == '#' ||
                    arryPtr[i][j-1] == '#' || arryPtr[i][j+1] == '#')
                    printf("Block at coordinates [%d,%d] is valid\n", i,j);
                else
                {
                    printf("error due to bad shape\n");
                    return (0);
                }
            }
            j++;
        } 
    i++;
    }

    printf("The first row: %s\n", arryPtr[0]);
    printf("The first row: %s\n", arryPtr[1]);
    printf("The first row: %s\n", arryPtr[2]);
    printf("The first row: %s\n", arryPtr[3]);
    return (1);
}

