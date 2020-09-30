#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */

int main(void)
{
  int fd,n,i; /* File descriptor for the port */
  char c;
  fd = open("/dev/ttymxc0", O_RDWR | O_NOCTTY | O_NDELAY);
  if (fd == -1)
  {
   /*
    * Could not open the port.
    */

    perror("open_port: Unable to open /dev/ttymxc0 - ");
  }
  else
    fcntl(fd, F_SETFL, 0);

  //n = write(fd, "ATZ\r", 4);
  printf("Waiting to receive data:\n");
  while(1)
  {
    n=read(fd, &c,1); 
    fscanf(fd,"%c",c);
    if (n < 0)
      fputs("read() failed!\n", stderr);
    if ( c == 'q')
    {
      printf("Entered here\n");
      close(fd);
      break;
    }
    printf("%c ",c);
  }
  return 0;
}

