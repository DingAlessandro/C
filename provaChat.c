#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
int main()
{
    int fd, n;
    char buffer[2048];
    if (mkfifo("fifo1", 0777) == -1)
    {
        if (errno != EEXIST)
        {
            printf("Errore\n");
            return 1;
        }
    }
    if (mkfifo("fifo2", 0777) == -1)
    {
        if (errno != EEXIST)
        {
            printf("Errore\n");
            return 1;
        }
    }
    printf("inizia a chat\n");
    int p = fork();
    do
    {
        if (p == 0)
        {
            fd = open("fifo1", O_WRONLY);
            scanf("%s", buffer);
            write(fd, buffer, sizeof(buffer));
        }
        else
        {
            fd = open("fifo2", O_RDONLY);
            read(fd, buffer, sizeof(buffer));
            printf("%s\n", buffer);
        }
    } while (strcmp(buffer, "HALT") != 1);
    close(fd);
    return 0;
}
