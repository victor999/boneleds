#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

int execShellCommand(const char* shellCommandP_A);

int main(int argc, char **argv)
{
	char buff[512] = "";
	int i = 0;
	int increment = 10000;
	while(1)
	{
		sprintf(buff, "echo %d > /sys/devices/ocp.3/$(ls /sys/devices/ocp.3 | grep P8_19)/duty", i);
		execShellCommand(buff);
		usleep(10000);
		i += increment;
		if(increment >= 500000)
		{
			increment = increment * -1;
		}
		if(increment <= 0)
		{
			increment = increment;
		}
	}
	return 0;
}

int execShellCommand(const char* shellCommandP_A)
{
	char command_buff[512] = "";
	FILE *in;

	if(!(in = popen(shellCommandP_A, "r")))
	{
		printf("can't open pipe\n");
		return 0;
	}

	while(fgets(command_buff, sizeof(command_buff), in) != NULL);

	pclose(in);

	return 1;
}
