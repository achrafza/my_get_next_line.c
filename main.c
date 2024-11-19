#include "get_next_line.h"
#include <libc.h>
int main(){
    int fd = open("test.txt",O_RDWR);
    printf("%s\n",get_next_line(fd));
    printf("%s\n",get_next_line(fd));
    printf("%s\n",get_next_line(fd));

}