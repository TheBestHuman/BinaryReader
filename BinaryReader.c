#include <stdio.h>
#include <string.h>

//char *ByteToBinary(unsigned char inputByte)
void ByteToBinary(unsigned char inputByte)
{
	//printf("%c:", inputByte);
	int i = inputByte;
	
	int bitplace = 128;

	char stringplace = '0';
	
	while(bitplace >= 1)
	{
		//printf("%d>%d?", i, bitplace); 
		if( i >= bitplace )
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

int main(int argc, char **argv)
{

	char *filename;
	//printf("%d:  ", argc);
	if(argc > 1)
		filename = argv[1];
	else
		filename = "firstfile.bin";

	//printf("%s", filename);

	unsigned char buff[255];
	FILE *filestream;
	int bytesread = 0;

	filestream = fopen(filename, "rb");
	while(!feof(filestream))
	{
		bytesread = fread(buff, 1, sizeof(buff), filestream);
		//printf("(%d)", bytesread);
		for(int i = 0; i < bytesread; i++)
		{
			//printf("%c: ", buff[i]);
			ByteToBinary(buff[i]);
			printf(" ");
		}
	}
	printf("\n");
  	return 0;
}
