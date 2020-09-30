#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */

int main(void)
{
  int fd,n; /* File descriptor for the port */
 char user_input;

  fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NDELAY);
  if (fd == -1)
  {
   /*
    * Could not open the port.
    */
    perror("open_port: Unable to open /dev/ttyUSB0 - ");
  }
  else
    fcntl(fd, F_SETFL, 0);
	
	printf("###########UART HOST AND DEVICE COMMUNICATION###############\n");

	while (1)
	{
		printf("Enter any character to send\n Enter '$' to exit UART communication\n");
		scanf("%c",&user_input);
		if (user_input == '$')
		{
			write(fd, &user_input, 1);
			break;
		}
		n=write(fd, &user_input, 1);
		if (n < 0)
  		fputs("write operation failed!\n", stderr);
	}

 /* n = write(fd, "Hemanth\r", 4);
if (n < 0)
  fputs("write() of 4 bytes failed!\n", stderr);
*/
close(fd);
}

