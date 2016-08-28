#include <stdio.h>


//char *ByteToBinary(unsigned char inputByte)
void ByteToBinary(unsigned char inputByte)
{
	int i = inputByte;
	
	int bitplace = 128;

	char stringplace = '0';
	
	while(bitplace >= 1)
	{
		if( i > bitplace )
		{
			i = i - bitplace;
			stringplace = '1';
		}
		else
			stringplace = '0';
		bitplace = bitplace/2;
		printf("%c",stringplace);
	}
	
}

int main(void)
{
	unsigned char buff[255];
	FILE *filestream;
	int bytesread = 0;

	filestream = fopen("firstfile.bin", "rb");
	while(!feof(filestream))
	{
		bytesread = fread(buff, 1, sizeof(buff), filestream);
		printf("(%d)", bytesread);
		for(int i = 0; i < bytesread; i++)
		{
			printf("%c", buff[i]);
			//printf("%c: ", buff[i]);
			//ByteToBinary(buff[i]);
			printf(" ");
		}
	}
  	return 0;
}
