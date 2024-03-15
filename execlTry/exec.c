#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
int main(int argc, char *argv[]) 
{
    int p;
    printf("%d\n", getpid());
    execl("eseguibileChiamato", "eseguibileChiamato", "ciao", "buongiorno", NULL);
    return 0;
}