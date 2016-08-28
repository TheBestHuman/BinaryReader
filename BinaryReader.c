#include <stdio.h>


char *ByteToBinary(unsigned char inputByte)
{
	int i = inputByte;
	
	int bitplace = 128;

	char stringplace = "0";
	
	while(bitplace >= 1)
	{
		if( i > bitplace )
		{
			i = i - bitplace;
			stringplace = "1";
		}
		else
			stringPlace = "0";
		bitplace = bitplace/2;
	}
}

int main(void)
{
  printf("Hello, world!\n");
  return 0;
}
