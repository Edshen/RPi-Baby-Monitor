#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <wiringPiSPI.h>

int main()
{
	int SPI_channel = 0;
	int SPI_speed = 32000000;
	
	// Page 21 of the MCP3008 describes a 3 byte simultaneous RW
	int numSPIbytes = 3;
	int dataLength = numSPIbytes*8;
	unsigned char SPI_data[dataLength];
	
	int i;
	
	int SPIsetup = wiringPiSPISetup(SPI_channel, SPI_speed);
	if (SPIsetup != 0)
	{
		printf("SPI setup failed: %s\n", strerror(SPIsetup));
		return -1;
	}
	
	int SPIrw = wiringPiSPIDataRW(SPI_channel, SPI_data, dataLength);
	
	printf("Data read: ");
	for (i = 0; i < dataLength; i++)
	{
		printf("%d", SPI_data[i]);
	}

}